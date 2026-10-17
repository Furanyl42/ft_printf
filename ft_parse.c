/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:14:20 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/16 15:58:51 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_format(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->dot = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->hash = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->specifier = '\0';
}

static void	ft_parse_flags(char **format, t_format *fmt)
{
	while (**format && (**format == '-' || **format == '0' || **format == '#'
			|| **format == ' ' || **format == '+'))
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '+')
			fmt->plus = 1;
		(*format)++;
	}
}

static void	ft_parse_num_and_prec(char **format, t_format *fmt)
{
	while (**format >= '0' && **format <= '9')
	{
		fmt->width = (fmt->width * 10) + (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		fmt->dot = 1;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			fmt->precision = (fmt->precision * 10) + (**format - '0');
			(*format)++;
		}
	}
}

void	ft_parse_formatter(char **format, t_format *fmt)
{
	ft_init_format(fmt);
	ft_parse_flags(format, fmt);
	ft_parse_num_and_prec(format, fmt);
	if (**format)
		fmt->specifier = **format;
}
