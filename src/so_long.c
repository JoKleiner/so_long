/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:13:19 by joklein           #+#    #+#             */
/*   Updated: 2024/12/12 12:40:54 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	ft_hook(void *param)
{
	t_data		*data;
	static int	moves = 0;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if ((mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx,
				MLX_KEY_W)) && data->image->instances[0].y > 30)
	{
		data->image->instances[0].y -= 30;
		moves++;
		printf("%i", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx,
				MLX_KEY_S)) && data->image->instances[0].y < data->height - 60)
	{
		data->image->instances[0].y += 30;
		moves++;
		printf("%i", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx,
				MLX_KEY_A)) && data->image->instances[0].x > 30)
	{
		data->image->instances[0].x -= 30;
		moves++;
		printf("%i", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(data->mlx,
				MLX_KEY_D)) && data->image->instances[0].x < data->width - 60)
	{
		data->image->instances[0].x += 30;
		moves++;
		printf("%i", moves);
	}
	usleep(100000);
}

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
			x_coord = x_coord + 30;
		}
		y_coord = y_coord + 30;
	}
	return (mlx_delete_texture(ground_texture), 0);
}

void	c(void)
{
	system("leaks so_long");
}

int	main(void)
{
	mlx_texture_t	*thief_texture;
	t_data			*data;
	int				height;
	int				width;

	// atexit(c);
	width = 450;
	height = 300;
	data = malloc(sizeof(t_data));
	data->width = width;
	data->height = height;
	data->mlx = mlx_init(data->width, data->height, "MLX Window", true);
	if (!data->mlx)
		return (free(data), write(1, "Error\n", 6), 1);
	if (set_ground(data->mlx, data) == 1)
		return (free(data), write(1, "Error\n", 6), 1);
	thief_texture = mlx_load_png("images/Thief.png");
	if (!thief_texture)
	{
		mlx_close_window(data->mlx);
		return (free(data), write(1, "Error\n", 6), 1);
	}
	data->image = mlx_texture_to_image(data->mlx, thief_texture);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		mlx_delete_texture(thief_texture);
		return (free(data), write(1, "Error\n", 6), 1);
	}
	if (mlx_image_to_window(data->mlx, data->image, 30, 30) == -1)
	{
		mlx_close_window(data->mlx);
		return (free(data), write(1, "Error\n", 6), 1);
	}
	mlx_delete_texture(thief_texture);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	return (0);
}

// system("leaks so_long");