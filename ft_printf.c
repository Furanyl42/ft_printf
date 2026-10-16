/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:58:22 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/16 17:04:58 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_conversion(va_list args, t_format *fmt)
{
	static t_func	funcs[128] = {0};
	static int		is_init = 0;

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

static int	ft_process_specifier(char **format, va_list args)
{
	t_format	fmt;

	ft_bzero(&fmt, sizeof(t_format));
	ft_parse_format(format, &fmt);
	return (ft_conversion(args, &fmt));
}

static int	ft_print_format_spec(char **format, va_list args, int *count)
{
	int	r;

	(*format)++;
	if (!**format)
		return (0);
	r = ft_process_specifier(format, args);
	if (r == -1)
		return (-1);
	*count += r;
	return (1);
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_print_format_spec(&format, args, &count) == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			count += write(1, format, 1);
		if (!*format)
			break ;
		format++;
	}
	va_end(args);
	return (count);
}
