/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:53:42 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 16:15:16 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		// count += write(1, "-", 1);
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

static void     ft_putstr(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

static void     ft_putnbr(int n)
{
    char c;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void            print_struct_write(t_flags *f)
{
    ft_putstr("minus : ");
    ft_putnbr(f->minus);
    write(1, "\n", 1);

    ft_putstr("zero : ");
    ft_putnbr(f->zero);
    write(1, "\n", 1);

    ft_putstr("dot : ");
    ft_putnbr(f->dot);
    write(1, "\n", 1);

    ft_putstr("width : ");
    ft_putnbr(f->width);
    write(1, "\n", 1);

    ft_putstr("precision : ");
    ft_putnbr(f->precision);
    write(1, "\n", 1);

    ft_putstr("hash : ");
    ft_putnbr(f->hash);
    write(1, "\n", 1);

    ft_putstr("space : ");
    ft_putnbr(f->space);
    write(1, "\n", 1);

    ft_putstr("plus : ");
    ft_putnbr(f->plus);
    write(1, "\n", 1);

    ft_putstr("specifier : ");
    if (f->specifier)
        write(1, &f->specifier, 1);
    else
        ft_putstr("(null)");
    write(1, "\n", 1);
}

// static int ft_print_tnum(t_number nbr, t_flags *fmt)
// {
// 	int count;
//
// 	count = 0;
//
// 	if ((fmt->zero) && !fmt->minus)
// 	{
// 		if (nbr.printsign || nbr.isneg)
// 			count += write(1, &nbr.sign, 1);
// 		while (count < nbr.width - nbr.digit_len)
// 			count += ft_print_npad(fmt, 1);
// 	}
// 	if (!fmt->zero && !fmt->minus)
// 	{
// 		while (count < nbr.width - nbr.digit_len - nbr.isneg)
// 			count += ft_print_npad(fmt, 1);
// 	}
// 	if ((fmt->zero) && nbr.isneg)
// 		count += ft_putnbr_len(-nbr.value);
// 	else
// 		count += ft_putnbr_len(nbr.value);
// 	if (fmt->minus)
// 	{
// 		while (count < nbr.width)
// 			count += ft_print_npad(fmt, 1);
// 	}
// 	return (count);
// }

static int ft_print_tnum(t_number nbr, t_flags *fmt)
{
    int count;
    int prec_zeros;
    int num_len;
    int has_sign;
    int is_empty_zero;
    int content_len;
    int padding;
    int zero_pad;

    count = 0;
    num_len = nbr.digit_len;
    has_sign = (nbr.printsign || nbr.isneg);
    
    is_empty_zero = (fmt->dot && fmt->precision == 0 && nbr.value == 0);
    if (is_empty_zero)
        num_len = 0;

    prec_zeros = 0;
    if (fmt->dot && fmt->precision > num_len)
        prec_zeros = fmt->precision - num_len;

    content_len = has_sign + prec_zeros + num_len;
    padding = (nbr.width > content_len) ? nbr.width - content_len : 0;

    zero_pad = fmt->zero && !fmt->minus && !fmt->dot;

    if (fmt->minus)
    {
        if (has_sign)
            count += write(1, &nbr.sign, 1);
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_len(nbr.value);
        while (count < nbr.width)
            count += write(1, " ", 1);
    }
    else if (zero_pad)
    {
        if (has_sign)
            count += write(1, &nbr.sign, 1);
        while (padding-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_len(nbr.value);
    }
    else
    {
        while (padding-- > 0)
            count += write(1, " ", 1);
        if (has_sign)
            count += write(1, &nbr.sign, 1);
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_len(nbr.value);
    }
    return (count);
}

int ft_handle_num(va_list args, t_flags *fmt)
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


int ft_print_nbr(va_list args, t_flags *fmt)
{
	return (ft_handle_num(args, fmt));
}
