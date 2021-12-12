/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:54:08 by majjig            #+#    #+#             */
/*   Updated: 2021/12/12 00:54:09 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kill_game(t_mlx *mlx)
{
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->map);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}
