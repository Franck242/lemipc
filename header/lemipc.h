/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** header file
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <time.h>

# define SUCCESS_EXIT	(0)
# define EXIT_ERROR	(84)
# define BAD_NBR_ARG	write(2, "Error , too few or too many arguments\n", 38);
# define BAD_TYPE	write(2, "Error, arg n°3 must be an integer > 0\n", 39);
# define BAD_PATH	write(2, "Error, invalid Path\n", 21);
# define _ERROR_MALLOC_	write(2, "Error on allocated memory\n", 27);

typedef enum s_way
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_way;

typedef struct	s_ipc
{
	key_t	key;
	int	id_shm;
	int	id_sem;
	int	size_map;
	char	*map;
	int	p_play;
	t_way	way;
}		t_ipc;

typedef struct	s_linkedmsg
{
	int	type;
	char	*map[20*20];
}		t_linkedmsg;

void		check_param(int , char **);
t_ipc		*init_infos(char *, int);
char		*player_on_map(t_ipc*, int);
bool		is_num(char*);
char		*mov_player(char*, int, int);
char		*move_right(char*, int, int);
char		*move_down(char*, int, int);
char		*move_left(char*, int, int);
char		*move_up(char*, int, int);
int		get_pos(char *, int);
t_ipc		*choosed_way(t_ipc*);
void		inc_dec_semaphore(t_ipc*);
t_ipc		*ia_simulation(t_ipc*, int);

#endif /* LEMIPC_H */
