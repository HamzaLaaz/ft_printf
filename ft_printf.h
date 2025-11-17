/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaaz <hlaaz@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:49:52 by hlaaz             #+#    #+#             */
/*   Updated: 2025/11/12 10:53:02 by hlaaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	print_char(char c, int count);
int	print_string(char *s, int count);
int	print_number(int n, int count);
int	print_unsigned(unsigned int n, int count);
int	print_hex(unsigned int n, int uppercase, int count);

#endif
