/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/30 19:55:33 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

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

/* Dir */
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3

/* Path textures */
# define WALL_00 "./textures/wall/wall_00.xpm"
# define WALL_01 "./textures/wall/wall_01.xpm"
# define WALL_1 "./textures/wall/wall_1.xpm"
# define WALL_2 "./textures/wall/wall_2.xpm"
# define COLL "./textures/coll.xpm"
# define PLAYER "./textures/player.xpm"
# define PLAYER_1 "./textures/player_exit.xpm"
# define EXIT "./textures/exit.xpm"
# define EMPTY "./textures/empty.xpm"
# define PXL 32

/* Path Enemy */
# define EBACK0 "./textures/enemy/eback0.xpm"
# define EBACK1 "./textures/enemy/eback1.xpm"
# define EBACK2 "./textures/enemy/eback2.xpm"
# define EFRONT0 "./textures/enemy/efront0.xpm"
# define EFRONT1 "./textures/enemy/efront1.xpm"
# define EFRONT2 "./textures/enemy/efront2.xpm"
# define ELEFT0 "./textures/enemy/eleft0.xpm"
# define ELEFT1 "./textures/enemy/eleft1.xpm"
# define ELEFT2 "./textures/enemy/eleft2.xpm"
# define ERIGHT0 "./textures/enemy/eright0.xpm"
# define ERIGHT1 "./textures/enemy/eright1.xpm"
# define ERIGHT2 "./textures/enemy/eright2.xpm"

/* Struct IMAGE */
typedef struct s_image
{
	void	*wall_00;
	void	*wall_01;
	void	*wall_1;
	void	*wall_2;
	void	*coll;
	void	*player;
	void	*player_1;
	void	*exit;
	void	*empty;
	void	*eback0;
	void	*eback1;
	void	*eback2;
	void	*efront0;
	void	*efront1;
	void 	*efront2;
	void	*eleft0;
	void	*eleft1;
	void	*eleft2;
	void	*eright0;
	void	*eright1;
	void	*eright2;
}	t_image;

/* Struct for initial infor about map */
typedef struct s_data
{
	int		width;
	int		height;
	int		pplayer_h;
	int		pplayer_w;
	int		penemy_h;
	int		penemy_w;
	int		c;
	int		p;
	int		e;
	int		enemy;
	int		ff_c;
	int		ff_e;
	char	**map;
	char	**new_map;
	void	*mlx;
	void	*win;
	int		size;
	int		movements;
	int		bag;
	t_image	*img;
	time_t r_move_time;
}	t_data;

/* Free & Error handler */
void	ft_error_handler(char *error, int signal, char *str, t_data *data);
void	ft_free_data(t_data *data);
void	ft_free_map(char **source);
void	ft_free_image(t_data *data);

/* Loadmap & Ensure Map */
void	ft_loadmap(char *pathname, t_data *data);
int		ft_open(char *pathname, t_data *data);
void	ft_floodfill(char **map, t_data *data, int x, int y);
char	*ft_strremove(char *str, t_data *data);
char	**ft_copymap(char **source, t_data *data);
void	ft_data_init(t_data *data);
void	ft_printmap(char **source);

/* Render */
void	ft_render_background(t_data *data);
void	ft_render_layer(t_data *data, int old_y, int old_x);
void	water(t_data *data);
void	put_image(t_data *data, void *img, int column, int line);

/* Animations */


/* Initiators */
void	all_init(t_data *data, char *path);
void	data_init(t_data *data);
void	image_init(t_data *data);
void	image_init_null(t_data *data);

#endif //SO_LONG_BONUS_H