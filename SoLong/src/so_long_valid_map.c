/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:39:21 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/11 19:37:50 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
Pendiente crear funcion para controlar todos los errores posibles
*/
static int	all_one(t_so_long *c)
{
	int	i;

	i = -1;

	while (++i < c->w)
	{
		if (c->map[0][i] != '1')
			return (-1);
		if (c->map[c->h - 1][i] != '1')
			return (-1);
	}
	i = -1;
	while (++i < c->h)
	{
		if (c->map[i][0] != '1')
			return (-1);
		if (c->map[i][c->w - 1] != '1')
			return (-1);
	}
	printf("\nMapa rodeado de muros\n");
	return (1);
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

int	valid_path(char **c, int size_file, int size_col)
{
	int	file;
	int	col;

	file = 1;
	col = 1;
	while (file < size_file -2)
	{
		col = 0;
		while (col < size_col - 2)
		{
			if (c[file][col] != 'M' && c[file][col] != '1')
			{
				printf("\nMapa sin salida\n");
				exit (1);
			}
		col++;
		}
		file++;
	}
	printf("\nMapa con salida posible\n");
	return (0);
}

int	map_valid(t_so_long *c)
{
	int		i;
	char	**cpy;

	cpy = cpy_matrix(c);
	i = 0;
	if ((c->w == c->h) || c->w < 3 || c->h < 3)
		return (write(1, "Map_Cuadrado\n", 13), -1);
	all_one(c);
	look_p(c);
	if (look(c, 'E') != 1 || look(c, 'P') != 1 || look(c, 'C') < 1)
	{	
		printf("Mapa No valido");
		exit(1);
	}
	flood_fill(cpy, c->player[0], c->player[1]);
	print_matrix(cpy, c->h, c->w);
	valid_path(cpy, c->h, c->w);
	// liberar memoria de cada fila 
	return (1);
}
