/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:05:13 by majjig            #+#    #+#             */
/*   Updated: 2021/12/07 03:01:10 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_alloc_fill(char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static int	ft_count_words(char *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str != c)
		{
			words++;
			while (*str && *str != c)
				str++;
			continue ;
		}
		str++;
	}
	return (words + 1);
}

static int	ft_check_is_alloc(char **str, int j)
{
	if (str[j] == NULL)
	{
		while (j)
			free(str[--j]);
		free(str);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		words;
	char	**str;

	if (s == NULL)
		return (NULL);
	words = ft_count_words((char *) s, c);
	str = (char **) malloc(words * sizeof(char *));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[j] = ft_alloc_fill((char *) s, c);
			if (!(ft_check_is_alloc(str, j++)))
				return (NULL);
			while (*(s + 1) && *(s + 1) != c)
				s++;
		}
		s++;
	}
	str[j] = NULL;
	return (str);
}
