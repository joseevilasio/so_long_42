/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:38:50 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/05 22:11:18 by joneves-         ###   ########.fr       */
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
# define WALL_0 "./textures/wall/wall_00.xpm"
# define WALL_1 "./textures/wall/wall_1.xpm"
# define WALL_2 "./textures/wall/wall_2.xpm"
# define EXIT "./textures/exit.xpm"
# define EMPTY "./textures/empty.xpm"
# define SHARK "./textures/shark/sharkleft.xpm"

# define COLL "./textures/coll.xpm"
# define PLAYER "./textures/player.xpm"
# define PLAYER_1 "./textures/player_exit.xpm"
# define PLAYER_2 "./textures/player_left.xpm"

/* Path enemy textures */
# define EB0 "./textures/enemy/eback0.xpm"
# define EB1 "./textures/enemy/eback1.xpm"
# define EB2 "./textures/enemy/eback2.xpm"
# define EF0 "./textures/enemy/efront0.xpm"
# define EF1 "./textures/enemy/efront1.xpm"
# define EF2 "./textures/enemy/efront2.xpm"
# define EL0 "./textures/enemy/eleft0.xpm"
# define EL1 "./textures/enemy/eleft1.xpm"
# define EL2 "./textures/enemy/eleft2.xpm"
# define ER0 "./textures/enemy/eright0.xpm"
# define ER1 "./textures/enemy/eright1.xpm"
# define ER2 "./textures/enemy/eright2.xpm"
# define BLL "./textures/enemy/ball.xpm"

/* Path crab textures */
# define CRAB0 "./textures/crab/crab0.xpm"
# define CRAB1 "./textures/crab/crab1.xpm"
# define CRAB2 "./textures/crab/crab2.xpm"
# define CRAB3 "./textures/crab/crab3.xpm"

typedef struct s_image
{
	int		len_f;
	int		pos_h;
	int		pos_w;
	int		current_frame;
	int		frame_counter;
	int		bag;
	void	**frames;
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
	time_t	move_time;
	t_image	*player;
	t_image	*enemy;
	t_image	*background;
	t_image	*collectibles;
}	t_data;

#endif //UTILS_BONUS_H