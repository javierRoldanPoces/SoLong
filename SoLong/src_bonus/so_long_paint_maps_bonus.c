/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_paint_maps_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:31 by javier            #+#    #+#             */
/*   Updated: 2023/05/31 19:49:23 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	paint_maps(t_so_long *c)
{
	int	fil;
	int	col;

	fil = -1;
	while (++fil < c->h)
	{
		col = -1;
		while (++col < c->w)
		{
			mlx_image_to_window(c->mlx, c->bg, col * 64, fil * 64);
			if (c->map[fil][col] == '1')
				mlx_image_to_window(c->mlx, c->wall, col * 64, fil * 64);
			else if (c->map[fil][col] == 'C')
				mlx_image_to_window(c->mlx, c->bone, col * 64, fil * 64);
			else if (c->map[fil][col] == 'X')
				mlx_image_to_window(c->mlx, c->enemy, col * 64, fil * 64);
			else if (c->map[fil][col] == 'E')
			{
				mlx_image_to_window(c->mlx, c->closed, col * 64, fil * 64);
				c->door[0] = fil;
				c->door[1] = col;
			}
		}
	}
}

void	paint_collec(t_so_long *c)
{
	int	fil;
	int	col;

	fil = 0;
	c->bone = mlx_texture_to_image(c->mlx, c->t_bone);
	while (fil < c->h)
	{
		col = 0;
		while (col < c->w)
		{
			if (c->map[fil][col] == 'C')
			{	
				mlx_image_to_window(c->mlx, c->bone, col * S, fil * S);
			}
			col++;
		}
		fil++;
	}
}
