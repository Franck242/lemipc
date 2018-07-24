/*
** EPITECH PROJECT, 2018
** check param
** File description:
** source file
*/

#include "lemipc.h"

void	print_usage(void)
{
	printf("USAGE\n\t./lemipc PATH TEAM_NUMBER\n\n");
	printf("DESCRIPTION\n\tPATH\t    path you'll give to ftok\n");
	printf("\tTEAM_NUMBER team number of the current champion (greater than 0)\n");
	exit(SUCCESS_EXIT);
}

bool	is_num(char *str)
{
	int	index = 0;

	while (str[index] != '\0') {
		if (str[index] < '0' || str[index] > '9')
			return (false);
		index = index + 1;
	}
	return (true);
}

bool	path_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY, 0);
	if (fd < 0 && strcmp(path, "pwd") != 0) {
		BAD_PATH;
		return (false);
	}
	return (true);
}

void	check_arg_values(char **av)
{
	if (is_num(av[2]) == false || atoi(av[2]) == 0) {
		BAD_TYPE;
		exit(EXIT_ERROR);
	}
	if (path_exist(av[1]) == false)
		exit(EXIT_ERROR);
}

void	check_param(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "--help") == 0)
		print_usage();
	if (ac < 3 || ac > 3) {
		BAD_NBR_ARG;
		exit(EXIT_ERROR);
	}
	if (ac == 3)
		check_arg_values(av);
}
