/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:17 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/11 19:01:45 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP) || mlx_is_key_down(param, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN) || mlx_is_key_down(param, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT) || mlx_is_key_down(param, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT) || mlx_is_key_down(param, MLX_KEY_D))
		g_img->instances[0].x += 5;
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
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	(void)argc;
	init_so_long(&so_long);
	read_maps(&so_long, argv[1]);
	print_matrix(so_long.map, so_long.h, so_long.w);
	map_valid(&so_long);
	//atexit(ft_leaks);
	/*g_img = mlx_new_image(&so_long.mlx, 256, 256);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(&so_long.mlx, g_img, 0, 0);
	mlx_loop_hook(&so_long.mlx, &hook, &so_long.mlx);
	mlx_loop(&so_long.mlx);
	mlx_terminate(&so_long.mlx);*/
	return (EXIT_SUCCESS);
}
