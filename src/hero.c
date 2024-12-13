/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:25:20 by joklein           #+#    #+#             */
/*   Updated: 2024/12/13 18:45:43 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hero_move2(void *param, int moves)
{
	t_data	*data;

	data = param;
	if ((mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx,
				MLX_KEY_S)) && data->image->instances[0].y < data->height - 96)
	{
		data->image->instances[0].y += 32;
		moves++;
		printf("%i", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx,
				MLX_KEY_A)) && data->image->instances[0].x > 32)
	{
		data->image->instances[0].x -= 32;
		moves++;
		printf("%i", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(data->mlx,
				MLX_KEY_D)) && data->image->instances[0].x < data->width - 96)
	{
		data->image->instances[0].x += 32;
		moves++;
		printf("%i", moves);
	}
	return (moves);
}

void	hero_move(void *param)
{
	t_data		*data;
	static int	moves = 0;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if ((mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx,
				MLX_KEY_W)) && data->image->instances[0].y > 32)
	{
		data->image->instances[0].y -= 32;
		moves++;
		printf("%i", moves);
	}
	moves = hero_move2(param, moves);
	usleep(100000);
}

int	hero(t_data *data)
{
	mlx_texture_t	*thief_texture;

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
	return (0);
}
