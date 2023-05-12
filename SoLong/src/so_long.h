/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:54:20 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/05/12 10:23:17 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1000
# define HEIGHT 1000
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
	mlx_t	*mlx;
	char	**map;
	int		h;
	int		w;
	int		count_c;
	int		count_e;
	int		count_p;
	int		player[2];
}	t_so_long;

void	hook(void *param);
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
#endif