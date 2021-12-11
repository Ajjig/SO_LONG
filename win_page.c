/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_page.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:54:00 by majjig            #+#    #+#             */
/*   Updated: 2021/12/12 00:54:01 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_page(t_mlx *mlx)
{
	char	*img;
	int		weight;
	int		height;

	img = mlx_xpm_file_to_image(mlx->mlx, "win.xpm", &weight, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, 0, 0);
	mlx_destroy_image(mlx->mlx, img);
	return (0);
}
