/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:53:42 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/15 12:19:26 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr_len(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_len(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int	ft_print_nbr(va_list args, t_format *fmt)
{
	long	nbr;
	int		len;
	int		width;
	int		count;

	nbr = va_arg(args, int);
	len = ft_nbrlen(nbr);
	width = fmt->width;
	if (width < len)
		width = len;
	count = 0;
	if (!fmt->minus)
	{
		while (count < width - len)
			count += write(1, " ", 1);
	}
	count += ft_putnbr_len(nbr);
	if (fmt->minus)
	{
		while (count < width)
			count += write(1, " ", 1);
	}
	return (count);
}
