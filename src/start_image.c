/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:54:44 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 14:03:11 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_image(t_data *data, char ***map, int num_line)
{
	mlx_texture_t	*texture;

	if ((*map)[data->x][data->y] == 'P' || (*map)[data->x][data->y] == '0')
		texture = mlx_load_png("images/Ground.png");
	if ((*map)[data->x][data->y] == '1' && (data->x == 0 || data->x == num_line
			- 1 || data->y == 0 || data->y == ft_strlen_n((*map)[0]) - 1))
	{
		texture = mlx_load_png("images/Wall_out.png");
	}
	else if ((*map)[data->x][data->y] == '1')
		texture = mlx_load_png("images/Cell.png");
	if ((*map)[data->x][data->y] == 'E')
		texture = mlx_load_png("images/Exit.png");
	if ((*map)[data->x][data->y] == 'C')
		texture = mlx_load_png("images/Key.png");
	if (!texture)
		return (ft_printf("Error\nPng to texture went wrong"), 1);
	data->image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	if (!data->image)
		return (ft_printf("Error\nTexture to image went wrong"), 1);
	if (-1 == mlx_image_to_window(data->mlx, data->image, data->y * 32, data->x
			* 32))
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
	if (-1 == mlx_image_to_window(data->mlx, data->image, data->y * 32, data->x
			* 32))
		return (mlx_delete_texture(texture),
			ft_printf("Error\nImage to window went wrong"), 1);
	return (mlx_delete_texture(texture), 0);
}

int	set_start_image(t_data *data, char ***map, int num_line)
{
	data->x = 0;
	while ((*map)[data->x])
	{
		data->y = 0;
		while (data->y < ft_strlen_n((*map)[0]))
		{
			if (set_ground(data) == 1)
				return (1);
			if (set_image(data, map, num_line) == 1)
				return (1);
			data->y++;
		}
		data->x++;
	}
	return (0);
}
