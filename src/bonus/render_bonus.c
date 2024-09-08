/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:47:34 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/08 19:35:43 by joneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_data *data, void *img, int column, int line)
{
	int	x;
	int	y;

	x = column * PXL;
	y = line * PXL;
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

void	put_move(t_data *data)
{
	char	*count;
	char	*str;

	count = ft_itoa(data->movements);
	str = ft_strjoin("Move count:", count);
	put_image(data, data->backg->fr[6], 0, 0);
	put_image(data, data->backg->fr[6], 1, 0);
	put_image(data, data->backg->fr[6], 2, 0);
	mlx_string_put(data->mlx, data->win, 1, 16, 0xFFFFFF, str);
	free(count);
	free(str);
}

void	*load_image(t_data *data, char *path, int size)
{
	void	*image;

	image = mlx_xpm_file_to_image(data->mlx, path, &size, &size);
	if (!image)
	{
		// ft_error_handler(NULL, 0, NULL, data);
		// //mlx_destroy_window(data->mlx, data->win);
		// //mlx_destroy_display(data->mlx);
		// free(data->mlx);
		// free(data);
		close_window(data, 0);
		ft_printf("entrei aqui/n/n/n\n\n\n\n");
		exit(0);
	}
	return (image);
}
