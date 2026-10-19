/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:26:04 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/19 15:17:01 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_put_ptr_hex(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_put_ptr_hex(n / 16);
	count += write(1, &base[n % 16], 1);
	return (count);
}

static int	ft_print_nil(t_format *fmt)
{
	int	len;
	int	width;
	int	count;

	count = 0;
	len = 5;
	width = fmt->width;
	if (width < len)
		width = len;
	if (!fmt->minus)
		count += ft_print_npad(fmt, width - len);
	count += write(1, "(nil)", len);
	if (fmt->minus && count < width)
		count += ft_print_npad(fmt, width - count);
	return (count);
}

int	ft_print_ptr(va_list args, t_format *fmt)
{
	void			*ptr;
	unsigned long	addr;
	int				len;
	int				width;
	int				count;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_print_nil(fmt));
	addr = (unsigned long)ptr;
	len = ft_ptr_len(addr) + 2;
	width = fmt->width;
	if (width < len)
		width = len;
	count = 0;
	if (!fmt->minus)
		count += ft_print_npad(fmt, width - len);
	count += write(1, "0x", 2);
	count += ft_put_ptr_hex(addr);
	if (fmt->minus && count < width)
		count += ft_print_npad(fmt, width - count);
	return (count);
}
