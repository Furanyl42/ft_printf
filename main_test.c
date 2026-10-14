/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:29:07 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 15:13:25 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	print_sep()
{
	write(1, "\n--------------------\n", 22);
}

static int test_char(t_format *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = ft_print_char(args, fmt);
	va_end(args);
	return (r);
}

static int test_str(t_format *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = ft_print_str(args, fmt);
	va_end(args);
	return (r);
}

static int test_nbr(t_format *fmt, ...)
{
	va_list args;
	int r;

	va_start(args, fmt);
	r = ft_print_nbr(args, fmt);
	va_end(args);
	return (r);
}

int main(void)
{
	t_format fmt;
	int	r;

	fmt.width = 0;
	fmt.minus = 0;
	r = test_nbr(&fmt, 666);
	printf("\ncount = %d\n", r);
	print_sep();

	r = test_nbr(&fmt, -9);
	printf("\ncount = %d\n", r);
	print_sep();
	
	r = test_nbr(&fmt, 0);
	printf("\ncount = %d\n", r);
	print_sep();

	r = test_nbr(&fmt, 0);
	printf("\ncount = %d\n", r);
	print_sep();


	r = test_nbr(&fmt, -2147483648);
	printf("\ncount = %d\n", r);
	print_sep();

	r = test_nbr(&fmt, -42);
	printf("\ncount = %d\n", r);
	print_sep();


	return (0);
}
