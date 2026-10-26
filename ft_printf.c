/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:58:22 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/26 11:00:20 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_dispatch_formatter(va_list args, t_flags *fmt)
{
	if (fmt->specifier == 'c')
		return (ft_print_char(args, fmt));
	if (fmt->specifier == 's')
		return (ft_print_str(args, fmt));
	if (fmt->specifier == 'p')
		return (ft_print_ptr(args, fmt));
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
		return (ft_print_nbr(args, fmt));
	if (fmt->specifier == 'u')
		return (ft_print_unsigned(args, fmt));
	if (fmt->specifier == 'x')
		return (ft_print_hex_lower(args, fmt));
	if (fmt->specifier == 'X')
		return (ft_print_hex_upper(args, fmt));
	if (fmt->specifier == '%')
		return (ft_print_percent(args, fmt));
	return (0);
}

static int	ft_parse_and_dispatch(const char **format, va_list args)
{
	t_flags	fmt;

	ft_bzero(&fmt, sizeof(t_flags));
	ft_parse_format(format, &fmt);
	return (ft_dispatch_formatter(args, &fmt));
}

static int	ft_handle_directive(const char **format, va_list args, int *count)
{
	int	r;

	(*format)++;
	if (!**format)
		return (0);
	r = ft_parse_and_dispatch(format, args);
	if (r == -1)
		return (-1);
	*count += r;
	return (1);
}

int	ft_printf(const char *format, ...)
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
			if (ft_handle_directive(&format, args, &count) == -1)
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
