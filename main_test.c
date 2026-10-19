/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-wil <nide-wil@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:29:07 by nide-wil          #+#    #+#             */
/*   Updated: 2026/10/19 11:56:02 by nide-wil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>


int	main(void)
{
	char c = 'c';
	char *s = "string";
	int d = -42;
	unsigned int u = 42;

	printf("\n====================\n\n");
	printf("ft_printf: [BASIC]\n\n");
	ft_printf("%%c : %c\n", 'a');
	ft_printf("%%s : %s\n", "string");
	ft_printf("%%p : %p\n", &d);
	ft_printf("%%d : %d %d %d %d %d %d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%i : %i %i %i %i %i %i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%u : %u %u %u\n", 0, 42, INT_MAX);
	ft_printf("%%x : %x\n", d);
	ft_printf("%%X : %X\n", d);

	printf("\n====================\n\n");
	printf("printf: [BASIC]\n\n");
	printf("%%c : %c\n", 'a');
	printf("%%s : %s\n", "string");
	printf("%%p : %p\n", &d);
	printf("%%d : %d %d %d %d %d %d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%i : %i %i %i %i %i %i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%u : %u %u %u\n", 0, 42, INT_MAX);
	printf("%%x : %x\n", d);
	printf("%%X : %X\n", d);


	printf("\n====================\n\n");
	printf("ft_printf: [-5]\n\n");
	ft_printf("%%c : %-5c\n", 'a');
	ft_printf("%%s : %-5s\n", "string");
	ft_printf("%%p : %-5p\n", &d);
	ft_printf("%%d : %-5d %-5d %-5d %-5d %-5d %-5d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%i : %-5i %-5i %-5i %-5i %-5i %-5i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%u : %-5u %-5u %-5u\n", 0, 42, INT_MAX);
	ft_printf("%%x : %-5x\n", d);
	ft_printf("%%X : %-5X\n", d);


	printf("\n====================\n\n");
	printf("printf: [-5]\n\n");
	printf("%%c : %-5c\n", 'a');
	printf("%%s : %-5s\n", "string");
	printf("%%p : %-5p\n", &d);
	printf("%%d : %-5d %-5d %-5d %-5d %-5d %-5d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%i : %-5i %-5i %-5i %-5i %-5i %-5i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%u : %-5u %-5u %-5u\n", 0, 42, INT_MAX);
	printf("%%x : %-5x\n", d);
	printf("%%X : %-5X\n", d);



	printf("\n====================\n\n");
	ft_printf("ft_printf: [5]\n\n");
	ft_printf("%%c : %5c\n", 'a');
	ft_printf("%%s : %5s\n", "string");
	ft_printf("%%p : %5p\n", &d);
	ft_printf("%%d : %5d %5d %5d %5d %5d %5d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%i : %5i %5i %5i %5i %5i %5i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%u : %5u %5u %5u\n", 0, 42, INT_MAX);
	ft_printf("%%x : %5x\n", d);
	ft_printf("%%X : %5X\n", d);

	printf("\n====================\n\n");
	printf("printf: [5]\n\n");
	printf("%%c : %5c\n", 'a');
	printf("%%s : %5s\n", "string");
	printf("%%p : %5p\n", &d);
	printf("%%d : %5d %5d %5d %5d %5d %5d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%i : %5i %5i %5i %5i %5i %5i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%u : %5u %5u %5u\n", 0, 42, INT_MAX);
	printf("%%x : %5x\n", d);
	printf("%%X : %5X\n", d);

	printf("\n====================\n\n");
	ft_printf("ft_printf: [05]\n\n");
	ft_printf("%%d : %05d %05d %05d %05d %05d %05d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%i : %05i %05i %05i %05i %05i %05i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	ft_printf("%%u : %05u %05u %05u\n", 0, 42, INT_MAX);
	ft_printf("%%x : %05x\n", d);
	ft_printf("%%X : %05X\n", d);

	printf("\n====================\n\n");
	printf("printf: [05]\n\n");
	printf("%%d : %05d %05d %05d %05d %05d %05d\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%i : %05i %05i %05i %05i %05i %05i\n", -42, 42, 0, -0, INT_MAX, INT_MIN);
	printf("%%u : %05u %05u %05u\n", 0, 42, INT_MAX);
	printf("%%x : %05x\n", d);
	printf("%%X : %05X\n", d);


	printf("\n====================\n\n");
	printf("ft_printf: [-05]\n\n");
	ft_printf("%%d : %-05d %-05d\n", 42, -42);


	printf("\n====================\n\n");
	printf("printf: [-05]\n\n");
	printf("%%d : %-05d %-05d\n", 42, -42);



	ft_printf("\n\n");

	return (0);
}

// int main(void)
// {
// 	int ft_ret, orig_ret;
// 	int total = 0;
// 	int passed = 0;
//
// 	printf("========================================\n");
// 	printf("    BATTERIE DE TESTS COMPLÈTE FT_PRINTF\n");
// 	printf("========================================\n\n");
//
// 	// --- SECTION 1 : CHARACTÈRES (%c) ---
// 	printf("--- 1. Tests des Caractères (%%c) ---\n");
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%c]\n", 'a');
// 	orig_ret = printf("ORG : [%c]\n", 'a');
// 	if (ft_ret == orig_ret) { printf("-> [OK] Simple char\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%c]\n", 0); // Caractère nul '\0'
// 	orig_ret = printf("ORG : [%c]\n", 0);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Null char (\\0)\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- SECTION 2 : CHAÎNES DE CARACTÈRES (%s) ---
// 	printf("--- 2. Tests des Chaînes (%%s) ---\n");
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%s]\n", "Hello, 42!");
// 	orig_ret = printf("ORG : [%s]\n", "Hello, 42!");
// 	if (ft_ret == orig_ret) { printf("-> [OK] Standard string\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%s]\n", "");
// 	orig_ret = printf("ORG : [%s]\n", "");
// 	if (ft_ret == orig_ret) { printf("-> [OK] Empty string\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%s]\n", (char *)NULL);
// 	orig_ret = printf("ORG : [%s]\n", (char *)NULL);
// 	if (ft_ret == orig_ret) { printf("-> [OK] NULL string (doit afficher (null))\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- SECTION 3 : ENTIERS (%d / %i) ---
// 	printf("--- 3. Tests des Entiers (%%d / %%i) ---\n");
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%d] [%i]\n", 42, -42);
// 	orig_ret = printf("ORG : [%d] [%i]\n", 42, -42);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Positif et négatif\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%d] [%d]\n", INT_MAX, INT_MIN);
// 	orig_ret = printf("ORG : [%d] [%d]\n", INT_MAX, INT_MIN);
// 	if (ft_ret == orig_ret) { printf("-> [OK] INT_MAX et INT_MIN\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%d]\n", 0);
// 	orig_ret = printf("ORG : [%d]\n", 0);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Zéro\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- SECTION 4 : NON SIGNÉS (%u) ---
// 	printf("--- 4. Tests des Non Signés (%%u) ---\n");
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%u]\n", 42U);
// 	orig_ret = printf("ORG : [%u]\n", 42U);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Unsigned normal\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%u]\n", 4294967295U); // UINT_MAX
// 	orig_ret = printf("ORG : [%u]\n", 4294967295U);
// 	if (ft_ret == orig_ret) { printf("-> [OK] UINT_MAX\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- SECTION 5 : HEXADÉCIMAUX (%x / %X) ---
// 	printf("--- 5. Tests Hexadécimaux (%%x / %%X) ---\n");
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%x] [%X]\n", 255, 255);
// 	orig_ret = printf("ORG : [%x] [%X]\n", 255, 255);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Hex min/maj (255 -> ff / FF)\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%x]\n", 0);
// 	orig_ret = printf("ORG : [%x]\n", 0);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Hex zéro\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- SECTION 6 : POINTEURS (%p) ---
// 	printf("--- 6. Tests des Pointeurs (%%p) ---\n");
//
// 	int dummy = 42;
// 	total++;
// 	ft_ret = ft_printf("FT  : [%p]\n", &dummy);
// 	orig_ret = printf("ORG : [%p]\n", &dummy);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Pointeur valide\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%p]\n", (void *)NULL);
// 	orig_ret = printf("ORG : [%p]\n", (void *)NULL);
// 	if (ft_ret == orig_ret) { printf("-> [OK] Pointeur NULL (doit afficher (nil))\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- SECTION 7 : POURCENTAGE (%%) ---
// 	printf("---  7. Tests du Pourcentage (%%%%) ---\n");
//
// 	total++;
// 	ft_ret = ft_printf("FT  : [%%]\n");
// 	orig_ret = printf("ORG : [%%]\n");
// 	if (ft_ret == orig_ret) { printf("-> [OK] Pourcentage simple\n\n"); passed++; }
// 	else { printf("-> [KO] Attendu: %d, Obtenu: %d\n\n", orig_ret, ft_ret); }
//
//
// 	// --- BILAN FINAL ---
// 	printf("========================================\n");
// 	printf("         BILAN DES TESTS (%d/%d)        \n", passed, total);
// 	printf("========================================\n");
// 	if (passed == total)
// 		printf("🎉 Félicitations ! Tous les tests de retour ont réussi avec succès !\n");
// 	else
// 		printf("⚠️ Certains tests ont échoué. Vérifie les différences ci-dessus.\n");
//
// 	return (0);
// }
