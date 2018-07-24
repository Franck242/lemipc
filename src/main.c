/*
** EPITECH PROJECT, 2018
** main
** File description:
** principal file
*/

#include "lemipc.h"

int	main(int ac, char **argv)
{
	t_ipc	*res;
	int	nb;

	check_param(ac, argv);
	srand(time(NULL));
	nb = atoi(argv[2]);
	res = init_infos(argv[1], nb);
	printf("%s\n", res->map);
      	while (1) {
		inc_dec_semaphore(res);
		usleep(100000);
		system("clear");
		printf("[Board Game]\n\n");
		printf("Team number %i added on the map\n", nb);
		printf("%s\n", res->map);
		res = ia_simulation(res, nb);
	}
	shmctl(res->id_shm, IPC_RMID, NULL);
	return (SUCCESS_EXIT);
}
