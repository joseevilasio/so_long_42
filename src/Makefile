.PHONY: all $(NAME) bonus clean fclean re

NAME := so_long

BONUS := so_long_bonus

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

all: $(NAME)

$(NAME): $(LIBFT) $(MLIBX) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(MLXFLAGS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT)	$(MLIBX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(BONUS) $(MLXFLAGS) $(LIBFT)

$(MLIBX):
	make -C $(MLIBX_DIR)

$(LIBFT):
	make all -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLIBX_DIR)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(MLIBX) $(BONUS)

re:	fclean all