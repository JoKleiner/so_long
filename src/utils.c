/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:25:20 by joklein           #+#    #+#             */
/*   Updated: 2025/01/03 12:20:43 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_win(t_data *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/Win.png");
	if (!texture)
		return (ft_printf("Error\nPng to texture went wrong"), 1);
	data->image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	if (!data->image)
		return (ft_printf("Error\nTexture to image went wrong"), 1);
	if (-1 == mlx_image_to_window(data->mlx, data->image, 0, 0))
		return (ft_printf("Error\nImage to window went wrong"), 1);
	return (0);
}

int	find_c(t_data *data)
{
	int	i;
	int	u;

	i = 0;
	while ((*data->map)[i])
	{
		u = 0;
		while ((*data->map)[i][u])
		{
			if ((*data->map)[i][u] == 'C')
				return (1);
			u++;
		}
		i++;
	}
	return (0);
}

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free((*map));
}

void	step_on_c(t_data *data)
{
	if (set_ground(data) == 1)
		mlx_close_window(data->mlx);
	set_hero(data);
	(*data->map)[data->y][data->x] = '0';
}

// void	c(void)
// {
// 	system("leaks so_long");
// }
