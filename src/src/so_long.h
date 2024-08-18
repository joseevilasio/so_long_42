/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 15:54:42 by joneves-         ###   ########.fr       */
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

# define SUCCESS 0
/* Internal process failure range 100 | perror() */
# define ERROR_OPEN 101
# define ERROR_READ 102
# define ERROR_MALLOC 103
/* External process failure range 200 | ft_printf() */
# define ERROR_ARGUMENTS 201
# define ERROR_TYPE 202
# define ERROR_MAP 203

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
}	t_data;

/* Struct for variables for mlx stuffs */
typedef struct s_vars
{
	void	*mlx;
	void	*window;
}	t_vars;

/* Free & Error handler */
void	ft_error_handler(char *error, int signal, char *str, t_data *data);
void	ft_free_data(t_data *data);
void	ft_free_map(char **source);

void	ft_loadmap(char *pathname, t_data *data);
void	ft_render(void *mlx, void *window, char **map, int map_width, int map_height);

// so_long utils
char	**ft_copymap(char **source, t_data *data);

// loadmap utils
int		ft_open(char *pathname, t_data *data);
void	ft_data_init(t_data *data);
void	ft_printmap(char **source, int height, int width);
void	ft_floodfill(char **map, t_data *data, int x, int y);
char	*ft_strremove(char *str, char *target);

/* 
https://www.oreilly.com/library/view/xlib-reference-manual/
9780937175262/16_appendix-h.html
Utilizar keysym para mapear teclas

Refatorar funcoes do map, mudanca de int ** para char **
*/

#endif //SO_LONG_H