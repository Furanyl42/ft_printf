/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:17:03 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 15:41:06 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int    ft_strnlen(char *s, int max)
{
    int    i;

    i = 0;
    while (s[i] && i < max)
        i++;
    return (i);
}

int    ft_print_str(va_list args, t_flags *fmt)
{
    char    *s;
    int     is_null;
    int     len;
    int     padding;
    int     count;

    s = va_arg(args, char *);
    is_null = 0;
    if (!s)
    {
        s = "(null)";
        is_null = 1;
    }

    if (fmt->dot)
    {
        if (is_null && fmt->precision < 6)
            len = 0;
        else
            len = ft_strnlen(s, fmt->precision);
    }
    else
    {
        len = 0;
        while (s[len])
            len++;
    }

    padding = (fmt->width > len) ? fmt->width - len : 0;
    count = 0;

    if (!fmt->minus)
    {
        while (padding-- > 0)
            count += write(1, " ", 1);
    }

    count += write(1, s, len);

    if (fmt->minus)
    {
        while (padding-- > 0)
            count += write(1, " ", 1);
    }

    return (count);
}



/*
#include "ft_printf.h"

static int	ft_strnlen(char *s, int max)
{
	int	i;

	i = 0;
	while (s[i] && i < max)
		i++;
	return (i);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_str(va_list args, t_flags *fmt)
{
	char	*s;
	int		len;
	int		count;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	if (fmt->dot)
		len = ft_strnlen(s, fmt->precision);
	else
		len = ft_strlen(s);
	count = 0;
	if (!fmt->minus && fmt->width > len)
		count += ft_print_npad(fmt, fmt->width - len);
	count += write(1, s, len);
	if (fmt->minus && count < fmt->width)
		count += ft_print_npad(fmt, fmt->width - count);
	return (count);
}*/
