
NAME	=	so_long
NAME_BONUS	=	so_long_bonus

ifeq ($(shell uname), Darwin)
	CFLAGS			=	-Wall -Werror -Wextra -DEBUG=1
	INCLUDES 		= -Iinclude -lglfw -L /Users/jroldan-/.brew/Cellar/glfw/3.3.8/lib
else
	CFLAGS			=	-Wall -Werror -ldl -Wextra -DEBUG=1
	INCLUDES		= -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif
RM				=	rm -fr
INCLUDE			=	so_long.h GNL/get_next_line.h ft_printf/ft_printf.h
DIR_MAKE_MLX	=	./MLX42
DIR_SRC			=	./src/
DIR_SRC_BONUS	=	./src_bonus/
DIR_GNL			=	./GNL/
DIR_FT_PRINTF	=	./ft_printf
SRC				=	$(DIR_SRC)so_long.c $(DIR_GNL)get_next_line_utils.c $(DIR_GNL)get_next_line.c \
					$(DIR_SRC)so_long_utils.c $(DIR_SRC)so_long_read_maps.c $(DIR_SRC)so_long_valid_map.c \
					$(DIR_SRC)so_long_paint_maps.c $(DIR_SRC)so_long_hook.c

SRC_BONUS		=	$(DIR_SRC_BONUS)so_long_bonus.c $(DIR_GNL)get_next_line_utils.c $(DIR_GNL)get_next_line.c \
					$(DIR_SRC_BONUS)so_long_utils_bonus.c $(DIR_SRC_BONUS)so_long_read_maps_bonus.c $(DIR_SRC_BONUS)so_long_valid_map_bonus.c \
					$(DIR_SRC_BONUS)so_long_paint_maps_bonus.c $(DIR_SRC_BONUS)so_long_hook_bonus.c	$(DIR_SRC_BONUS)so_long_utils_bonus_2.c

OBJ				=	$(SRC:.c=.o)

OBJ_BONUS		=	$(SRC_BONUS:.c=.o)

all: make_mlx make_ft_printf $(NAME)

make_ft_printf:
			@$(MAKE) -C $(DIR_FT_PRINTF)
make_mlx:
			@$(MAKE) -C $(DIR_MAKE_MLX)

$(NAME):	$(OBJ)
			@gcc $(SRC) -g3 $(CFLAGS) -o $(NAME) $(DIR_MAKE_MLX)/libmlx42.a $(DIR_FT_PRINTF)/ft_printf.a $(INCLUDES)
			@echo completed

$(NAME_BONUS):	$(OBJ_BONUS)
			@gcc $(SRC_BONUS) -g3 $(CFLAGS) -o $(NAME_BONUS) $(DIR_MAKE_MLX)/libmlx42.a $(DIR_FT_PRINTF)/ft_printf.a $(INCLUDES)
			@echo bonus completed

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_MLX)
		@$(MAKE) -s clean -C $(DIR_FT_PRINTF)
		@$(RM) $(OBJ)
		@$(RM) $(OBJ_BONUS)

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_MLX)
			@$(MAKE) -s fclean -C $(DIR_FT_PRINTF)
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)
			@echo all cleaned

bonus:		make_mlx make_ft_printf $(NAME_BONUS)	

.PHONY: 	all make_mlx make_ft_printf re clean fclean bonus
