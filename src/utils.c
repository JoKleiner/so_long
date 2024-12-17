/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:25:20 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 11:10:40 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	close_func(t_data *data, char **map)
{
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	free_map(&map);
}

// void	c(void)
// {
// 	system("leaks so_long");
// }
