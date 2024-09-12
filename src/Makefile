NAME := so_long

NAME_BONUS := so_long_bonus

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

MLXFLAGS := -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

MLIBX_DIR := libs/minilibx-linux

MLIBX := libs/minilibx-linux/libmlx.a

LIBFT := libs/libft/libft.a

LIBFT_DIR := libs/libft

SRCS := src/so_long.c\
		src/ft_loadmap.c\
		src/so_long_utils.c\
		src/free_error_handler.c\
		src/loadmap_utils.c\
		src/ft_render.c\

SRCS_BONUS := bonus/so_long_bonus.c\
			bonus/loadmap_bonus.c\
			bonus/free_error_handler_bonus.c\
			bonus/initiators_bonus.c\
			bonus/loadmap_utils_bonus.c\
			bonus/render_bonus.c\
			bonus/enemy_bonus.c\
			bonus/background_bonus.c\
			bonus/player_bonus.c\
			bonus/collectibles_bonus.c\

$(NAME): $(LIBFT) $(MLIBX) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

all: $(NAME) bonus

$(MLIBX):
	make -C $(MLIBX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(NAME_BONUS) 

$(NAME_BONUS): $(LIBFT)	$(MLIBX) $(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(MLXFLAGS) $(LIBFT) -o $(NAME_BONUS) 

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLIBX_DIR)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) 
	rm -f $(NAME_BONUS)
	rm -f $(MLIBX)

re:	fclean all

.PHONY: all bonus clean fclean re
