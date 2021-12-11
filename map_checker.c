/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:09:48 by majjig            #+#    #+#             */
/*   Updated: 2021/12/11 16:29:00 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	items_checker(char **map)
{
	static int	player_count = 0;
	static int	exit_count = 0;
	static int	coll_count = 0;
	int			y;
	int			x;
	char		unk;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == PLAYER)
				player_count++;
			else if (map[y][x] == EXIT)
				exit_count++;
			else if (map[y][x] == COLL)
				coll_count++;
			else if(map[y][x] != EMPTY && map[y][x] != WALL)
				unk =x;
		}
	}
	if (player_count != 1)
		write(2, &NO_PLAYER, 42);
	else if (coll_count == 0)
		write(2, NO_COLL, 48);
	else if (exit_count == 0)
		write(2, NO_EXIT, 41);
	else if (unk)
		write(2, UNKNOWN_ELEMENT, 27);
	else if (player_count != 1 || coll_count == 0 || exit_count == 0)
		exit(0);
}

static void	is_closed(char *line, int len)
{
	if (line[0] == WALL && line[len - 1] == WALL)
		return ;
	perror(NOT_CLOSED);
	exit(0);
}

static void	is_all_wall(char *line)
{
	while (*line)
	{
		if (*line != WALL)
			perror(NOT_CLOSED);
		line++;
	}
}

void check(char **map)
{
	int	len;
	int	y;

	y = -1;
	len = ft_strlen(map[0]);
	while(map[++y])
		if (len != ft_strlen(map[y]))
		{
			perror(NO_RECTANGLE);
			exit(1);
		}
	items_checker(map);
	y = 0;
	is_all_wall(map[y]);
	while (map[++y])
		is_closed(map[y], len);
	is_all_wall(map[--y]);

}

int	map_checker(char *file, char ***map)
{
	int		fd;
	char	*big;
	int		nb;
	char	*tmp;

	fd = open(file, O_RDONLY);
	big = (char *) malloc(BUFFER_LEN + 1);
	nb = read(fd, big, BUFFER_LEN);
	if (nb == -1)
	{
		perror(NO_FILE);
		exit(0);
	}
	if (nb == BUFFER_LEN)
		return (free(big), 0);
	if (nb == 0 || nb == 1)
	{
		perror(EMPTY_MAP);
		exit(0);
	}
	if (nb < BUFFER_LEN)
	{
		big[nb] = 0;
		tmp = ft_strdup(big);
		free(big);
		big = tmp;
	}
	*map = ft_split(big, '\n');
	check(*map);
	return (free(big), 1);
}
