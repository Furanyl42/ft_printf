/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:17:03 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/16 17:00:48 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_print_spaces(int n)
{
	int	count;

	count = 0;
	while (count < n)
		count += write(1, " ", 1);
	return (count);
}

int	ft_print_str(va_list args, t_format *fmt)
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
		count += ft_print_npad(fmt,fmt->width - len);
	count += write(1, s, len);
	if (fmt->minus && count < fmt->width)
		count += ft_print_npad(fmt,fmt->width - count);
	return (count);
}
