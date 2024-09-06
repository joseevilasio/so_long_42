/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:28:56 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/06 20:33:53 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "utils_bonus.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

/* Free & Error handler */
void	ft_error_handler(char *error, int signal, char *str, t_data *data);
void	ft_free_data(t_data *data);
void	ft_free_map(char **source);
void	ft_free_image(void **frames, t_data *data);
int     close_window(t_data *data, int mode);

/* Loadmap & Ensure Map */
void	ft_loadmap(char *pathname, t_data *data);
int		ft_open(char *pathname, t_data *data);
void	ft_floodfill(char **map, t_data *data, int x, int y);
char	*ft_strremove(char *str, t_data *data);
char	**ft_copymap(char **source, t_data *data);
void	ft_data_init(t_data *data);
void	ft_printmap(char **source);

/* Render */
void	background(t_data *data);
void	put_image(t_data *data, void *img, int column, int line);
void	put_move(t_data *data);

/* Animations */
void	player(t_data *data, int old_y, int old_x);
int		enemy(t_data *data);
void	collectibles(t_data *data);
void	shark(t_data *data);

/* Initiators */
void	all_init(t_data *data, char *path);
void	data_init(t_data *data);
void	background_init(t_data *data);
void	enemy_init(t_data *data);
void	player_init(t_data *data);
void	collectibles_init(t_data *data);
void	background_image_init(t_data *data);
void	collectibles_image_init(t_data *data);
void	enemy_image_init(t_data *data);
void	player_image_init(t_data *data);

#endif //SO_LONG_BONUS_H