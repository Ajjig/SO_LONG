/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:02:30 by majjig            #+#    #+#             */
/*   Updated: 2021/12/11 15:34:01 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_mlx *mlx)
{
	int			x;
	int			y;
	int			posx;
	int			posy;

	mlx->count = 0;
	y = 0;
	posy = 0;
	while (mlx->map[y])
	{
		x = 0;
		posx = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] != EMPTY && mlx->map[y][x] != PLAYER)
				ft_put_img(mlx, mlx->map[y][x], posx, posy);
			if (mlx->map[y][x] == COLL)
				mlx->count++;
			posx += ELEMENT_LEN;
			x++;
		}
		posy += ELEMENT_LEN;
		y++;
	}
}
