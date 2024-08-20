/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/20 20:24:51 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define SUCCESS 0
/* Internal process failure range 100 | perror() */
# define ERROR_OPEN 101
# define ERROR_READ 102
# define ERROR_MALLOC 103
# define ERROR_MLX 104
/* External process failure range 200 | ft_printf() */
# define ERROR_ARGUMENTS 201
# define ERROR_TYPE 202
# define ERROR_MAP 203

/* Path textures */
# define WALL "./textures/wall.xpm"
# define COLL "./textures/coll.xpm"
# define PLAYER "./textures/player.xpm"
# define EXIT "./textures/exit.xpm"
# define EMPTY "./textures/empty.xpm"
# define PIXEL 80

/* Struct for initial infor about map */
typedef struct s_data
{
	int		width;
	int		height;
	int		pplayer_h;
	int		pplayer_w;
	int		c;
	int		p;
	int		e;
	int		ff_c;
	int		ff_e;
	char	**map;
	char	**new_map;
	void	*mlx;
	void	*win;
	int		img_size;
	void	*img_wall;
	void	*img_coll;
	void	*img_player;
	void	*img_exit;
	void	*img_empty;
	int		movements;
	int		bag;
}	t_data;

/* Free & Error handler */
void	ft_error_handler(char *error, int signal, char *str, t_data *data);
void	ft_free_data(t_data *data);
void	ft_free_map(char **source);
void	ft_free_image(t_data *data);

/* Loadmap & Ensure Map */
void	ft_loadmap(char *pathname, t_data *data);
int		ft_open(char *pathname, t_data *data);
void	ft_data_init(t_data *data);
void	ft_printmap(char **source, int height, int width);
void	ft_floodfill(char **map, t_data *data, int x, int y);
char	*ft_strremove(char *str, char *target);

/* Render */
void	ft_render_background(t_data *data);
void	ft_render_layer(t_data *data);
void	put_empty(t_data *data, char set);
void	put_player(t_data *data);

// so_long utils
char	**ft_copymap(char **source, t_data *data);

/* Actions */
int		move_left(t_data *data);
int		move_right(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);

/* Organizar isso */
void	close_window(t_data *data);

/* 
https://www.oreilly.com/library/view/xlib-reference-manual/
9780937175262/16_appendix-h.html
Utilizar keysym para mapear teclas

Refatorar funcoes do map, mudanca de int ** para char **
*/

#endif //SO_LONG_H
