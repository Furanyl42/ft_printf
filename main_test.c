/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:21:36 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/20 13:43:58 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_ft;
    int ret_sys;

    printf("==================================================\n");
    printf("   TESTS COMBINÉS : Flags (-), (0), (.) et Nombres \n");
    printf("==================================================\n\n");

    // --- 1. INTERACTIONS DE BASE (Largeur vs Alignement vs Flag 0) ---
    printf("--- 1. Largeur et drapeaux de base ---\n");
    ret_ft = ft_printf("FT  : [%8d]\n", 42);
    ret_sys = printf("SYS : [%8d]\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%-8d] (alignement gauche)\n", 42);
    ret_sys = printf("SYS : [%-8d] (alignement gauche)\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%08d] (flag zero)\n", 42);
    ret_sys = printf("SYS : [%08d] (flag zero)\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%08d] (negatif + zero)\n", -42);
    ret_sys = printf("SYS : [%08d] (negatif + zero)\n", -42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);


    // --- 2. PRÉCISION ET COMBINAISONS ---
    printf("--- 2. Précision et Largeur + Précision ---\n");
    ret_ft = ft_printf("FT  : [%.5d]\n", 42);
    ret_sys = printf("SYS : [%.5d]\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%10.5d]\n", 42);
    ret_sys = printf("SYS : [%10.5d]\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%-10.5d] (gauche + precision)\n", 42);
    ret_sys = printf("SYS : [%-10.5d] (gauche + precision)\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%10.5d] (negatif)\n", -42);
    ret_sys = printf("SYS : [%10.5d] (negatif)\n", -42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%-10.5d] (negatif + gauche)\n", -42);
    ret_sys = printf("SYS : [%-10.5d] (negatif + gauche)\n", -42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);


    // --- 3. LES CONFLITS DE DRAPEAUX (Priorités) ---
    // Règle C : Si une précision est présente, le flag '0' doit être ignoré.
    // Règle C : Si le flag '-' est présent, le flag '0' doit être ignoré.
    printf("--- 3. Conflits de drapeaux (0 ignoré) ---\n");
    ret_ft = ft_printf("FT  : [%010.5d] (flag 0 + precision -> 0 ignore)\n", 42);
    ret_sys = printf("SYS : [%010.5d] (flag 0 + precision -> 0 ignore)\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%-08d] (flag 0 + flag - -> 0 ignore)\n", 42);
    ret_sys = printf("SYS : [%-08d] (flag 0 + flag - -> 0 ignore)\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);


    // --- 4. LE CAS PARTICULIER DE LA PRÉCISION NULLE ---
    printf("--- 4. Zéro et précision nulle ---\n");
    ret_ft = ft_printf("FT  : [%.d] | [%.0d]\n", 0, 0);
    ret_sys = printf("SYS : [%.d] | [%.0d]\n", 0, 0);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%5.d] | [%5.0d]\n", 0, 0);
    ret_sys = printf("SYS : [%5.d] | [%5.0d]\n", 0, 0);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);


    // --- 5. APPLICATION AUX AUTRES CONVERSIONS NUMÉRIQUES (u, x, X) ---
    printf("--- 5. Application sur u, x, X ---\n");
    ret_ft = ft_printf("FT  : [%08x] (hex)\n", 255);
    ret_sys = printf("SYS : [%08x] (hex)\n", 255);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%-10.4X] (hex + prec + gauche)\n", 255);
    ret_sys = printf("SYS : [%-10.4X] (hex + prec + gauche)\n", 255);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    ret_ft = ft_printf("FT  : [%010.4u] (unsigned + prec + zero)\n", 42);
    ret_sys = printf("SYS : [%010.4u] (unsigned + prec + zero)\n", 42);
    printf("Ret -> FT: %d | SYS: %d\n\n", ret_ft, ret_sys);

    return (0);
}
