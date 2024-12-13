/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:28:34 by joklein           #+#    #+#             */
/*   Updated: 2024/12/12 14:59:40 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t		i;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	while (i < num)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}

// void	*ft_memcpy(void *dst, const void *src, size_t num)
// {
// 	size_t		i;
// 	char		*dstptr;
// 	const char	*srcptr;

// 	dstptr = (char *)dst;
// 	srcptr = (const char *)src;
// 	if (dst == 0 && src == 0)
// 		return (NULL);
// 	i = 0;
// 	while (i < num)
// 	{
// 		dstptr[i] = srcptr[i];
// 		i++;
// 	}
// 	return (dst);
// }
