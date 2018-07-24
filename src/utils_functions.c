/*
** EPITECH PROJECT, 2018
** utils functions
** File description:
** source file
*/

#include "lemipc.h"

char	*get_map(char *map_base, int size_ligne)
{
	int	size = size_ligne * size_ligne;
	int	j = 1;
	int	i = 0;

	while (i < size) {
		if (j == 25) {
			map_base[i] = '\n';
			j = 0;
		}
		else
			map_base[i] = '.';
		i = i + 1;
		j = j + 1;
	}
	return (map_base);
}

t_ipc	*init_infos(char *path, int nb_team)
{
	t_ipc	*res;
	void	*map;
	int	pos;

	res = malloc(sizeof(t_ipc));
	res->key = ftok(path, 0);
	res->size_map = 25;
	res->id_shm = shmget(res->key, res->size_map, SHM_R | SHM_W);
	if (res->id_shm == -1) {
		res->id_shm = shmget(res->key, res->size_map, IPC_CREAT | SHM_R | SHM_W);
		map = shmat(res->id_shm, NULL, SHM_R | SHM_W);
		res->map = (char *)map;
		res->map = get_map(res->map, res->size_map);

	}
	else
		res->map = shmat(res->id_shm, NULL, SHM_R | SHM_W);
	pos = get_pos(res->map, (res->size_map*res->size_map));
	res->p_play = pos;
       	res->map = player_on_map(res, nb_team);
	return (res);
}
