/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:55:54 by majjig            #+#    #+#             */
/*   Updated: 2021/12/12 00:57:07 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *c1, char *c2)
{
	*c2 = ENEMY;
	*c1 = EMPTY;
}

static int	left_right(t_mlx *mlx, int x, int y, char *where)
{
	if (*where == 'R')
	{
		if (mlx->map[y + 1][x + 1] == PLAYER)
			mlx_loop_hook(mlx->mlx, &lose_page, mlx);
		else if (mlx->map[y + 1][x + 1] != EMPTY)
		{
			*where = 'L';
			return (0);
		}
		else
			return (ft_swap(&mlx->map[y][x], &mlx->map[y + 1][x + 1]), 0);
	}
	if (mlx->map[y - 1][x - 1] == PLAYER)
		mlx_loop_hook(mlx->mlx, &lose_page, mlx);
	else if (mlx->map[y - 1][x - 1] != EMPTY)
	{
		*where = 'R';
		return (0);
	}
	ft_swap(&mlx->map[y][x], &mlx->map[y - 1][x - 1]);
	return (0);
}

int	enemy_move(t_mlx *mlx)
{
	int			x;
	int			y;
	static char	where = 'R';

	y = -1;
	while (mlx->map[++y])
	{
		x = -1;
		while (mlx->map[y][++x])
		{
			if (mlx->map[y][x] == ENEMY)
			{
				left_right(mlx, x, y, &where);
				return (0);
			}
		}
	}
	return (0);
}

void	enemy_pos(t_mlx *mlx)
{
	static int	is = 1;
	int			x;
	int			y;

	y = 0;
	x = 0;
	if (is)
	{
		while (mlx->map[y])
		{
			x = 0;
			while (mlx->map[y][x])
			{
				if (mlx->map[y][x] == EMPTY)
				{
					mlx->map[y][x] = ENEMY;
					is = 0;
					return ;
				}
				x++;
			}
			y++;
		}
	}
	enemy_move(mlx);
}
