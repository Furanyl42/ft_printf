/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:49:51 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 16:34:48 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_hex_left(unsigned int nbr, t_flags *fmt, int uppercase,
				int has_prefix);
int			ft_print_hex_zero(unsigned int nbr, t_flags *fmt, int uppercase,
				int has_prefix);
int			ft_print_hex_right(unsigned int nbr, t_flags *fmt, int uppercase,
				int has_prefix);

int	ft_putnbr_hex(unsigned int n, int uppercase)
{
	int			count;
	const char	*base;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	count += write(1, &base[n % 16], 1);
	return (count);
}

static int	ft_print_hex_common(va_list args, t_flags *fmt, int uppercase)
{
	unsigned int	nbr;
	int				has_prefix;
	int				zero_pad;

	nbr = va_arg(args, unsigned int);
	has_prefix = 0;
	if (fmt->hash && nbr != 0)
		has_prefix = 2;
	zero_pad = 0;
	if (fmt->zero && !fmt->minus && !fmt->dot)
		zero_pad = 1;
	if (fmt->minus)
		return (ft_print_hex_left(nbr, fmt, uppercase, has_prefix));
	if (zero_pad)
		return (ft_print_hex_zero(nbr, fmt, uppercase, has_prefix));
	return (ft_print_hex_right(nbr, fmt, uppercase, has_prefix));
}

int	ft_print_hex_lower(va_list args, t_flags *fmt)
{
	return (ft_print_hex_common(args, fmt, 0));
}

int	ft_print_hex_upper(va_list args, t_flags *fmt)
{
	return (ft_print_hex_common(args, fmt, 1));
}
