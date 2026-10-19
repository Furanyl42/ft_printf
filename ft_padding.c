/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:40:46 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/19 15:16:13 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_npad(t_format *fmt, int n)
{
	int		count;
	char	pad;

	if (fmt->zero && !fmt->minus)
		pad = '0';
	else
		pad = ' ';
	count = 0;
	while (count < n)
		count += write(1, &pad, 1);
	return (count);
}
