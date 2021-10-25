/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:44:18 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/10/25 16:16:59 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

char	*ft_usg_itoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		check_letter(const char *format, va_list arg);
int		convert_arg_char(const char format, va_list arg);
int		convert_arg_str(va_list arg);
int		convert_arg_int(va_list arg);
int		convert_arg_uns_int(va_list arg);
int		convert_argp_hex(va_list arg);
int		convert_arg_hex(const char format, va_list arg);
int		ft_itoa_hx(unsigned long int n, char *base);

#endif