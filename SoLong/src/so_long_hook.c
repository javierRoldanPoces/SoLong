/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:40:14 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/24 13:50:32 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	control_up(mlx_key_data_t keydata, t_so_long *so_long)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		so_long->dog->instances[0].y -= 64;
		so_long->player[0] -= 1;
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
		{
			mlx_delete_image(so_long->mlx, so_long->bone);
			so_long->count_c--;
			so_long->map[so_long->player[0]][so_long->player[1]] = '0';
			printf("\n%d\n", so_long->count_c);
			if (so_long->count_c > 0)
			{
				printf("entra en printar collec\n");
				paint_collec(so_long);
			}
		}
	}
}

void	control_down(mlx_key_data_t keydata, t_so_long *so_long)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{	
		so_long->player[0] += 1;
		so_long->dog->instances[0].y += 64;
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
		{
			mlx_delete_image(so_long->mlx, so_long->bone);
			so_long->count_c--;
			so_long->map[so_long->player[0]][so_long->player[1]] = '0';			
			if (so_long->count_c > 0)
			{
				printf("entra en printar collec\n");
				paint_collec(so_long);
			}
		}
	}
}

void	control_left(mlx_key_data_t keydata, t_so_long *so_long)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		so_long->player[1] -= 1;
		so_long->dog->instances[0].x -= 64;
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
		{
			mlx_delete_image(so_long->mlx, so_long->bone);
			so_long->count_c--;
			so_long->map[so_long->player[0]][so_long->player[1]] = '0';
			printf("\n%d\n", so_long->count_c);
			if (so_long->count_c > 0)
			{
				printf("entra en printar collec\n");
				paint_collec(so_long);
			}
		}

	}
}

void	control_right(mlx_key_data_t keydata, t_so_long *so_long)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		so_long->player[1] += 1;
		so_long->dog->instances[0].x += 64;
		if (so_long->map[so_long->player[0]][so_long->player[1]] == 'C')
		{
			mlx_delete_image(so_long->mlx, so_long->bone);
			so_long->count_c--;
			so_long->map[so_long->player[0]][so_long->player[1]] = '0';
			printf("\n%d\n", so_long->count_c);
			if (so_long->count_c > 0)
			{
				printf("entra en printar collec\n");
				paint_collec(so_long);
			}
		}
	}
}

void	my_hook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(so_long->mlx);
	if (so_long->map[so_long->player[0] - 1][so_long->player[1]] != '1')
		control_up(keydata, so_long);
	if (so_long->map[so_long->player[0] + 1][so_long->player[1]] != '1')
		control_down(keydata, so_long);
	if (so_long->map[so_long->player[0]][so_long->player[1] - 1] != '1')
		control_left(keydata, so_long);
	if (so_long->map[so_long->player[0]][so_long->player[1] + 1] != '1')
		control_right(keydata, so_long);
	//print_matrix(so_long->map, so_long->h, so_long->w);
	//printf("\nfila %d, col %d", so_long->player[0], so_long->player[1]);
}
