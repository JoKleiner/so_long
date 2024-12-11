/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:50:33 by joklein           #+#    #+#             */
/*   Updated: 2024/10/23 15:09:03 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		case_p(size_t num);
int		case_u(unsigned int numunsign);
int		case_xx(unsigned int numunsign, char cha);
int		ft_printf(const char *arg, ...);
size_t	ft_strlen(const char *str);
long	ft_putstr(char *str);
int		ft_putstr_rev(char *str);
int		ft_putchar(char cha);
int		ft_putnbr(int num);

#endif
