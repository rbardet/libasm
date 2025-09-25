#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

void test_strlen() {
	const char *str1 = "Hello World!";

	printf("real func: %zu\n", strlen(str1));
	printf("mine: %zu\n", ft_strlen(str1));

	const char *str2 = "Lille OSC";

	printf("real func: %zu\n", strlen(str2));
	printf("mine: %zu\n", ft_strlen(str2));

	const char *str3 = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";

	printf("real func: %zu\n", strlen(str3));
	printf("mine: %zu\n", ft_strlen(str3));

	const char *str4 = "";

	printf("real func: %zu\n", strlen(str4));
	printf("mine: %zu\n", ft_strlen(str4));
}

void test_strcpy() {
	const char *str1 = "Hello World!";
	char *str1_1 = malloc(sizeof(char) * ft_strlen(str1));

	printf("real func: %s\n", strcpy(str1_1, str1));
	printf("mine: %s\n", strcpy(str1_1, str1));
	free(str1_1);

	const char *str2 = "Lille OSC";
	str1_1 = malloc(sizeof(char) * ft_strlen(str2));

	printf("real func: %s\n", strcpy(str1_1, str2));
	printf("mine: %s\n", strcpy(str1_1, str2));
	free(str1_1);

	const char *str3 = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";
	str1_1 = malloc(sizeof(char) * ft_strlen(str3));

	printf("real func: %s\n", strcpy(str1_1, str3));
	printf("mine: %s\n", strcpy(str1_1, str3));
	free(str1_1);

	const char *str4 = "";
	str1_1 = malloc(sizeof(char) * ft_strlen(str4));

	printf("real func: %s\n", strcpy(str1_1, str4));
	printf("mine: %s\n", strcpy(str1_1, str4));
	free(str1_1);
}

void test_strcmp() {
	char *str1 = "Hello World!";
	char *str1_1 = "Hello World!";

	printf("real func: %d\n", strcmp(str1, str1_1));
	printf("mine: %d\n", ft_strcmp(str1, str1_1));

	char *str2 = "Hello 1";
	char *str2_1 = "Hello World!";

	printf("real func: %d\n", strcmp(str2, str2_1));
	printf("mine: %d\n", ft_strcmp(str2, str2_1));
	
	char *str3 = "a";
	char *str3_1 = "c";
	printf("real func: %d\n", strcmp(str3, str3_1));
	printf("mine: %d\n", ft_strcmp(str3, str3_1));

	char *str4 = "f";
	char *str4_1 = "a";
	printf("real func: %d\n", strcmp(str4, str4_1));
	printf("mine: %d\n", ft_strcmp(str4, str4_1));

	char *str5 = "";
	char *str5_1 = "";
	printf("real func: %d\n", strcmp(str5, str5_1));
	printf("mine: %d\n", ft_strcmp(str5, str5_1));
}



int main(void) {
	printf("-----ft_strlen-----\n");
	test_strlen();
	printf("-----ft_strcpy-----\n");
	test_strcpy();
	printf("-----ft_strcmp-----\n");
	test_strcmp();
	printf("-----ft_write-----\n");
	return (0);
}

// 1er argument → rdi
// 2ème argument → rsi
// 3ème argument → rdx
// 4ème argument → rcx
// 5ème argument → r8
// 6ème argument → r9
