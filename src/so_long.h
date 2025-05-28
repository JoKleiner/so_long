/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:44:05 by joklein           #+#    #+#             */
/*   Updated: 2024/12/18 10:34:09 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*image_hero;
	int			width;
	int			height;
	char		***map;
	size_t		x;
	int			y;
	int			end;
}				t_data;

// Init game
int				main(int argc, char **argv);
int				init_game(t_data *data, int num_line, char **map);
int				count_lines_init_map(char ***map, char **argv);
int				init_map(char ***map, char **argv, int num_line);

// Map check
int				map_check(char ***map, int num_line, char **argv);
int				check_pec(int i, size_t u, char ***map, int num_line);
int				check_10pce(int i, int u, char ***map);
int				check_doable(char **argv, int num_line);
int				put_p(char **map2);
int				surround_check(int i, int u, char **map2);

// Start win, image
int				set_start_image(t_data *data, char ***map, int num_line);
int				set_ground(t_data *data);
int				set_image(t_data *data, char ***map, int num_line);

// Hero start, move
int				hero(t_data *data, char ***map);
int				set_hero(t_data *data);
void			hero_move(void *param);
int				hero_up_down(void *param, int moves);
int				hero_le_ri(void *param, int moves);

// Utils
int				find_c(t_data *data);
void			free_map(char ***map);
int				set_win(t_data *data);
void			step_on_c(t_data *data);
// void			c(void);

#endif
