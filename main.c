#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);

void test_strlen() {
	const char str1[100] = "Hello World!";

	printf("%zu\n", strlen(str1));
	printf("%zu\n", ft_strlen(str1));

	const char str2[100] = "Lille OSC";

	printf("%zu\n", strlen(str2));
	printf("%zu\n", ft_strlen(str2));

	const char str3[10000] = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";

	printf("%zu\n", strlen(str3));
	printf("%zu\n", ft_strlen(str3));

	const char str4[10000] = "";

	printf("%zu\n", strlen(str4));
	printf("%zu\n", ft_strlen(str4));
}

void test_strcpy() {
	const char str1[100] = "Hello World!";
	char *str1_1 = malloc(sizeof(char *) * (sizeof(str1)));

	str1_1 = strcpy(str1_1, str1);
	printf("%s\n", str1_1);
	str1_1 = ft_strcpy(str1_1, str1);
	printf("%s\n", str1_1);

	const char str2[100] = "Lille OSC";

	str1_1 = strcpy(str1_1, str2);
	printf("%s\n", str1_1);
	str1_1 = ft_strcpy(str1_1, str2);
	printf("%s\n", str1_1);

	const char str3[10000] = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";

	str1_1 = strcpy(str1_1, str3);
	printf("%s\n", str1_1);
	str1_1 = ft_strcpy(str1_1, str3);
	printf("%s\n", str1_1);

	const char str4[10000] = "";

	str1_1 = strcpy(str1_1, str4);
	printf("%s\n", str1_1);
	str1_1 = ft_strcpy(str1_1, str4);
	printf("%s\n", str1_1);
}

int main(void) {
	printf("-----ft_strlen-----\n");
	test_strlen();
	printf("-----ft_strcpy-----\n");
	test_strcpy();
	return (0);
}

// 1er argument → rdi
// 2ème argument → rsi
// 3ème argument → rdx
// 4ème argument → rcx
// 5ème argument → r8
// 6ème argument → r9
