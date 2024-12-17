/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:09:53 by joklein           #+#    #+#             */
/*   Updated: 2024/12/17 11:19:42 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memcpy(void *dst, const void *src, size_t num);
size_t				ft_strlen(const char *str);
size_t				ft_strlen_n(const char *str);
char				*ft_strjoin(char const *str1, char const *str2);

#endif
