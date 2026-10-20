/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:49:51 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 16:15:56 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n);
int	ft_putnbr_hex(unsigned int n, int uppercase);

// Fonction commune partagée par %x et %X
static int    ft_print_hex_common(va_list args, t_flags *fmt, int uppercase)
{
    unsigned int    nbr;
    int             count;
    int             prec_zeros;
    int             num_len;
    int             is_empty_zero;
    int             has_prefix;
    int             content_len;
    int             padding;
    int             zero_pad;

    nbr = va_arg(args, unsigned int);
    num_len = ft_hex_len(nbr);

    is_empty_zero = (fmt->dot && fmt->precision == 0 && nbr == 0);
    if (is_empty_zero)
        num_len = 0;

    has_prefix = (fmt->hash && nbr != 0 ? 2 : 0);

    prec_zeros = 0;
    if (fmt->dot && fmt->precision > num_len)
        prec_zeros = fmt->precision - num_len;

    content_len = has_prefix + prec_zeros + num_len;
    padding = (fmt->width > content_len) ? fmt->width - content_len : 0;
    zero_pad = fmt->zero && !fmt->minus && !fmt->dot;

    count = 0;
    if (fmt->minus)
    {
        if (has_prefix)
            count += write(1, uppercase ? "0X" : "0x", 2);
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_hex(nbr, uppercase);
        while (count < fmt->width)
            count += write(1, " ", 1);
    }
    else if (zero_pad)
    {
        if (has_prefix)
            count += write(1, uppercase ? "0X" : "0x", 2);
        while (padding-- > 0)
            count += write(1, "0", 1);
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_hex(nbr, uppercase);
    }
    else
    {
        while (padding-- > 0)
            count += write(1, " ", 1);
        if (has_prefix)
            count += write(1, uppercase ? "0X" : "0x", 2);
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_hex(nbr, uppercase);
    }
    return (count);
}

// Les deux fonctions appelées par ton dispatch
int    ft_print_hex_lower(va_list args, t_flags *fmt)
{
    return (ft_print_hex_common(args, fmt, 0));
}

int    ft_print_hex_upper(va_list args, t_flags *fmt)
{
    return (ft_print_hex_common(args, fmt, 1));
}

