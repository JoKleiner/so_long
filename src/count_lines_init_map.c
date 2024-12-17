/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines_init_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:00:13 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 10:15:10 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(char ***map, char **argv, int num_line)
{
	int	fd;

	(*map) = malloc(sizeof(char *) * (num_line + 1));
	if (!(*map))
		return (ft_printf("Error\nSpace allocation went wrong"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (free_map(map),
			ft_printf("Error\nMap initialization went wrong"), 1);
	(*map)[0] = get_next_line(fd);
	num_line = 0;
	while ((*map)[num_line])
	{
		num_line++;
		(*map)[num_line] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	count_lines_init_map(char ***map, char **argv)
{
	int		num_line;
	char	*str;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nMap initialization went wrong"), -1);
	str = get_next_line(fd);
	num_line = 0;
	while (str)
	{
		num_line++;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
	if (init_map(map, argv, num_line) == 1)
		return (-1);
	return (num_line);
}
