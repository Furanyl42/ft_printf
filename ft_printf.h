/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:52:05 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/13 18:01:03 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format
{
	int	minus;
	int zero;
	int dot;
	int width;
	int precision;
	int hash;
	int space;
	int plus;
	char specifier;
}	t_format;

int	ft_printf(const char *format, ...);
