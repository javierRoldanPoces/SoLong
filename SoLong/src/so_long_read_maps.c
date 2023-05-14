/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:58:08 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/14 17:51:53 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_maps(t_so_long *c, char *name_file)
{
	int		file;
	int		size;
	char	*line;

	file = open(name_file, O_RDONLY);
	if (file < 0)
		return (ft_printf("Error abriendo fichero", -1));
	c->w = 0;
	c->h = 0;
	size = (int)ft_strlen(name_file);
	if (ft_memcmp(&name_file[size - 4], ".ber", 4))
		return (ft_printf("Extension de archivo no válida"), -1);
	line = get_next_line(file);
	c->h++;
	c->w = (int)ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (c->w != (int)ft_strlen(line) - 1 && ft_strlen(line))
			return (free(line), -3);
		c->h++;
	}
	c->h--;
	free(line);
	close(file);
	read_maps_2(c, name_file);
	return (0);
}

int	read_maps_2(t_so_long *c, char *name_file)
{
	int		f;
	int		file;
	char	*line;

	f = 0;
	c->map = (char **)ft_calloc(sizeof(char *), c->h + 1);
	file = open(name_file, O_RDONLY);
	line = get_next_line(file);
	c->map[0] = line;
	while (c->map[f])
		c->map[++f] = get_next_line(file);
	close(file);
	return (0);
}

void	print_matrix(char **c, int size_file, int size_col)
{
	int	fil;
	int	col;

	fil = 0;
	while (fil < size_file)
	{
		col = 0;
		write(1, "\n", 1);
		while (col < size_col)
		{
			write(1, &c[fil][col], 1);
			col++;
		}
		fil++;
	}
}
