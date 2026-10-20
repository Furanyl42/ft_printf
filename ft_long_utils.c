/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:17:25 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 15:24:38 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    ft_nbrlen_base(long n, int base_len)
{
    int    len;

    len = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        n /= base_len;
        len++;
    }
    return (len);
}

int    ft_putnbr_base_len(long n, char *base, int base_len)
{
    int    count;

    count = 0;
    if (n >= (long)base_len)
        count += ft_putnbr_base_len(n / base_len, base, base_len);
    count += write(1, &base[n % base_len], 1);
    return (count);
}
