/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_next_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:19:50 by majjig            #+#    #+#             */
/*   Updated: 2021/12/07 03:20:55 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *mlx, t_pos *pos)
{
	int	i;

	i = ELEMENT_LEN;
	while (i--)
	{
		pos->y -= 1;
		between_move(mlx);
	}
}

void	move_down(t_mlx *mlx, t_pos *pos)
{
	int	i;

	i = ELEMENT_LEN;
	while (i--)
	{
		pos->y += 1;
		between_move(mlx);
	}
}

void	move_right(t_mlx *mlx, t_pos *pos)
{
	int	i;

	i = ELEMENT_LEN;
	while (i--)
	{
		pos->x += 1;
		between_move(mlx);
	}
}

void	move_left(t_mlx *mlx, t_pos *pos)
{
	int	i;

	i = ELEMENT_LEN;
	while (i--)
	{
		pos->x -= 1;
		between_move(mlx);
	}
}

void	get_player_next_pos(int key, t_mlx *mlx, t_pos *pos)
{
	if (key == MOVE_UP && is_move_up(mlx))
		move_up(mlx, pos);
	if (key == MOVE_DOWN && is_move_down(mlx))
		move_down(mlx, pos);
	if (key == MOVE_RIGHT && is_move_right(mlx))
		move_right(mlx, pos);
	if (key == MOVE_LEFT && is_move_left(mlx))
		move_left(mlx, pos);
}