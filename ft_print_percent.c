/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:06:27 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 12:21:55 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(va_list args, t_format *fmt)
{
	int	count;
	int	width;

	(void)args;
	count = 0;
	width = fmt->width;
	if (width <= 0)
		width = 1;
	if (!fmt->minus && fmt->zero)
	{
		while (count < width - 1)
			count += write(1, "0", 1);
	}
	else if (!fmt->minus)
	{
		while (count < width - 1)
			count += write(1, " ", 1);
	}
	count += write(1, "%", 1);
	if (fmt->minus)
	{
		while (count < width)
			count += write(1, " ", 1);
	}
	return (count);
}
