/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:13:19 by joklein           #+#    #+#             */
/*   Updated: 2024/12/13 18:56:16 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	c(void)
{
	system("leaks so_long");
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

int	main(int argc, char **argv)
{
	char	**map;
	int		num_line;
	t_data	*data;

	if (argc != 2)
		return (write(1, "Error\n", 6), 1);
	num_line = count_lines_init_map(&map, argv);
	if (num_line == -1)
		return (write(1, "Error\n", 6), 1);
	if (map_check(&map, num_line, argv) == 1)
		return (free_map(&map), write(1, "Error\n", 6), 1);
	// atexit(c);
	data = malloc(sizeof(t_data));
	data->width = ft_strlen_n(map[0]) * 32;
	data->height = num_line * 32;
	data->mlx = mlx_init(data->width, data->height, "MLX Window", true);
	if (!data->mlx)
		return (free(data), write(1, "Error\n", 6), 1);
	if (set_ground(data->mlx, data) == 1)
		return (free(data), write(1, "Error\n", 6), 1);
	if (hero(data) == 1)
		return (1);
	mlx_loop_hook(data->mlx, hero_move, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	free_map(&map);
	return (0);
}

// system("leaks so_long");