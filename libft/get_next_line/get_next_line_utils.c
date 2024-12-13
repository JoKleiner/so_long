/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:05:01 by joklein           #+#    #+#             */
/*   Updated: 2024/12/12 15:00:36 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	free_str(char **str)
{
	if (str && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}
