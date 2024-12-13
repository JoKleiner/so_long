/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:54:44 by joklein           #+#    #+#             */
/*   Updated: 2024/12/13 18:54:56 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_ground(mlx_t *mlx_window, t_data *data)
{
	mlx_texture_t	*ground_texture;
	int				y_coord;
	int				x_coord;

	ground_texture = mlx_load_png("images/Ground.png");
	if (!ground_texture)
		return (mlx_close_window(mlx_window), write(1, "Error\n", 6), 1);
	data->image = mlx_texture_to_image(mlx_window, ground_texture);
	if (!data->image)
		return (mlx_close_window(mlx_window),
			mlx_delete_texture(ground_texture), write(1, "Error\n", 6), 1);
	y_coord = 0;
	while (y_coord < data->height)
	{
		x_coord = 0;
		while (x_coord < data->width)
		{
			if (mlx_image_to_window(mlx_window, data->image, x_coord,
					y_coord) == -1)
				return (mlx_delete_texture(ground_texture),
					mlx_close_window(mlx_window), write(1, "Error\n", 6), 1);
			x_coord = x_coord + 32;
		}
		y_coord = y_coord + 32;
	}
	return (mlx_delete_texture(ground_texture), 0);
}
