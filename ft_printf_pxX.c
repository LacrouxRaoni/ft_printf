/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:09:55 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/09/26 15:14:17 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_argp_hex(va_list arg)
{
	int					len;
	unsigned long int	nb;

	len = 0;
	nb = va_arg (arg, unsigned long int);
	write (1, "0x", 2);
	len = ft_itoa_hx(nb, "0123456789abcdef");
	len += 2;
	return (len);
}

int	convert_arg_hex(const char format, va_list arg)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = va_arg (arg, unsigned int);
	if (format == 'x')
	{
		len = ft_itoa_hx(nb, "0123456789abcdef");
	}
	else if (format == 'X')
	{
		len = ft_itoa_hx(nb, "0123456789ABCDEF");
	}
	return (len);
}
