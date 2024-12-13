/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:38:08 by joklein           #+#    #+#             */
/*   Updated: 2024/12/13 17:29:40 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	strlen;

	strlen = 0;
	while (str[strlen] != '\0')
		strlen++;
	return (strlen);
}

size_t	ft_strlen_n(const char *str)
{
	size_t	strlen;

	strlen = 0;
	while (str[strlen] != '\0' && str[strlen] != '\n')
		strlen++;
	return (strlen);
}
