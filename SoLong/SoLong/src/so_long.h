/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:54:20 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/23 18:58:01 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 256
# define HEIGHT 256
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <memory.h>
# include "../GNL/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct so_so_long
{
	mlx_t			*mlx;
	char			**map;
	int				h;
	int				w;
	int				count_c;
	int				count_e;
	int				count_p;
	int				player[2];
	mlx_image_t		*bg;
	mlx_texture_t	*t_bg;
	mlx_image_t		*dog;
	mlx_texture_t	*t_dog;
	mlx_image_t		*wall;
	mlx_texture_t	*t_wall;
	mlx_image_t		*bone;
	mlx_texture_t	*t_bone;
	mlx_image_t		*closed;
	mlx_texture_t	*t_closed;
	mlx_image_t		*open;
	mlx_texture_t	*t_open;
}	t_so_long;

//void	hook(void *param);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		read_maps(t_so_long *c, char *name_file);
int		read_maps_2(t_so_long *c, char *name_file);
void	print_matrix(char **c, int size_file, int size_col);
void	ft_leaks(void);
int		map_valid(t_so_long *c);
int		look(t_so_long *c, char s);
void	look_p(t_so_long *c);
void	flood_fill(char **map, int i, int j);
char	**cpy_matrix(t_so_long *c);
void	free_cpy_matrix(char **c, int fil);
void	paint_maps(t_so_long *c);
void	my_hook(mlx_key_data_t keydata, void *param);

#endif