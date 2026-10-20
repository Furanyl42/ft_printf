/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:53:42 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 13:43:53 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_number
{
	char sign;
	int isneg;
	int printsign;
	long value;
	int digit_len;
	int width;
}	t_number;

// static int	ft_nbrlen(long n)
// {
// 	int	len;
//
// 	len = 0;
// 	if (n <= 0)
// 	{
// 		len++;
// 		n = -n;
// 	}
// 	while (n > 0)
// 	{
// 		n /= 10;
// 	 	len++;
// 	}
// 	return (len);
// }

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

static int ft_digitlen(long n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int ft_print_tnum(t_number nbr, t_format *fmt)
{
	int count;

	count = 0;
	if ((fmt->zero || fmt->dot) && !fmt->minus)
	{
		if (nbr.printsign || nbr.isneg)
			count += write(1, &nbr.sign, 1);
		while (count < nbr.width - nbr.digit_len)
			count += ft_print_npad(fmt, 1);
	}
	if (!fmt->zero && !fmt->minus)
	{
		while (count < nbr.width - nbr.digit_len - nbr.isneg)
			count += ft_print_npad(fmt, 1);
	}
	if (fmt->zero && nbr.isneg)
		count += ft_putnbr_len(-nbr.value);
	else
		count += ft_putnbr_len(nbr.value);
	if (fmt->minus)
	{
		while (count < nbr.width)
			count += ft_print_npad(fmt, 1);
	}
	return (count);
}

int ft_handle_num(va_list args, t_format *fmt)
{
	t_number nbr;

	nbr.value = va_arg(args, int);
	if (nbr.value < 0)
	{
		nbr.sign = '-';
		nbr.isneg = 1;
	}
	else
	{
		nbr.sign = '+';
		nbr.isneg = 0;
	}
	if (fmt->plus)
		nbr.printsign = 1;
	else
		nbr.printsign = 0;
	nbr.digit_len = ft_digitlen(nbr.value);
	nbr.width = fmt->width;
	
	if ((nbr.printsign || nbr.sign == '-') && nbr.width < nbr.digit_len + 1)
		nbr.width = nbr.digit_len;
	if (!nbr.printsign && nbr.sign == '+' && nbr.width < nbr.digit_len)
		nbr.width = nbr.digit_len;
	return (ft_print_tnum(nbr, fmt));
}


int ft_print_nbr(va_list args, t_format *fmt)
{
	return (ft_handle_num(args, fmt));
}

// int	ft_print_nbr(va_list args, t_format *fmt)
// {
// 	long	nbr;
// 	int		len;
// 	int		width;
// 	int		count;
//
// 	nbr = va_arg(args, int);
// 	len = ft_nbrlen(nbr);
// 	width = fmt->width;
// 	if (width < len)
// 		width = len;
// 	count = 0;
// 	if (!fmt->minus)
// 	{
// 		while (count < width - len)
// 			count += ft_print_npad(fmt, 1);
// 	}
// 	count += ft_putnbr_len(nbr);
// 	if (fmt->minus)
// 	{
// 		while (count < width)
// 			count += ft_print_npad(fmt, 1);
// 	}
// 	return (count);
// }
