/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:41:00 by joklein           #+#    #+#             */
/*   Updated: 2024/10/23 15:06:26 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_for_xx(unsigned int numunsign, char *buffer, char cha)
{
	int		i;

	i = 0;
	if (numunsign == 0)
	{
		buffer[i++] = '0';
		return (i);
	}
	while (numunsign != 0)
	{
		if (cha == 'x')
			buffer[i++] = HEX_LOW[numunsign % 16];
		if (cha == 'X')
			buffer[i++] = HEX_UP[numunsign % 16];
		numunsign = numunsign / 16;
	}
	buffer[i] = '\0';
	return (i);
}

int	case_xx(unsigned int numunsign, char cha)
{
	char	buffer[17];
	int		num_ret;

	if (numunsign == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	num_ret = hex_for_xx(numunsign, buffer, cha);
	if (ft_putstr_rev(buffer) == -1)
		return (-1);
	return (num_ret);
}
