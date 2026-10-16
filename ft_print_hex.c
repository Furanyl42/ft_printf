/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:49:51 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/16 16:57:13 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n);
int	ft_putnbr_hex(unsigned int n, int uppercase);

static int	ft_print_hex_base(va_list args, t_format *fmt, int uppercase)
{
	unsigned int	nbr;
	int				len;
	int				width;
	int				count;

	nbr = va_arg(args, unsigned int);
	len = ft_hex_len(nbr);
	width = fmt->width;
	if (width < len)
		width = len;
	count = 0;
	if (!fmt->minus)
	{
		while (count < width - len)
			count += ft_print_npad(fmt, 1);
	}
	count += ft_putnbr_hex(nbr, uppercase);
	if (fmt->minus)
	{
		while (count < width)
			count += ft_print_npad(fmt, 1);
	}
	return (count);
}

int	ft_print_hex_lower(va_list args, t_format *fmt)
{
	return (ft_print_hex_base(args, fmt, 0));
}

int	ft_print_hex_upper(va_list args, t_format *fmt)
{
	return (ft_print_hex_base(args, fmt, 1));
}
