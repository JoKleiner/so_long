/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:54:44 by joklein           #+#    #+#             */
/*   Updated: 2025/01/03 11:30:47 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_image(t_data *data, char ***map, int num_line)
{
	mlx_texture_t	*texture;

	if ((*map)[data->y][data->x] == 'P' || (*map)[data->y][data->x] == '0')
		texture = mlx_load_png("images/Ground.png");
	if ((*map)[data->y][data->x] == '1' && (data->y == 0 || data->y == num_line
			- 1 || data->x == 0 || data->x == ft_strlen_n((*map)[0]) - 1))
	{
		texture = mlx_load_png("images/Wall_out.png");
	}
	else if ((*map)[data->y][data->x] == '1')
		texture = mlx_load_png("images/Cell.png");
	if ((*map)[data->y][data->x] == 'E')
		texture = mlx_load_png("images/Exit.png");
	if ((*map)[data->y][data->x] == 'C')
		texture = mlx_load_png("images/Key.png");
	if (!texture)
		return (ft_printf("Error\nPng to texture went wrong"), 1);
	data->image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	if (!data->image)
		return (ft_printf("Error\nTexture to image went wrong"), 1);
	if (mlx_image_to_window(data->mlx, data->image, data->x * 32, data->y
			* 32) == -1)
		return (ft_printf("Error\nImage to window went wrong"), 1);
	return (0);
}

int	set_ground(t_data *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/Ground.png");
	if (!texture)
		return (ft_printf("Error\nPng to texture went wrong"), 1);
	data->image = mlx_texture_to_image(data->mlx, texture);
	if (!data->image)
		return (mlx_delete_texture(texture),
			ft_printf("Error\nTexture to image went wrong"), 1);
	if (mlx_image_to_window(data->mlx, data->image, data->x * 32, data->y
			* 32) == -1)
		return (mlx_delete_texture(texture),
			ft_printf("Error\nImage to window went wrong"), 1);
	return (mlx_delete_texture(texture), 0);
}

int	set_start_image(t_data *data, char ***map, int num_line)
{
	data->y = 0;
	while ((*map)[data->y])
	{
		data->x = 0;
		while (data->x < ft_strlen_n((*map)[0]))
		{
			if (set_ground(data) == 1)
				return (1);
			if (set_image(data, map, num_line) == 1)
				return (1);
			data->x++;
		}
		data->y++;
	}
	return (0);
}
