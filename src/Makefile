.PHONY: all $(NAME) bonus clean fclean re

NAME := so_long

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

MLXFLAGS := -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

MLIBX_DIR := libs/minilibx-linux

LIBFT := libs/libft

SRCS := src/so_long.c src/ft_loadmap.c src/so_long_utils.c\
		src/free_error_handler.c src/loadmap_utils.c src/ft_render.c\

SRCS_BONUS := bonus/so_long_bonus.c bonus/loadmap_bonus.c\
		bonus/free_error_handler_bonus.c bonus/initiators_bonus.c\
		bonus/loadmap_utils_bonus.c bonus/render_bonus.c\

all:	$(NAME)

# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) -c $*.c -o $@

# # $(OBJS_BONUS): $(SRCS_BONUS)
# # 	$(CC) $(CFLAGS) -c $*.c -o $@

$(NAME): $(MLIBX_DIR)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(MLXFLAGS) $(LIBFT)/libft.a

bonus: $(MLIBX_DIR)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME) $(MLXFLAGS) $(LIBFT)/libft.a

$(MLIBX):
	make -C $(MLIBX_DIR)

clean:
	make clean -C $(LIBFT)

fclean:	clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re:	fclean all
