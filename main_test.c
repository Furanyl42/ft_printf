/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:29:07 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/14 17:31:49 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	r;
	r = ft_printf("FT  -> Pos: [%d], Neg: [%i], Max: [%d], Min: [%d]\n", 42, -42, INT_MAX, INT_MIN);
	printf("count = %d\n", r);
	return (0);
}
