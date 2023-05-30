/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:25 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/30 22:49:26 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	**cpy_matrix(t_so_long *c)
{
	int		fil;
	int		col;
	char	**cpy_matrix;

	cpy_matrix = (char **)ft_calloc(sizeof(char *), c->h + 1);
	if (cpy_matrix == NULL)
		return (ft_printf("Error\nReserva de memoria"), NULL);
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

void	free_cpy_matrix(char **c, int fil)
{
	int	i;

	i = 0;
	while (i < fil)
	{
		free(c[i]);
		i++;
	}
	free(c);
}

void	look_p(t_so_long *c)
{
	int	file;
	int	col;

	file = 0;
	col = 0;
	while (file < c->h)
	{
		col = 1;
		while (col < c->w)
		{
			if (c->map[file][col] == 'P')
			{
				c->player[0] = file;
				c->player[1] = col;
			}
			col++;
		}
		file++;
	}
}

void	c_found(t_so_long *so_long)
{
	mlx_delete_image(so_long->mlx, so_long->bone);
	so_long->count_c--;
	so_long->map[so_long->player[0]][so_long->player[1]] = '0';
	if (so_long->count_c > 0)
		paint_collec(so_long);
}
