/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:09:48 by majjig            #+#    #+#             */
/*   Updated: 2021/12/07 03:13:25 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
static int	items_checker(char *line)
{
	while (*line)
	{
		if (*line != PLAYER && *line != WALL && *line!= COLL &&
			*line != EMPTY && *line != EXIT)
			return (0);
		line++;
	}
	return (1);
}

static int	is_closed(char *line, int len)
{
	if (len == 0 || !line)
		return (0);
	if (line[0] == WALL && line[len - 2] == WALL)
		return(1);
	return(0);
}

static int	is_all_wall(char *line)
{
	while (*line)
	{
		if (*line != WALL)
			return (0);
		line++;
	}
	return (1);
}
*/

int	map_checker(char *file, char ***map)
{
	int		fd;
	char	*big;
	int		nb;
	char	*tmp;

	fd = open(file, O_RDONLY);
	big = (char *) malloc(BUFFER_LEN + 1);
	nb = read(fd, big, BUFFER_LEN);
	if (nb == BUFFER_LEN)
	{
		free(big);
		return (-1);
	}
	else if (nb < BUFFER_LEN)
	{
		big[nb] = 0;
		tmp = ft_strdup(big);
		free(big);
		big = tmp;
	}
	*map = ft_split(big, '\n');
	free(big);
	return (1);
}
