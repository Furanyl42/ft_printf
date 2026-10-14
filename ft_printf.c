/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:58:22 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 17:31:13 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <strings.h> // a changer par libft

int	ft_conversion(va_list args, t_format *fmt)
{
	static table funcs[128] = {0};
	static int	is_init = 0;

	if (!is_init)
	{
		funcs['c'] = ft_print_char;
		funcs['s'] = ft_print_str;
		funcs['p'] = ft_print_ptr;
		funcs['d'] = ft_print_nbr;
		funcs['i'] = ft_print_nbr;
		funcs['u'] = ft_print_unsigned;
		funcs['x'] = ft_print_hex_lower;
		funcs['X'] = ft_print_hex_upper;
		funcs['%'] = ft_print_percent;
		is_init = 1;
	}
	if (funcs[(int)fmt->specifier])
		return (funcs[(int)fmt->specifier](args, fmt));
	
	return (0);
}

int ft_printf(char *format, ...)
{
	va_list args;
	int	count;
	t_format fmt;
	int r;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;

			bzero(&fmt, sizeof(t_format));
			ft_parse_format((char **)&format, &fmt);
			r = ft_conversion(args, &fmt);
			if (r == -1)
			{
				va_end(args);
				return (-1);
			}
			count += r;
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
