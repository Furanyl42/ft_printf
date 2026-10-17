/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:52:05 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/16 16:54:55 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_format {
  int minus;
  int zero;
  int dot;
  int width;
  int precision;
  int hash;
  int space;
  int plus;
  char specifier;
} t_format;

typedef int (*t_func)(va_list, t_format *);

int ft_print_percent(va_list args, t_format *fmt);
int ft_print_char(va_list args, t_format *fmt);
int ft_print_str(va_list args, t_format *fmt);
int ft_print_nbr(va_list args, t_format *fmt);
int ft_print_unsigned(va_list args, t_format *fmt);
int ft_print_hex_lower(va_list args, t_format *fmt);
int ft_print_hex_upper(va_list args, t_format *fmt);
int ft_print_ptr(va_list args, t_format *fmt);
void ft_parse_formatter(char **format, t_format *fmt);
int ft_dispatch_formatter(va_list args, t_format *fmt);
int ft_print_npad(t_format *fmt, int n);
int ft_printf(char *format, ...);

#endif
