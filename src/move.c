/*
** EPITECH PROJECT, 2018
** move
** File description:
** source file
*/

#include "lemipc.h"

char	*move_right(char *map, int player, int x)
{
	map[x] = '.';
	map[x + 1] = player + '0';
	return (map);
}

char	*move_left(char *map, int player, int x)
{
	map[x] = '.';
	map[x - 1] = player + '0';
	return (map);
}

char	*move_down(char *map, int player, int x)
{
	map[x] = '.';
	map[x + 25] = player + '0';
	return (map);
}

char	*move_up(char *map, int player, int x)
{
	map[x - 25] = player + '0';
	map[x] = '.';
	return (map);
}
