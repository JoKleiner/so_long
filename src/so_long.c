/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:13:19 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 10:18:01 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_win(t_data *data, int num_line, char **map)
{
	data->width = ft_strlen_n(map[0]) * 32;
	if (data->width > 2528)
		return (ft_printf("Error\nMap width to big"), 1);
	data->height = num_line * 32;
	if (data->height > 1312)
		return (ft_printf("Error\nMap height to big"), 1);
	data->mlx = mlx_init(data->width, data->height, "MLX Window", true);
	if (!data->mlx)
		return (ft_printf("Error\nmlx init went wrong"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		num_line;
	t_data	*data;

	if (argc != 2)
		return (ft_printf("Error\nInvalid arguments"), 1);
	num_line = count_lines_init_map(&map, argv);
	if (num_line == -1)
		return (1);
	if (map_check(&map, num_line, argv) == 1)
		return (free_map(&map), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (free_map(&map),
			ft_printf("Error\nSpace for data allocation went wrong"), 1);
	if (init_win(data, num_line, map) == 1)
		return (free(data), free_map(&map), 1);
	if (set_start_image(data, &map, num_line) == 1)
		return (mlx_close_window(data->mlx), free(data), free_map(&map), 1);
	if (hero(data, &map) == 1)
		return (mlx_close_window(data->mlx), free(data), free_map(&map), 1);
	data->map = &map;
	data->end = 0;
	mlx_loop_hook(data->mlx, hero_move, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	free_map(&map);
	return (0);
}

// atexit(c);
// system("leaks so_long");