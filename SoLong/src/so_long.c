/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:17 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/23 18:55:46 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(t_so_long *c)
{
	c->mlx = mlx_init(c->w * 64, c->h * 64, "So_Long", true);
	if (!c->mlx)
		exit(EXIT_FAILURE);
	c->count_c = 0;
	c->count_e = 0;
	c->count_p = 0;
	c->player[0] = 0;
	c->player[1] = 0;
	c->t_bg = mlx_load_png("img/fondo_playa.png");
	c->t_dog = mlx_load_png("img/dog.png");
	c->t_wall = mlx_load_png("img/wall.png");
	c->t_bone = mlx_load_png("img/bone.png");
	c->t_closed = mlx_load_png("img/closed.png");
	c->t_open = mlx_load_png("img/open.png");
	c->bg = mlx_texture_to_image(c->mlx, c->t_bg);
	c->dog = mlx_texture_to_image(c->mlx, c->t_dog);
	c->wall = mlx_texture_to_image(c->mlx, c->t_wall);
	c->bone = mlx_texture_to_image(c->mlx, c->t_bone);
	c->closed = mlx_texture_to_image(c->mlx, c->t_closed);
	c->open = mlx_texture_to_image(c->mlx, c->t_open);
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;
	//atexit(ft_leaks);
	(void)argc;
	read_maps(&so_long, argv[1]);
	print_matrix(so_long.map, so_long.h, so_long.w);
	if (map_valid(&so_long) == 1)
	{
		free_cpy_matrix(so_long.map, so_long.w);
		mlx_terminate(so_long.mlx);
		exit (1);
	}
	init_so_long(&so_long);
	look_p(&so_long);
	paint_maps (&so_long);
	mlx_image_to_window(so_long.mlx, so_long.dog, so_long.player[1] * 64, so_long.player[0] * 64);
	so_long.count_c = look(&so_long, 'C');
	mlx_key_hook(so_long.mlx, my_hook, &so_long);
	mlx_loop(so_long.mlx);
	mlx_terminate(so_long.mlx);
	//liberar todo
	free_cpy_matrix(so_long.map, so_long.h);
	return (EXIT_SUCCESS);
}
