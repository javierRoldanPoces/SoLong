/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:40:14 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/31 19:08:25 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	control_up(t_so_long *g)
{
	if (g->map[g->player[0] - 1][g->player[1]] != '1')
	{
		g->move++;
		ft_printf("Movimientos : %d\n", g->move);
		mlx_delete_texture(g->t_dog);
		mlx_delete_image(g->mlx, g->dog);
		g->t_dog = mlx_load_png("img/dog_up.png");
		g->dog = mlx_texture_to_image(g->mlx, g->t_dog);
		mlx_image_to_window(g->mlx, g->dog, g->player[1] * S, g->player[0] * S);
		g->dog->instances[0].y -= 64;
		g->player[0] -= 1;
		if (g->map[g->player[0]][g->player[1]] == 'C')
			c_found(g);
		if (g->map[g->player[0]][g->player[1]] == 'E')
		{
			if (g->count_c == 0)
				mlx_close_window(g->mlx);
		}
	}
}

void	control_down(t_so_long *g)
{
	if (g->map[g->player[0] + 1][g->player[1]] != '1')
	{	
		g->move++;
		ft_printf("Movimientos : %d\n", g->move);
		mlx_delete_texture(g->t_dog);
		mlx_delete_image(g->mlx, g->dog);
		g->t_dog = mlx_load_png("img/dog_down.png");
		g->dog = mlx_texture_to_image(g->mlx, g->t_dog);
		mlx_image_to_window(g->mlx, g->dog, g->player[1] * S, g->player[0] * S);
		g->dog->instances[0].y += 64;
		g->player[0] += 1;
		if (g->map[g->player[0]][g->player[1]] == 'C')
			c_found(g);
		if (g->map[g->player[0]][g->player[1]] == 'E')
		{
			if (g->count_c == 0)
				mlx_close_window(g->mlx);
		}
	}
}

void	control_left(t_so_long *g)
{
	if (g->map[g->player[0]][g->player[1] - 1] != '1')
	{
		g->move++;
		ft_printf("Movimientos : %d\n", g->move);
		mlx_delete_texture(g->t_dog);
		mlx_delete_image(g->mlx, g->dog);
		g->t_dog = mlx_load_png("img/dog_left.png");
		g->dog = mlx_texture_to_image(g->mlx, g->t_dog);
		mlx_image_to_window(g->mlx, g->dog, g->player[1] * S, g->player[0] * S);
		g->dog->instances[0].x -= 64;
		g->player[1] -= 1;
		if (g->map[g->player[0]][g->player[1]] == 'C')
			c_found(g);
		if (g->map[g->player[0]][g->player[1]] == 'E')
		{
			if (g->count_c == 0)
				mlx_close_window(g->mlx);
		}
	}
}

void	control_right(t_so_long *g)
{
	if (g->map[g->player[0]][g->player[1] + 1] != '1')
	{
		g->move++;
		ft_printf("Movimientos : %d\n", g->move);
		mlx_delete_texture(g->t_dog);
		mlx_delete_image(g->mlx, g->dog);
		g->t_dog = mlx_load_png("img/dog_right.png");
		g->dog = mlx_texture_to_image(g->mlx, g->t_dog);
		mlx_image_to_window(g->mlx, g->dog, g->player[1] * S, g->player[0] * S);
		g->dog->instances[0].x += 64;
		g->player[1] += 1;
		if (g->map[g->player[0]][g->player[1]] == 'C')
			c_found(g);
		if (g->map[g->player[0]][g->player[1]] == 'E')
		{
			if (g->count_c == 0)
			{
				mlx_close_window(g->mlx);
			}
		}	
	}
}

void	my_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		mlx_close_window(so_long->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == 1)
		control_up(so_long);
	else if (keydata.key == MLX_KEY_S && keydata.action == 1)
		control_down(so_long);
	else if (keydata.key == MLX_KEY_A && keydata.action == 1)
		control_left(so_long);
	else if (keydata.key == MLX_KEY_D && keydata.action == 1)
		control_right(so_long);
}
