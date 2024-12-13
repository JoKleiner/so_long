/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:44:05 by joklein           #+#    #+#             */
/*   Updated: 2024/12/13 18:40:18 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
}				t_data;

int				set_ground(mlx_t *mlx_window, t_data *data);
void			free_map(char ***map);

char			*get_next_line(int fd);
int				ft_printf(const char *arg, ...);
size_t			ft_strlen_n(const char *str);

int				map_check(char ***map, int num_line, char **argv);
int				check_pec(int i, size_t u, char ***map, int num_line);
int				check_10PCE(int i, int u, char ***map);
int				check_doable(char **argv, int num_line);
int				put_p(char **map2);
int				surround_check(int i, int u, char **map2);
int				count_lines_init_map(char ***map, char **argv);
int				init_map(char ***map, char **argv, int num_line);

int				hero(t_data *data);
void			hero_move(void *param);
int				hero_move2(void *param, int moves);

#endif
