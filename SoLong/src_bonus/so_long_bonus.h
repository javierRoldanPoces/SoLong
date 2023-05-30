/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:54:20 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/30 22:49:56 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUSH
# define S 64
# define NO_BER -1
# define MAPA_NO_VALID -2
# define FIN -3
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
	int				move;
	mlx_image_t		*bg;
	mlx_texture_t	*t_bg;
	mlx_image_t		*dog;
	mlx_texture_t	*t_dog;
	mlx_image_t		*wall;
	mlx_texture_t	*t_wall;
	mlx_image_t		*bone;
	mlx_texture_t	*t_bone;
	mlx_image_t		*open;
	mlx_texture_t	*t_open;
}	t_so_long;

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	read_maps(t_so_long *c, char *name_file);
void	read_maps_2(t_so_long *c, char *name_file);
void	ft_leaks(void);
int		map_valid(t_so_long *c);
int		look(t_so_long *c, char s);
void	look_p(t_so_long *c);
void	flood_fill(char **map, int i, int j);
char	**cpy_matrix(t_so_long *c);
void	free_cpy_matrix(char **c, int fil);
void	paint_maps(t_so_long *c);
void	my_hook(mlx_key_data_t keydata, void *param);
void	paint_collec(t_so_long *c);
void	c_found(t_so_long *so_long);
void	ft_control_error(int error, t_so_long *c);
void	ft_delete_img(t_so_long *c);

#endif