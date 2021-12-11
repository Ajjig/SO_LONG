/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:53:15 by majjig            #+#    #+#             */
/*   Updated: 2021/12/12 00:53:16 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_moves(t_mlx *mlx)
{
	char	*nb;

	mlx_string_put(mlx->mlx, mlx->win, 10, 5, 0xFFFF00, "KUNSAI USED: ");
	nb = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx, mlx->win, 140, 5, 0xFFFF00, nb);
	free(nb);
	nb = NULL;
}
