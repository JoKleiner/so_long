/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:25:20 by joklein           #+#    #+#             */
/*   Updated: 2025/01/03 13:03:55 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hero_up_down(void *param, int moves)
{
	t_data	*data;

	data = param;
	if ((mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx,
				MLX_KEY_W)) && (*data->map)[data->y - 1][data->x] != '1')
	{
		data->y -= 1;
		data->image_hero->instances[0].y -= 32;
		if ((*data->map)[data->y][data->x] == 'C')
			step_on_c(data);
		moves++;
		ft_printf("Moves = %i\n", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx,
				MLX_KEY_S)) && (*data->map)[data->y + 1][data->x] != '1')
	{
		data->y += 1;
		data->image_hero->instances[0].y += 32;
		if ((*data->map)[data->y][data->x] == 'C')
			step_on_c(data);
		moves++;
		ft_printf("Moves = %i\n", moves);
	}
	return (moves);
}

int	hero_le_ri(void *param, int moves)
{
	t_data	*data;

	data = param;
	if ((mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx,
				MLX_KEY_A)) && (*data->map)[data->y][data->x - 1] != '1')
	{
		data->x -= 1;
		data->image_hero->instances[0].x -= 32;
		if ((*data->map)[data->y][data->x] == 'C')
			step_on_c(data);
		moves++;
		ft_printf("Moves = %i\n", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(data->mlx,
				MLX_KEY_D)) && (*data->map)[data->y][data->x + 1] != '1')
	{
		data->x += 1;
		data->image_hero->instances[0].x += 32;
		if ((*data->map)[data->y][data->x] == 'C')
			step_on_c(data);
		moves++;
		ft_printf("Moves = %i\n", moves);
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
	if ((*data->map)[data->y][data->x] == 'E')
	{
		if (find_c(data) != 1)
		{
			ft_printf("You escaped!\n");
			mlx_close_window(data->mlx);
			usleep(1000000);
		}
	}
	moves = hero_up_down(param, moves);
	moves = hero_le_ri(param, moves);
	usleep(10000);
}

int	set_hero(t_data *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/Prisoner2.png");
	if (!texture)
		return (ft_printf("Error\nPng to texture went wrong"), 1);
	data->image_hero = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	if (!data->image_hero)
		return (ft_printf("Error\nTexture to image went wrong"), 1);
	if (-1 == mlx_image_to_window(data->mlx, data->image_hero, data->x * 32,
			data->y * 32))
		return (ft_printf("Error\nImage to window went wrong"), 1);
	return (0);
}

int	hero(t_data *data, char ***map)
{
	data->y = 0;
	while ((*map)[data->y])
	{
		data->x = 0;
		while (data->x < ft_strlen_n((*map)[0]))
		{
			if ((*map)[data->y][data->x] == 'P')
			{
				if (set_hero(data) == 1)
					return (1);
				return (0);
			}
			data->x++;
		}
		data->y++;
	}
	return (0);
}
