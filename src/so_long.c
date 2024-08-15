/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:27:35 by joneves-          #+#    #+#             */
/*   Updated: 2024/08/15 22:08:46 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

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


int mouse_hook(int keysym, int x, int y, t_vars *data)
{
	ft_printf("Press -> %d <-\n", keysym);
	ft_printf("x -> %d   y -> %d \n", x, y);
	
	if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
		free(data->win);
        exit(1);
    }
	if (keysym == 1) // Verifica se o botão esquerdo foi clicado
    {
        mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000); // Desenha um pixel vermelho na posição clicada
    }
	return (0);
}

int close_window(int keysym, t_vars *data)
{
	    mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
		free(data->win);
		exit(1);
		return (0);
}

void render_map(void *mlx, void *window, int **map, int map_width, int map_height)
{
    int cell_width = 80 / map_width;
    int cell_height = 80 / map_height;
    void *wall_texture = mlx_xpm_file_to_image(mlx, "/home/thecreator/so_long_42/src/textures/wall.xpm", &cell_width, &cell_height);
    void *collectable_texture = mlx_xpm_file_to_image(mlx, "/home/thecreator/so_long_42/src/textures/coletavel.xpm", &cell_width, &cell_height);
    void *player_texture = mlx_xpm_file_to_image(mlx, "/home/thecreator/so_long_42/src/textures/player.xpm", &cell_width, &cell_height);
    void *exit_texture = mlx_xpm_file_to_image(mlx, "/home/thecreator/so_long_42/src/textures/player.xpm", &cell_width, &cell_height);
    void *empty_texture = mlx_xpm_file_to_image(mlx, "/home/thecreator/so_long_42/src/textures/space.xpm", &cell_width, &cell_height);

    for (int linha = 0; linha < map_height; linha++) {
        for (int coluna = 0; coluna < map_width; coluna++) {
            int x = coluna * cell_width;
            int y = linha * cell_height;
            
            if (map[linha][coluna] == '1')
                mlx_put_image_to_window(mlx, window, wall_texture, x, y);
            else if (map[linha][coluna] == 'C')
                mlx_put_image_to_window(mlx, window, collectable_texture, x, y);
            else if (map[linha][coluna] == 'P')
                mlx_put_image_to_window(mlx, window, player_texture, x, y);
            else if (map[linha][coluna] == 'E')
                mlx_put_image_to_window(mlx, window, exit_texture, x, y);
            else
                mlx_put_image_to_window(mlx, window, empty_texture, x, y);
        }
    }
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		img_width;
	int		img_height;
	int **map;

	map = ft_loadmap(argv[1]);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
	mlx_key_hook(vars.win, mouse_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	render_map(vars.mlx, vars.win, map, 33, 5);
	// mlx_loop_hook(vars.mlx, render_map, &vars);
	mlx_loop(vars.mlx);
}
