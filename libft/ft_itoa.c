/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:16:15 by majjig            #+#    #+#             */
/*   Updated: 2021/12/11 00:19:09 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_get_size(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

static void	ft_itoa_fill(char *dest, int nb, int len)
{
	int	end;

	end = 0;
	dest[len] = 0;
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
		end = 1;
	}
	while (len-- > end)
	{
		dest[len] = nb % 10 + 48;
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*buff;

	len = ft_get_size(n);
	buff = (char *) malloc(len + 1);
	if (buff == NULL)
		return (0);
	if (n == 0)
		return (ft_strdup("0"));
	else
		ft_itoa_fill(buff, n, len);
	return (buff);
}
