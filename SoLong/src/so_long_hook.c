/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:40:14 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/26 21:09:46 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	control_up(t_so_long *so_long)
{
	if (so_long->map[so_long->player[0] - 1][so_long->player[1]] != '1')
	{
		so_long->dog->instances[0].y -= 64;
		so_long->player[0] -= 1;
		so_long->move++;
		ft_printf("Movimientos : %d\n", so_long->move);
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
			c_found(so_long);
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'E')
		{
			if (so_long->count_c == 0)
				mlx_close_window(so_long->mlx);
		}
	}
}

void	control_down(t_so_long *so_long)
{
	if (so_long->map[so_long->player[0] + 1][so_long->player[1]] != '1')
	{	
		so_long->move++;
		ft_printf("Movimientos : %d\n", so_long->move);
		so_long->dog->instances[0].y += 64;
		so_long->player[0] += 1;

		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
			c_found(so_long);
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'E')
		{
			if (so_long->count_c == 0)
				mlx_close_window(so_long->mlx);
		}
	}
}

void	control_left(t_so_long *so_long)
{
	if (so_long->map[so_long->player[0]][so_long->player[1] - 1] != '1')
	{
		so_long->move++;
		ft_printf("Movimientos : %d\n", so_long->move);
		so_long->dog->instances[0].x -= 64;
		so_long->player[1] -= 1;

		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
			c_found(so_long);
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'E')
		{
			if (so_long->count_c == 0)
				mlx_close_window(so_long->mlx);
		}
	}
}

void	control_right(t_so_long *so_long)
{
	if (so_long->map[so_long->player[0]][so_long->player[1] + 1] != '1')
	{
		so_long->move++;
		ft_printf("Movimientos : %d\n", so_long->move);
		so_long->dog->instances[0].x += 64;
		so_long->player[1] += 1;

		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
			c_found(so_long);
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'E')
		{
			if (so_long->count_c == 0)
			{
				mlx_close_window(so_long->mlx);
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
