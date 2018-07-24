/*
** EPITECH PROJECT, 2018
** create players
** File description:
** source file
*/

#include "lemipc.h"

int	get_pos(char *map, int size)
{
	int	res;

	res = rand()%(size) -1 + 1;
	while (map[res] != '.')
		res = rand()%(size) + 1 - 1;
	return (res);
}

char	*player_on_map(t_ipc *cur, int nb_team)
{
	cur->map[cur->p_play] = nb_team + '0';
	return (cur->map);
}

void	semaphore_instructions(int id)
{
	struct sembuf	pos;
	int		tmp;

	tmp = semctl(id, 0, GETVAL);
	printf("Using semaphore [%d]\n", id);
	pos.sem_num = 0;
	pos.sem_flg = 0;
	if (tmp != 0)
		pos.sem_op = -1;
	else
		pos.sem_op = 1;
	printf("Locked %i\n", tmp);
	semop(id, &pos, 1);
	printf("Unlocked %i\n", semctl(id, 0, GETVAL));
}

void	inc_dec_semaphore(t_ipc *cur)
{
	cur->id_sem = semget(cur->key, 1, SHM_R | SHM_W);
	if (cur->id_sem == -1) {
		cur->id_sem = semget(cur->key, 1, IPC_CREAT | SHM_R | SHM_W);
		printf("Semaphore [%d] created\n", cur->id_sem);
		semctl(cur->id_sem, 0, SETVAL, 1);
	}
	else
		semaphore_instructions(cur->id_sem);
}
