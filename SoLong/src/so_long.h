#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <memory.h>
# include "../GNL/get_next_line.h"

typedef  struct so_so_long
{
	mlx_t	*mlx;
	char	**map;
	int		h;
	int		w;
}	t_so_long;


void	hook(void *param);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
int read_maps(t_so_long *c, char *name_file);
int read_maps_2(t_so_long *c, char *name_file);
void	print_matrix(t_so_long *c);

#endif