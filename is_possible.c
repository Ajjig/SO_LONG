/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:19:14 by majjig            #+#    #+#             */
/*   Updated: 2021/12/10 02:08:16 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_up(t_mlx *mlx)
{
	t_pos	player;

	player = find_player(mlx->map);
	if (mlx->map[player.y - 1][player.x] != WALL)
	{
		if (mlx->map[player.y - 1][player.x] == EXIT && mlx->count == 0)
		{
			printf("\n\n\nYOU WIN\n\n\n\n");
			exit(0);
		}
		if (mlx->map[player.y - 1][player.x] != EXIT)
		{
			mlx->map[player.y - 1][player.x] = PLAYER;
			mlx->map[player.y][player.x] = EMPTY;
			return (1);
		}
	}
	return (0);
}

int	is_move_down(t_mlx *mlx)
{
	t_pos	player;

	player = find_player(mlx->map);
	if (mlx->map[player.y + 1][player.x] != WALL)
	{
		if (mlx->map[player.y + 1][player.x] == EXIT && mlx->count == 0)
		{
			printf("\n\n\nYOU WIN\n\n\n\n");
			exit(0);
		}
		if (mlx->map[player.y + 1][player.x] != EXIT)
		{
			mlx->map[player.y + 1][player.x] = PLAYER;
			mlx->map[player.y][player.x] = EMPTY;
			return (1);
		}

	}
	return (0);
}

int	is_move_right(t_mlx *mlx)
{
	t_pos	player;

	player = find_player(mlx->map);
	if (mlx->map[player.y][player.x + 1] != WALL)
	{
		if (mlx->map[player.y][player.x + 1] == EXIT && mlx->count == 0)
		{
			printf("\n\n\nYOU WIN\n\n\n\n");
			exit(0);
		}
		if (mlx->map[player.y][player.x + 1] != EXIT)
		{
			mlx->map[player.y][player.x + 1] = PLAYER;
			mlx->map[player.y][player.x] = EMPTY;
			return (1);
		}
	}
	return (0);
}

int	is_move_left(t_mlx *mlx)
{
	t_pos	player;

	player = find_player(mlx->map);
	if (mlx->map[player.y][player.x - 1] != WALL)
	{
		if (mlx->map[player.y][player.x - 1] == EXIT && mlx->count == 0)
		{
			printf("\n\n\nYOU WIN\n\n\n\n");
			exit(0);
		}
		if (mlx->map[player.y][player.x - 1] != EXIT)
		{
			mlx->map[player.y][player.x - 1] = PLAYER;
			mlx->map[player.y][player.x] = EMPTY;
			return (1);
		}
	}
	return (0);
}
