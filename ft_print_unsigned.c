/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:32:33 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 15:39:09 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_unsigned_len(unsigned int n)
{
	int len;
	len = 0;

	if (n == 0)
		return (1);

	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int ft_putnbr_unsigned(unsigned int n)
{
	int count;
	
	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int ft_print_unsigned(va_list args, t_format *fmt)
{
	unsigned int nbr;
	int len;
	int width;
	int count;

	nbr = va_arg(args, unsigned int);
	len = ft_unsigned_len(nbr);
	width = fmt->width;
	if (width < len)
		width = len;
	count = 0;

	if (!fmt->minus)
	{
		while (count < width - len)
			count += write(1, " ", 1);
	}

	count += ft_putnbr_unsigned(nbr);

	if (fmt->minus)
	{
		while (count < width)
			count += write(1, " ", 1);
	}

	return (count);
}
