/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joneves- <joneves-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:47:34 by joneves-          #+#    #+#             */
/*   Updated: 2024/09/06 20:35:45 by joneves-         ###   ########.fr       */
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
	char	*s;
	char	*font;

	font = "-misc-fixed-bold-r-normal--18-120-100-100-c-90-iso8859-9";
	count = ft_itoa(data->movements);
	s = ft_strjoin("Move count: ", count);
	mlx_put_image_to_window(data->mlx, data->win, data->img_m, 150, 20);
	mlx_set_font(data->mlx, data->win, font);
	mlx_string_put(data->mlx, data->win, 20, 20, 0xFFFFFF, s);
	free(count);
	free(s);
}
