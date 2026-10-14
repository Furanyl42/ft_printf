/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:29:07 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 16:50:49 by nide-wil         ###   ########.fr       */
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

static int test_ptr(t_format *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = ft_print_ptr(args, fmt);
	va_end(args);
	return (r);
}

int main(void)
{
	t_format fmt;
	int	r;
	int x;

	x = 69;

	fmt.width = 30;
	fmt.minus = 0;
	r = test_ptr(&fmt, &x);
	printf("\ncount = %d\n", r);
	print_sep();

	fmt.width = 0;
	fmt.minus = 0;
	r = test_ptr(&fmt, &x);
	printf("\ncount = %d\n", r);
	print_sep();

	fmt.width = 10;
	fmt.minus = 0;
	r = test_ptr(&fmt, &x);
	printf("\ncount = %d\n", r);
	print_sep();

	fmt.width = 10;
	fmt.minus = 0;
	r = test_ptr(&fmt, 0);
	printf("\ncount = %d\n", r);
	print_sep();
	return (0);
}
