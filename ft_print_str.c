/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:17:03 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 15:26:23 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_strnlen(char *s, int max)
{
	int i;
	
	i = 0;
	while (s[i] && i < max)
		i++;
	return (i);
}
int	ft_print_str(va_list args, t_format *fmt)
{
	char *s;
	int len;
	int width;
	int count;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";

	len = ft_strnlen(s, fmt->precision);
	width = fmt->width;
	count = 0;

	if (!fmt->minus)
	{
		while (count < width - len)
			count += write(1, " ", 1);
	}
	count += write(1, s, len);

	if (fmt->minus)
	{
		while (count < width)
			count += write(1, " ", 1);
	}
	return (count);
}
