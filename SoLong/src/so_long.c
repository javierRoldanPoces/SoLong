/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:17 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/14 18:25:54 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	hook(void *param)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)param;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so_long->mlx);
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_UP) || mlx_is_key_down(so_long->mlx, MLX_KEY_W))
		so_long->dog->instances[0].y -= 64;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_DOWN) || mlx_is_key_down(so_long->mlx, MLX_KEY_S))
		so_long->dog->instances[0].y += 64;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_LEFT) || mlx_is_key_down(so_long->mlx, MLX_KEY_A))
		so_long->dog->instances[0].x -= 64;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(so_long->mlx, MLX_KEY_D))
		so_long->dog->instances[0].x += 64;
}

void	init_so_long(t_so_long *c)
{
	c->mlx = mlx_init(c->w * 64, c->h *64, "So_Long", true);
	if (!c->mlx)
		exit(EXIT_FAILURE);
	//c->h = 0;
	//c->w = 0;
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
	//so_long.t_bg = mlx_load_png("img/fondo_playa.png");
	//so_long.bg = mlx_texture_to_image(so_long.mlx, so_long.t_bg);
	paint_maps (&so_long);
	mlx_image_to_window(so_long.mlx, so_long.dog, so_long.player[0] * 64, so_long.player[1] * 64);
	mlx_loop_hook(so_long.mlx, &hook, &so_long);
	mlx_loop(so_long.mlx);
	//paint_maps (&so_long);
	mlx_terminate(so_long.mlx);
	
	free_cpy_matrix(so_long.map, so_long.h);
	return (EXIT_SUCCESS);
}
// imagenes 64 *64 aprox