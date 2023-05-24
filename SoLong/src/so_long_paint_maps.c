/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_paint_maps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:31 by javier            #+#    #+#             */
/*   Updated: 2023/05/24 13:50:50 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			else if (c->map[fil][col] == 'E')
				mlx_image_to_window(c->mlx, c->open, col * 64, fil * 64);
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
				mlx_image_to_window(c->mlx, c->bone, col * 64, fil * 64);
			}
			col++;
		}
		fil++;
	}

}
