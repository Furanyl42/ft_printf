/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:32:33 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 16:15:39 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int    ft_unsigned_len(unsigned int n)
{
    int    len;

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

static int    ft_putnbr_unsigned(unsigned int n)
{
    int    count;

    count = 0;
    if (n > 9)
        count += ft_putnbr_unsigned(n / 10);
    count += write(1, &"0123456789"[n % 10], 1);
    return (count);
}

int    ft_print_unsigned(va_list args, t_flags *fmt)
{
    unsigned int    nbr;
    int             count;
    int             prec_zeros;
    int             num_len;
    int             is_empty_zero;
    int             content_len;
    int             padding;
    int             zero_pad;

    nbr = va_arg(args, unsigned int);
    num_len = ft_unsigned_len(nbr);

    // Cas particulier : valeur 0 avec précision 0 -> n'affiche rien
    is_empty_zero = (fmt->dot && fmt->precision == 0 && nbr == 0);
    if (is_empty_zero)
        num_len = 0;

    // Calcul des zéros de précision
    prec_zeros = 0;
    if (fmt->dot && fmt->precision > num_len)
        prec_zeros = fmt->precision - num_len;

    // Taille totale du contenu (zéros de précision + chiffres)
    content_len = prec_zeros + num_len;
    padding = (fmt->width > content_len) ? fmt->width - content_len : 0;

    // Le flag '0' est ignoré si une précision est présente ou si le flag '-' est actif
    zero_pad = fmt->zero && !fmt->minus && !fmt->dot;

    count = 0;
    // CAS 1 : Alignement à gauche (flag '-')
    if (fmt->minus)
    {
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_unsigned(nbr);
        while (count < fmt->width)
            count += write(1, " ", 1);
    }
    // CAS 2 : Remplissage par zéros (flag '0')
    else if (zero_pad)
    {
        while (padding-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_unsigned(nbr);
    }
    // CAS 3 : Remplissage par espaces (par défaut à droite)
    else
    {
        while (padding-- > 0)
            count += write(1, " ", 1);
        while (prec_zeros-- > 0)
            count += write(1, "0", 1);
        if (!is_empty_zero)
            count += ft_putnbr_unsigned(nbr);
    }
    return (count);
}

