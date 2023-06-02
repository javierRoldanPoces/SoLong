/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_maps_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:58:08 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/01 20:11:00 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	read_maps(t_so_long *c, char *name_file)
{
	int		file;
	int		size;
	char	*line;

	file = open(name_file, O_RDONLY);
	if (file < 0)
		ft_printf("Error\nApertura de fichero");
	size = (int)ft_strlen(name_file);
	if (ft_memcmp(&name_file[size - 4], ".ber", 4))
		ft_control_error(NO_BER, c);
	line = get_next_line(file);
	c->h++;
	c->w = (int)ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (c->w != (int)ft_strlen(line) - 1 && ft_strlen(line))
			free(line);
		c->h++;
	}
	c->h--;
	free(line);
	close(file);
	read_maps_2(c, name_file);
}

void	read_maps_2(t_so_long *c, char *name_file)
{
	int		f;
	int		file;
	char	*line;

	f = 0;
	c->map = (char **)ft_calloc(sizeof(char *), c->h + 1);
	file = open(name_file, O_RDONLY);
	if (file < 0)
		ft_printf("Error\nApertura de fichero");
	line = get_next_line(file);
	c->map[0] = line;
	while (c->map[f])
		c->map[++f] = get_next_line(file);
	close(file);
}

void	ft_control_error(int error, t_so_long *c)
{
	if (error == NO_BER)
		(ft_printf("Error\nExtension de archivo no válida"));
	if (error == FIN)
	{
		while (--c->h)
			free(c->map[c->h]);
		free(c->map[c->h]);
		free(c->map);
		ft_delete_img(c);
		mlx_close_window(c->mlx);
		mlx_terminate(c->mlx);
		exit(ft_printf("\nFin Programa\n"));
	}
	if (error == MAPA_NO_VALID)
		exit(write(1, "\n[ERROR]Mapa no correcto.\n\n", 28));
}

void	ft_delete_img(t_so_long *c)
{
	mlx_delete_texture(c->t_bg);
	mlx_delete_image(c->mlx, c->bg);
	mlx_delete_texture(c->t_dog);
	mlx_delete_image(c->mlx, c->dog);
	mlx_delete_texture(c->t_wall);
	mlx_delete_image(c->mlx, c->wall);
	mlx_delete_texture(c->t_bone);
	mlx_delete_image(c->mlx, c->bone);
	mlx_delete_texture(c->t_open);
	mlx_delete_image(c->mlx, c->open);
	mlx_delete_texture(c->t_enemy);
	mlx_delete_image(c->mlx, c->enemy);
}
