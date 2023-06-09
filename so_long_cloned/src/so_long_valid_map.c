/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:39:21 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/02 19:54:53 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	all_one(t_so_long *c)
{
	int	i;

	i = -1;
	while (++i < c->w - 1)
	{
		if (c->map[0][i] != '1' || (c->map[c->h - 1][i] != '1'))
			return (1);
	}
	printf("sale\n");
	i = -1;
	while (++i < c->h - 1)
	{
		printf("i:%d linea: %s\n", i, c->map[i]);
		if (c->map[i][0] != '1' || (c->map[i][c->w - 1] != '1'))
			return (1);
	}
	return (0);
}

void	flood_fill(char **map, int i, int j)
{
	map[i][j] = 'M';
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'E')
		flood_fill(map, i + 1, j);
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E')
		flood_fill(map, i - 1, j);
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E')
		flood_fill(map, i, j + 1);
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E')
		flood_fill(map, i, j - 1);
}

int	look(t_so_long *c, char s)
{
	int	file;
	int	col;
	int	count;

	file = 1;
	col = 1;
	count = 0;
	while (file < c->h)
	{
		col = 1;
		while (col < c->w)
		{
			if (c->map[file][col] == s)
				count++;
			col++;
		}
		file++;
	}
	return (count);
}

int	valid_path(char **c, int size_file, int size_col)
{
	int	file;
	int	col;

	file = 1;
	col = 1;
	while (file < size_file - 1)
	{
		col = 0;
		while (col < size_col - 1)
		{
			if (c[file][col] != 'M' && c[file][col] != '1')
				return (1);
		col++;
		}
		file++;
	}
	return (0);
}

int	map_valid(t_so_long *c)
{
	char	**cpy;

	if ((c->w == c->h) || c->w < 3 || c->h < 3)
		return (ft_control_error(MAPA_NO_VALID, c), 1);
	if (all_one(c) == 1)
		return (ft_control_error(MAPA_NO_VALID, c), 1);
	if (look(c, 'E') != 1 || look(c, 'P') != 1 || look(c, 'C') < 1)
		return (ft_control_error(MAPA_NO_VALID, c), 1);
	look_p(c);
	cpy = cpy_matrix(c);
	flood_fill(cpy, c->player[0], c->player[1]);
	if (valid_path(cpy, c->h, c->w) == 1)
	{
		free_cpy_matrix(cpy, c->h);
		return (ft_control_error(MAPA_NO_VALID, c), 1);
	}
	free_cpy_matrix(cpy, c->h);
	return (0);
}
