/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:09:48 by majjig            #+#    #+#             */
/*   Updated: 2021/12/12 00:52:58 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	items_checker(char **map)
{
	static int	player_count = 0;
	static int	exit_count = 0;
	static int	coll_count = 0;
	t_pos		pos;

	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == PLAYER)
				if (++player_count != 1)
					ft_exit(NO_PLAYER);
			if (map[pos.y][pos.x] == EXIT)
				exit_count++;
			else if (map[pos.y][pos.x] == COLL)
				coll_count++;
			else if (map[pos.y][pos.x] != EMPTY && map[pos.y][pos.x] != WALL)
				if (map[pos.y][pos.x] != PLAYER)
					ft_exit(UNKNOWN_ELEMENT);
		}
	}
	if (coll_count == 0 || exit_count == 0)
		ft_exit(NO_COLL_EXIT);
}

static void	is_closed(char *line, int len)
{
	if (line[0] == WALL && line[len - 1] == WALL)
		return ;
	ft_exit(NOT_CLOSED);
}

static void	is_all_wall(char *line)
{
	while (*line)
	{
		if (*line != WALL)
			ft_exit(NOT_CLOSED);
		line++;
	}
}

void	check(char **map)
{
	int	len;
	int	y;

	y = -1;
	len = ft_strlen(map[0]);
	while (map[++y])
		if (len != ft_strlen(map[y]))
			ft_exit(NO_RECTANGLE);
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
		ft_exit(NO_FILE);
	if (nb == BUFFER_LEN)
		return (free(big), 0);
	if (nb == 0 || nb == 1)
		ft_exit(EMPTY_MAP);
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
