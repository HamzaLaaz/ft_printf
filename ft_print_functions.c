/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaaz <hlaaz@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:01:55 by hlaaz             #+#    #+#             */
/*   Updated: 2025/11/14 15:02:32 by hlaaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int count)
{
	write(1, &c, 1);
	return (count + 1);
}

int	print_string(char *s, int count)
{
	int	i;

	if (!s)
		return (print_string("(null)", count));
	i = 0;
	while (s[i])
	{
		count = print_char(s[i], count);
		i++;
	}
	return (count);
}

int	print_number(int n, int count)
{
	if (n == -2147483648)
		return (print_string("-2147483648", count));
	if (n < 0)
	{
		count = print_char('-', count);
		n = -n;
	}
	if (n > 9)
		count = print_number(n / 10, count);
	return (print_char((n % 10) + '0', count));
}

int	print_unsigned(unsigned int n, int count)
{
	if (n > 9)
		count = print_unsigned(n / 10, count);
	return (print_char((n % 10) + '0', count));
}

int	print_hex(unsigned int n, int uppercase, int count)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
		count = print_hex(n / 16, uppercase, count);
	return (print_char(base[n % 16], count));
}
