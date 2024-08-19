.PHONY: all $(NAME) bonus clean fclean re

NAME := so_long

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

LIBFT := libs/libft

SRCS := src/so_long.c src/ft_loadmap.c src/so_long_utils.c src/actions.c\
		src/free_error_handler.c src/loadmap_utils.c src/ft_render.c\

# OBJS := ft_loadmap.o ft_floodfill.o ft_error_handler.o so_long_utils.o ft_render.o\

# SRCS_BONUS := bonus/pipex_utils_bonus.c bonus/ft_parser_bonus.c  \
# 			bonus/ft_heredoc_bonus.c\

# OBJS_BONUS :=  bonus/pipex_utils_bonus.o  bonus/ft_parser_bonus.o \
# 			bonus/ft_heredoc_bonus.o\

all:	$(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $*.c -o $@

# $(OBJS_BONUS): $(SRCS_BONUS)
# 	$(CC) $(CFLAGS) -c $*.c -o $@

$(NAME):
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(MLXFLAGS) $(LIBFT)/libft.a

# bonus: $(OBJS_BONUS)
# 	make all -C $(LIBFT)
# 	$(CC) $(CFLAGS) bonus/$(NAME)_bonus.c -o $(NAME) bonus/$(NAME).a $(LIBFT)/$(LIBFT).a

clean:
	make clean -C $(LIBFT)

fclean:	clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re:	fclean all