/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/11 21:30:13 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		ft_loadmap(argv[1]);
// 		ft_printf("> %s < executando... \n\n", argv[1]);
		
// 		void	*mlx;
// 		mlx = NULL;
// 		mlx = mlx_init();
// 	}
// 	else
// 		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, 1, NULL);
// 	return (0);
// }




typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 200, 500, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, _close, &vars);
	mlx_loop(vars.mlx);
}


