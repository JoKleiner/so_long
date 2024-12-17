/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:51:44 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 09:55:33 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	surround_check(int i, int u, char **map2)
{
	if (map2[i][u] == 'C' || map2[i][u] == '0' || map2[i][u] == 'E')
		if (map2[i - 1][u] == 'P' || map2[i + 1][u] == 'P' || map2[i][u
			- 1] == 'P' || map2[i][u + 1] == 'P')
			return (1);
	return (0);
}

int	put_p(char **map2)
{
	int	changes;
	int	i;
	int	u;

	changes = 0;
	i = 0;
	while (map2[i])
	{
		u = 0;
		while (map2[i][u])
		{
			if (surround_check(i, u, map2) == 1)
			{
				map2[i][u] = 'P';
				changes = 1;
			}
			u++;
		}
		i++;
	}
	return (changes);
}

int	check_doable(char **argv, int num_line)
{
	char	**map2;
	int		changes;
	int		i;
	int		u;

	if (init_map(&map2, argv, num_line) == -1)
		return (1);
	changes = 1;
	while (changes == 1)
		changes = put_p(map2);
	i = 0;
	while (map2[i])
	{
		u = 0;
		while (map2[i][u] != '\n' && map2[i][u])
		{
			if (map2[i][u] == 'C' || map2[i][u] == 'E')
				return (free_map(&map2), ft_printf("Error\nMap not doable"), 1);
			u++;
		}
		i++;
	}
	free_map(&map2);
	return (0);
}
