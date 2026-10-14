/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:58:22 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 12:42:52 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"



int    ft_print_char(va_list args, t_format *fmt);
int    ft_print_str(va_list args, t_format *fmt);
int    ft_print_ptr(va_list args, t_format *fmt);
int    ft_print_nbr(va_list args, t_format *fmt);
int    ft_print_unsigned(va_list args, t_format *fmt);
int    ft_print_hex_low(va_list args, t_format *fmt);
int    ft_print_hex_up(va_list args, t_format *fmt);
int    ft_print_percent(va_list args, t_format *fmt);
int	ft_conversion(t_format *fmt, va_list args)
{
	static t_conv_func funcs[128] = {0};
	static int	is_init = 0;

	if (!is_init)
	{
		funcs['c'] = ft_print_char;
		funcs['s'] = ft_print_str;
		funcs['p'] = ft_print_ptr;
		funcs['d'] = ft_print_nbr;
		funcs['i'] = ft_print_nbr; // %d et %i font la même chose
		funcs['u'] = ft_print_unsigned;
		funcs['x'] = ft_print_hex_low;
		funcs['X'] = ft_print_hex_up;
		funcs['%'] = ft_print_percent;
	}
	if (funcs[(int)fmt->specifier])
		return (funcs[(int)fmt->specifier](args, fmt));
	
	return (0);
}

