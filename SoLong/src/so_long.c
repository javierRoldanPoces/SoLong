/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:17 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/26 23:48:50 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(t_so_long *c)
{
	c->mlx = mlx_init(c->w * S, c->h * S, "So_Long", false);
	if (!c->mlx)
		exit(EXIT_FAILURE);
	c->count_c = 0;
	c->count_e = 0;
	c->count_p = 0;
	c->player[0] = 0;
	c->player[1] = 0;
	c->move = 0;
	c->t_bg = mlx_load_png("img/fondo_playa.png");
	c->t_dog = mlx_load_png("img/dog.png");
	c->t_wall = mlx_load_png("img/wall.png");
	c->t_bone = mlx_load_png("img/bone.png");
	//c->t_closed = mlx_load_png("img/closed.png");
	c->t_open = mlx_load_png("img/open.png");
	c->bg = mlx_texture_to_image(c->mlx, c->t_bg);
	c->dog = mlx_texture_to_image(c->mlx, c->t_dog);
	c->wall = mlx_texture_to_image(c->mlx, c->t_wall);
	c->bone = mlx_texture_to_image(c->mlx, c->t_bone);
	//c->closed = mlx_texture_to_image(c->mlx, c->t_closed);
	c->open = mlx_texture_to_image(c->mlx, c->t_open);
}

void	ft_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_so_long	g;

	atexit(ft_leaks);
	(void)argc;
	read_maps(&g, argv[1]);
	if (map_valid(&g) == 1)
	{
		free_cpy_matrix(g.map, g.w);
		ft_control_error(MAPA_NO_VALID, &g);
		mlx_terminate(g.mlx);
		exit (1);
	}
	init_so_long(&g);
	look_p(&g);
	paint_maps (&g);
	mlx_image_to_window(g.mlx, g.dog, g.player[1] * S, g.player[0] * S);
	g.count_c = look(&g, 'C');
	mlx_key_hook(g.mlx, my_hook, &g);
	mlx_loop(g.mlx);
	ft_control_error(FIN, &g);
	return (EXIT_SUCCESS);
}
