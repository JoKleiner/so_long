/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:39:36 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 13:45:47 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_10pce(int i, int u, char ***map)
{
	if ((*map)[i][u] == 'C')
		return (0);
	if ((*map)[i][u] == 'P')
		return (0);
	if ((*map)[i][u] == 'E')
		return (0);
	if ((*map)[i][u] == '0')
		return (0);
	if ((*map)[i][u] == '1')
		return (0);
	return (1);
}

int	check_pec(int i, size_t u, char ***map, int num_line)
{
	static int	hero = 0;
	static int	exit = 0;
	static int	collec = 0;

	i = 0;
	while (i < num_line)
	{
		u = 0;
		while (u < ft_strlen_n((*map)[i]))
		{
			if ((*map)[i][u] == 'P')
				hero++;
			if ((*map)[i][u] == 'E')
				exit++;
			if ((*map)[i][u] == 'C')
				collec++;
			if (check_10pce(i, u, map) == 1)
				return (ft_printf("Error\nInvalide Map: Invalide char"), 1);
			u++;
		}
		i++;
	}
	if (hero != 1 || exit != 1 || collec == 0)
		return (ft_printf("Error\nInvalide Map: Number of PEC not correct"), 1);
	return (0);
}

int	map_check(char ***map, int num_line, char **argv)
{
	int		i;
	size_t	u;

	i = 0;
	while ((*map)[i])
	{
		if (ft_strlen_n((*map)[i]) != ft_strlen_n((*map)[0]))
			return (ft_printf("Error\nInvalide Map: Line length not equal"), 1);
		if ((*map)[i][0] != '1' || (*map)[i][ft_strlen_n((*map)[i]) - 1] != '1')
			return (ft_printf("Error\nMap not closed"), 1);
		i++;
	}
	u = 0;
	if (check_pec(i, u, map, num_line) == 1 || check_doable(argv,
			num_line) == 1)
		return (1);
	while ((*map)[0][u] != '\n')
	{
		if ((*map)[0][u] != '1' || (*map)[num_line - 1][u] != '1')
			return (1);
		u++;
	}
	return (0);
}
