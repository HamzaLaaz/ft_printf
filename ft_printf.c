/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaaz <hlaaz@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:53:45 by hlaaz             #+#    #+#             */
/*   Updated: 2025/11/14 22:08:34 by hlaaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_addr(unsigned long n, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		count = print_addr(n / 16, count);
	return (print_char(base[n % 16], count));
}

static int	print_pointer(void *ptr, int count)
{
	unsigned long	adr;

	if (!ptr)
		return (print_string("(nil)", count));
	adr = (unsigned long)ptr;
	count = print_string("0x", count);
	return (print_addr(adr, count));
}

static int	format_specifier(char c, va_list args, int count)
{
	if (c == 'c')
		return (print_char(va_arg(args, int), count));
	if (c == 's')
		return (print_string(va_arg(args, char *), count));
	if (c == 'p')
		return (print_pointer(va_arg(args, void *), count));
	if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int), count));
	if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int), count));
	if (c == 'x')
		return (print_hex(va_arg(args, unsigned int), 0, count));
	if (c == 'X')
		return (print_hex(va_arg(args, unsigned int), 1, count));
	if (c == '%')
		return (print_char('%', count));
	return (print_char(c, count));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			count = format_specifier(format[i], args, count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
