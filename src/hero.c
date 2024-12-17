/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:25:20 by joklein           #+#    #+#             */
/*   Updated: 2024/12/16 18:02:31 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hero_up_down(void *param, int moves)
{
	t_data	*data;

	data = param;
	if ((mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx,
				MLX_KEY_W)) && (*data->map)[data->x - 1][data->y] != '1')
	{
		data->x -= 1;
		data->image->instances[0].y -= 32;
		moves++;
		ft_printf("Moves = %i\n", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx,
				MLX_KEY_S)) && (*data->map)[data->x + 1][data->y] != '1')
	{
		data->x += 1;
		data->image->instances[0].y += 32;
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
				MLX_KEY_A)) && (*data->map)[data->x][data->y - 1] != '1')
	{
		data->y -= 1;
		data->image->instances[0].x -= 32;
		moves++;
		ft_printf("Moves = %i\n", moves);
	}
	if ((mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(data->mlx,
				MLX_KEY_D)) && (*data->map)[data->x][data->y + 1] != '1')
	{
		data->y += 1;
		data->image->instances[0].x += 32;
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
	if ((*data->map)[data->x][data->y] == 'C')
	{
		if (set_ground(data) == 1)
			return ;
		if (set_hero(data) == 1)
			return ;
		(*data->map)[data->x][data->y] = '0';
	}
	if ((*data->map)[data->x][data->y] == 'E')
	{
		if (find_c(data) != 1)
		{
			usleep(300000);
			mlx_close_window(data->mlx);
		}
	}
	moves = hero_up_down(param, moves);
	moves = hero_le_ri(param, moves);
	usleep(100000);
}

int	set_hero(t_data *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/Prisoner2.png");
	if (!texture)
		return (mlx_close_window(data->mlx), free(data), write(1, "Error\n", 6),
			1);
	data->image = mlx_texture_to_image(data->mlx, texture);
	if (!data->image)
		return (mlx_close_window(data->mlx), mlx_delete_texture(texture),
			free(data), write(1, "Error\n", 6), 1);
	if (-1 == mlx_image_to_window(data->mlx, data->image, data->y * 32, data->x
			* 32))
		return (mlx_close_window(data->mlx), free(data), write(1, "Error\n", 6),
			1);
	mlx_delete_texture(texture);
	return (0);
}

int	hero(t_data *data, char ***map)
{
	data->x = 0;
	while ((*map)[data->x])
	{
		data->y = 0;
		while (data->y < ft_strlen_n((*map)[0]))
		{
			if ((*map)[data->x][data->y] == 'P')
			{
				if (set_hero(data) == 1)
					return (1);
				return (0);
			}
			data->y++;
		}
		data->x++;
	}
	return (0);
}
