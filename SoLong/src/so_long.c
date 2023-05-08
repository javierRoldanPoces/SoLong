#include "so_long.h"
#define WIDTH 1000
#define HEIGHT 1000

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP) || mlx_is_key_down(param, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN) || mlx_is_key_down(param, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT) || mlx_is_key_down(param, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT) || mlx_is_key_down(param, MLX_KEY_D))
		g_img->instances[0].x += 5;
}

int read_maps(t_so_long *c, char *name_file)
{
	int		file;
	int		size;
	char	*line;

	file = open(name_file, O_RDONLY);
	if (file < 0)
	{
		//printf("file < 0");
		return (-2);
	}
	
	size = (int)ft_strlen(name_file);
	if (ft_memcmp(&name_file[size - 4], ".ber", 4))
	{	
		write(1, "ERROR", 5);
		return (-1);
	}
	line = get_next_line(file);
	c->h++;
	c->w = (int)ft_strlen(line) - 1;
	while(line)
	{
		free(line);
	//	printf("\nEntra\n");
		line = get_next_line(file);
		if(c->w != (int)ft_strlen(line) - 1 && ft_strlen(line))// estoy comprobando que coincida el tam de columna
		{	
			printf("%d W   %d\n", c->w, (int)ft_strlen(line) - 1);
			return(free(line), -3);
		}
		c->h++;
	}
	free(line);
	close(file);
	read_maps_2(c, name_file);
	return (0);
}

int read_maps_2(t_so_long *c, char *name_file)
{
	int	f;
	int	file;
	char *line;

	f = 0;
	c->map = (char **)ft_calloc(sizeof(char *),c->h + 1);
	file = open(name_file, O_RDONLY);
	line = get_next_line(file);
	c->map[0] = line;
	while(c->map[f])
	{
		//free(line);
		c->map[++f] = get_next_line(file);
	}
	//free(line);
	close(file);

	print_matrix(c);
	return (0);
}

void	print_matrix(t_so_long *c)
{
	int fil;
	int col;

	fil = 0;
	
	while (fil < c->h)
	{
		col = 0;
		write(1, "\n", 1);
		while(col < c->w)
		{
			write(1, &c->map[fil][col], 1);
			col++;
		}
		fil++;
	}
	
}

void init_so_long(t_so_long *c)
{
	c->mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!c->mlx)
		exit(EXIT_FAILURE);
	c->h = 0;
	c->w = 0;
}

void ft_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_so_long so_long;

	(void)argc;
	init_so_long(&so_long);
	read_maps(&so_long, argv[1]);
	atexit(ft_leaks);
	/*g_img = mlx_new_image(&so_long.mlx, 256, 256);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(&so_long.mlx, g_img, 0, 0);
	mlx_loop_hook(&so_long.mlx, &hook, &so_long.mlx);
	mlx_loop(&so_long.mlx);
	mlx_terminate(&so_long.mlx);*/
	return (EXIT_SUCCESS);
}