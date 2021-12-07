/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:18:56 by majjig            #+#    #+#             */
/*   Updated: 2021/12/07 03:18:57 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	get_window_size(char **map)
{
	t_pos	len;

	len.x = ft_strlen(map[0]);
	while (map[len.y] != NULL)
		len.y++;
	len.x *= 100;
	len.y *= 100;
	return (len);
}
