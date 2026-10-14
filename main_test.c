/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:29:07 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 16:17:10 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

void	print_sep()
{
	write(1, "\n--------------------\n", 22);
}

static int test_hex(int (*f)(va_list, t_format *), t_format *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = f(args, fmt);
	va_end(args);
	return (r);
}

int main(void)
{
	t_format fmt;
	int	r;

	fmt.width = 30;
	fmt.minus = 0;
	r = test_hex(ft_print_hex_lower,&fmt, 255U);
	printf("\ncount = %d\n", r);
	print_sep();

	fmt.width = 0;
	fmt.minus = 0;
	r = test_hex(ft_print_hex_upper,&fmt, 255U);
	printf("\ncount = %d\n", r);
	print_sep();

	fmt.width = 10;
	fmt.minus = 0;
	r = test_hex(ft_print_hex_lower,&fmt, 12344U);
	printf("\ncount = %d\n", r);
	print_sep();

	fmt.width = 10;
	fmt.minus = 1;
	r = test_hex(ft_print_hex_lower,&fmt, 0U);
	printf("\ncount = %d\n", r);
	print_sep();
	return (0);
}
