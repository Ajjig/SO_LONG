/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:02:30 by majjig            #+#    #+#             */
/*   Updated: 2021/12/09 04:48:00 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_mlx *mlx)
{
	int			x;
	int			y;
	int			posx;
	int			posy;

	y = 0;
	posy = 0;
	while (mlx->map[y])
	{
		x = 0;
		posx = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == COLL)
				ft_put_img(mlx, COLL, posx, posy);
			posx += ELEMENT_LEN;
			x++;
		}
		posy += ELEMENT_LEN;
		y++;
	}
}
