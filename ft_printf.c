/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:39:52 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/09/26 15:12:22 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_letter(const char *format, va_list arg)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len = convert_arg_char(*format, arg);
	else if (*format == 's')
		len = convert_arg_str(arg);
	else if (*format == 'p')
		len = convert_argp_hex(arg);
	else if (*format == 'd')
		len = convert_arg_int (arg);
	else if (*format == 'i')
		len = convert_arg_int (arg);
	else if (*format == 'u')
		len = convert_arg_uns_int (arg);
	else if (*format == 'x')
		len = convert_arg_hex(*format, arg);
	else if (*format == 'X')
		len = convert_arg_hex(*format, arg);
	else if (*format == '%')
		len = convert_arg_char(*format, arg);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format++;
			len += check_letter (&format[i], arg);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
