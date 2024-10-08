/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:38:50 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/11 18:28:26 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

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

/* PIXEL */
# define PXL 32

/* Directions */
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3

/* Path background textures */
# define WALL_0 "./textures/background/wall_0.xpm"
# define WALL_1 "./textures/background/wall_1.xpm"
# define WALL_2 "./textures/background/wall_2.xpm"
# define EXIT "./textures/background/exit.xpm"
# define EMPTY "./textures/background/empty.xpm"
# define SHARK "./textures/background/shark.xpm"
# define COUNT "./textures/background/count_bar.xpm"

/* Path player textures */
# define PLAYER "./textures/player/player.xpm"
# define PLAYER_1 "./textures/player/player_exit.xpm"
# define PLAYER_2 "./textures/player/player_left.xpm"

/* Path enemy textures */
# define EB1 "./textures/enemy/eback1.xpm"
# define EF1 "./textures/enemy/efront1.xpm"
# define EL1 "./textures/enemy/eleft1.xpm"
# define ER1 "./textures/enemy/eright1.xpm"
# define BLL "./textures/enemy/ball.xpm"

/* Path animal textures */
# define CRAB0 "./textures/animals/crab0.xpm"
# define CRAB1 "./textures/animals/crab1.xpm"
# define CRAB2 "./textures/animals/crab2.xpm"
# define CRAB3 "./textures/animals/crab3.xpm"
# define FOX0 "./textures/animals/fox0.xpm"
# define FOX1 "./textures/animals/fox1.xpm"
# define FOX2 "./textures/animals/fox2.xpm"
# define FOX3 "./textures/animals/fox3.xpm"
# define CHK0 "./textures/animals/chk0.xpm"
# define CHK1 "./textures/animals/chk1.xpm"
# define CHK2 "./textures/animals/chk2.xpm"
# define CHK3 "./textures/animals/chk3.xpm"

typedef struct s_image
{
	int		len_f;
	int		pos_h;
	int		pos_w;
	int		dir;
	int		current_frame;
	int		frame_counter;
	int		bag;
	void	**fr;
}	t_image;

/* Struct for initial infor about map */
typedef struct s_data
{
	int		width;
	int		height;
	int		c;
	int		p;
	int		e;
	int		enemy_;
	int		ff_c;
	int		ff_e;
	char	**map;
	char	**new_map;
	void	*mlx;
	void	*win;
	int		movements;
	void	*img_m;
	time_t	move_time;
	t_image	*plr;
	t_image	*enm;
	t_image	*backg;
	t_image	*collect;
}	t_data;

#endif //UTILS_BONUS_H