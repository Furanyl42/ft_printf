/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:21:36 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 17:06:29 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
// --- TESTS POUR LES POINTEURS (%p) ---
    int ret_ft, ret_sys;
    int var = 42;
    void *ptr = &var;

    printf("--- 1. Tests de base et adresses classiques ---\n");
    
    // Pointeur standard
    ret_ft = ft_printf("FT  : [%p]\n", ptr);
    ret_sys = printf("SYS : [%p]\n", ptr);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    // Pointeur sur une fonction ou autre (ex: main)
    ret_ft = ft_printf("FT  : [%p] (main address)\n", (void *)&main);
    ret_sys = printf("SYS : [%p] (main address)\n", (void *)&main);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);


    printf("--- 2. Gestion de la largeur et alignement ---\n");

    // Largeur (padding à droite par défaut avec des espaces)
    ret_ft = ft_printf("FT  : [%25p] (width 25)\n", ptr);
    ret_sys = printf("SYS : [%25p] (width 25)\n", ptr);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    // Alignement à gauche avec largeur
    ret_ft = ft_printf("FT  : [%-25p] (width 25 + gauche)\n", ptr);
    ret_sys = printf("SYS : [%-25p] (width 25 + gauche)\n", ptr);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);


    printf("--- 3. Cas limites (Pointeur NULL) ---\n");

    // Pointeur NULL (Comportement standard glibc: affiche "(nil)" ou "0x0" selon les systèmes, souvent "(nil)" sur Linux)
    ret_ft = ft_printf("FT  : [%p] (null pointer)\n", (void *)NULL);
    ret_sys = printf("SYS : [%p] (null pointer)\n", (void *)NULL);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    // Pointeur NULL avec largeur
    ret_ft = ft_printf("FT  : [%20p] (null pointer + width)\n", (void *)NULL);
    ret_sys = printf("SYS : [%20p] (null pointer + width)\n", (void *)NULL);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);
}
