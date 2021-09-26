/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdiu%.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:41:48 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/09/26 15:16:27 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_arg_char(const char format, va_list arg)
{
	int		len;
	char	c;

	len = 1;
	if (format == 'c')
	{	
		c = va_arg(arg, int);
		write (1, &c, 1);
	}
	else if (format == '%')
	{
		c = '%';
		write (1, &c, 1);
	}
	return (len);
}

int	convert_arg_str(va_list arg)
{
	int		len;
	char	*str;

	str = va_arg (arg, char *);
	if (str == NULL)
	{	
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

int	convert_arg_int(va_list arg)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg (arg, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	write (1, str, len);
	free (str);
	return (len);
}

int	convert_arg_uns_int(va_list arg)
{
	int				len;
	unsigned int	nb;
	char			*str;

	nb = va_arg(arg, unsigned int);
	str = ft_usg_itoa(nb);
	len = ft_strlen(str);
	write(1, str, len);
	free (str);
	return (len);
}
