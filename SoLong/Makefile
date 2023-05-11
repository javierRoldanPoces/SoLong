
NAME			=	so_long
ifeq ($(shell uname), Darwin)
	CFLAGS			=	-Wall -Werror -Wextra -DEBUG=1
	INCLUDES 		= -Iinclude -lglfw -L /Users/jroldan-/.brew/Cellar/glfw/3.3.8/lib
else
	CFLAGS			=	-Wall -Werror -ldl -Wextra -DEBUG=1
	INCLUDES		= -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif
RM				=	rm -fr
INCLUDE			=	so_long.h Get_Next_Line/get_next_line.h
DIR_MAKE_MLX	=	./MLX42
DIR_SRC			=	./src/
DIR_GNL			=	./GNL/
SRC				=	$(DIR_SRC)so_long.c $(DIR_GNL)get_next_line_utils.c $(DIR_GNL)get_next_line.c \
					$(DIR_SRC)so_long_utils.c $(DIR_SRC)so_long_read_maps.c $(DIR_SRC)so_long_valid_map.c
OBJ				=	$(SRC:.c=.o)

all: make_mlx $(NAME)

make_mlx:
			@$(MAKE) -C $(DIR_MAKE_MLX)

$(NAME):	$(OBJ)
			@gcc $(SRC) -g3 $(CFLAGS) -o $(NAME) $(DIR_MAKE_MLX)/libmlx42.a $(INCLUDES)
			@echo So_long compilado

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_MLX)
		@$(RM) $(OBJ)

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_MLX)
			@$(RM) $(NAME) 
			@echo Todo limpio

.PHONY: 	all make_mlx re clean fclean
