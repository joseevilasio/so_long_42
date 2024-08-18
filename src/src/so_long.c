/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/18 15:58:19 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	mouse_hook(int keysym, int x, int y, t_vars *data)
// {
// 	ft_printf("Press -> %d <-\n", keysym);
// 	ft_printf("x -> %d   y -> %d \n", x, y);
	
// 	if (keysym == XK_Escape)
//     {
//         printf("The %d key (ESC) has been pressed\n\n", keysym);
//         mlx_destroy_window(data->mlx, data->window);
//         mlx_destroy_display(data->mlx);
//         free(data->mlx);
// 		free(data->window);
//         exit(1);
//     }
// 	if (keysym == 1) // Verifica se o botão esquerdo foi clicado
//     {
//         mlx_pixel_put(data->mlx, data->window, x, y, 0xFF0000); // Desenha um pixel vermelho na posição clicada
//     }
// 	return (0);
// }

// int	close_window(int keysym, t_vars *data)
// {
// 	mlx_destroy_window(data->mlx, data->window);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	free(data->window);
// 	exit(1);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_data	data;
	// t_vars	vars;

	if (argc == 2)
	{
		ft_loadmap(argv[1], &data); //considerar uma struct para receber o map e ter funcao init map
		// vars.mlx = mlx_init();		
		// vars.window = mlx_new_window(vars.mlx, (80*34), (80*6), "Hello world!");
		// mlx_key_hook(vars.window, mouse_hook, &vars);
		// mlx_mouse_hook(vars.window, mouse_hook, &vars);
		// ft_render(vars.mlx, vars.window, map, 34, 6);
		// // mlx_loop_hook(vars.mlx, render_map, &vars);
		// mlx_loop(vars.mlx);
		ft_error_handler(NULL, 0, NULL, &data);
	}
	else
		ft_error_handler(strerror(EINVAL), ERROR_ARGUMENTS, NULL, NULL);
	return (0);		
}
