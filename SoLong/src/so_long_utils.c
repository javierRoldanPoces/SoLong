/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:25 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/12 10:03:09 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	i = 0;
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (i < n)
	{
		if (*s1cpy != *s2cpy)
			return (*s1cpy - *s2cpy);
		i++;
		s1cpy++;
		s2cpy++;
	}
	return (0);
}

void	ft_leaks(void)
{
	system("leaks so_long");
}

char	**cpy_matrix(t_so_long *c)
{
	int		fil;
	int		col;
	char	**cpy_matrix;

	cpy_matrix = (char **)ft_calloc(sizeof(char *), c->h + 1);
	if (cpy_matrix == NULL)
		return(write(1, "Memory error", 12), NULL);
	fil = 0;
	while (fil < c->h)
	{
		col = 0;
		cpy_matrix[fil] = (char *)ft_calloc(sizeof(char *), c->w);
		while (col < c->w)
		{
			cpy_matrix[fil][col] = c->map[fil][col];
			col++;
		}
		fil++;
	}
	return (cpy_matrix);
}
