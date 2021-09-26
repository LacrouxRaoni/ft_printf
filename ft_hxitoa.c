/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hxitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:03:31 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/09/26 15:13:30 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hxnlen(unsigned long int n)
{
	int	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_itoa_hx(unsigned long int n, char *base)
{
	char	*str;
	int		n_digits;
	int		i;

	n_digits = ft_hxnlen(n);
	str = (char *)malloc((n_digits + 1) * sizeof(char));
	i = n_digits;
	if (i == 0)
		str[0] = '0';
	while (i > 0)
	{
		str[i - 1] = base[n % 16];
		n = n / 16;
		i--;
	}
	write (1, str, n_digits);
	free (str);
	return (n_digits);
}
