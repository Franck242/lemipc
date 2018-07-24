/*
** EPITECH PROJECT, 2018
** intelligence artificial
** File description:
** source file
*/

#include "lemipc.h"

t_ipc	*movement(t_ipc *cur, int player)
{
	if (cur->way == LEFT) {
		cur->map = move_left(cur->map, player, cur->p_play);
		cur->p_play = cur->p_play - 1;
	}
	else if (cur->way == RIGHT) {
		cur->map = move_right(cur->map, player, cur->p_play);
		cur->p_play = cur->p_play + 1;
	}
	else if (cur->way == UP) {
		cur->map = move_up(cur->map, player, cur->p_play);
		cur->p_play = cur->p_play - 25;
	}
	else {
		cur->map = move_down(cur->map, player, cur->p_play);
		cur->p_play = cur->p_play + 25;
	}
	return (cur);
}

t_ipc	*check_death(t_ipc *cur)
{
	if (cur->map[cur->p_play - 1] == cur->map[cur->p_play + 1] && \
		cur->map[cur->p_play - 1] != '.') {
		printf("One player is dead\n");
		cur->map[cur->p_play] = '.';
	}
	if (cur->map[cur->p_play + 25] == cur->map[cur->p_play - 25] && \
		cur->map[cur->p_play + 25] != '.') {
		printf("One player is dead\n");
		cur->map[cur->p_play] = '.';
	}
	return (cur);
}

t_ipc	*set_way(t_ipc *cur)
{
	if (cur->map[cur->p_play + 1] != '.' && cur->map[cur->p_play + 25] == '.')
		cur-> way = DOWN;
	if (cur->map[cur->p_play + 1] != '.' && cur->p_play < 0)
		cur-> way = RIGHT;
	if (cur->map[cur->p_play + 25] != '.' && cur->p_play > 625)
		cur->way = UP;
	if ((cur->p_play - 25) < 0 || (cur->p_play - 1) < 0)
		cur->way = DOWN;
	if (cur->p_play - 25 < 0 && cur->map[cur->p_play + 1] == '.')
		cur->way = RIGHT;
	if ((cur->p_play - 1) < 0 && cur->map[cur->p_play + 25] == '.')
		cur->way = DOWN;
	if (cur->map[cur->p_play - 1] != '.' && cur->map[cur->p_play + 1] == '.')
		cur->way = RIGHT;
	if ((cur->p_play - 25) < 0 && cur->map[cur->p_play + 1] == '.')
		cur->way = RIGHT;
	if ((cur->p_play - 25) < 0 && cur->map[cur->p_play - 1] == '.')
		cur->way = LEFT;
	if (cur->p_play == 0 && cur->map[cur->p_play + 1] == '.')
                cur->way = RIGHT;
	return (cur);
}

t_ipc	*ia_simulation(t_ipc *cur, int player)
{
	cur->way = DOWN;
	cur->way = rand()%(3) + 1 - 1;
	cur = set_way(cur);
       	cur = movement(cur, player);
	cur = check_death(cur);
	return (cur);
}
