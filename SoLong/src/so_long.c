/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:17 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/12 15:28:40 by Jroldan-         ###   ########.fr       */
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
		so_long->bg->instances[0].y -= 64;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_DOWN) || mlx_is_key_down(so_long->mlx, MLX_KEY_S))
		so_long->bg->instances[0].y += 64;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_LEFT) || mlx_is_key_down(so_long->mlx, MLX_KEY_A))
		so_long->bg->instances[0].x -= 64;
	if (mlx_is_key_down(so_long->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(so_long->mlx, MLX_KEY_D))
		so_long->bg->instances[0].x += 64;
}

void	init_so_long(t_so_long *c)
{
	c->mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!c->mlx)
		exit(EXIT_FAILURE);
	c->h = 0;
	c->w = 0;
	c->count_c = 0;
	c->count_e = 0;
	c->count_p = 0;
	c->player[0] = 0;
	c->player[1] = 0;
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;
	//atexit(ft_leaks);
	(void)argc;
	init_so_long(&so_long);
	read_maps(&so_long, argv[1]);
	print_matrix(so_long.map, so_long.h, so_long.w);
	if (map_valid(&so_long) == 1)
	{
		free_cpy_matrix(so_long.map, so_long.w);
		mlx_terminate(so_long.mlx);
		exit (1);
	}
	so_long.t_bg = mlx_load_png("img/fondo_playa.png");
	so_long.bg = mlx_texture_to_image(so_long.mlx, so_long.t_bg);
	mlx_image_to_window(so_long.mlx, so_long.bg, 0, 0);
	mlx_loop_hook(so_long.mlx, &hook, &so_long);
	mlx_loop(so_long.mlx);
	mlx_terminate(so_long.mlx);
	
	free_cpy_matrix(so_long.map, so_long.h);
	return (EXIT_SUCCESS);
}
// imagenes 64 *64 aprox