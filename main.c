#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

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
	char *str1_1 = malloc(sizeof(char) * ft_strlen(str1) + 1);

	printf("real func: %s\n", strcpy(str1_1, str1));
	printf("mine: %s\n", strcpy(str1_1, str1));
	free(str1_1);

	const char *str2 = "Lille OSC";
	str1_1 = malloc(sizeof(char) * ft_strlen(str2) + 1);

	printf("real func: %s\n", strcpy(str1_1, str2) + 1);
	printf("mine: %s\n", strcpy(str1_1, str2));
	free(str1_1);

	const char *str3 = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";
	str1_1 = malloc(sizeof(char) * ft_strlen(str3) + 1);

	printf("real func: %s\n", strcpy(str1_1, str3));
	printf("mine: %s\n", strcpy(str1_1, str3));
	free(str1_1);

	const char *str4 = "";
	str1_1 = malloc(sizeof(char) * ft_strlen(str4) + 1);

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

void test_write() {
	int len = 0;
	const char *str1 = "test\n";

	len = write(1, str1, ft_strlen(str1));
	printf("\nreal func: %d\n", len);
	len = ft_write(1, str1, ft_strlen(str1));
	printf("\nmine: %d\n", len);

	errno = 0;
	len = write(1, str1, 3);
	printf("\nreal func: %d\n", len);
	printf("errno :%d\n", errno);
	errno = 0;
	len = ft_write(1, str1, 3);
	printf("\nmine: %d\n", len);
	printf("errno :%d\n", errno);

	const char *str2 = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";
	errno = 0;
	len = write(1, str2, ft_strlen(str2));
	printf("\nreal func: %d\n", len);
	printf("errno :%d\n", errno);
	errno = 0;
	len = ft_write(1, str2, ft_strlen(str2));
	printf("\nmine: %d\n", len);
	printf("errno :%d\n", errno);

	int fd = open("wrong_file.txt", O_CREAT | O_RDONLY, 0000);

	const char *real = "real\n";
	const char *mine = "mine\n";

	errno = 0;
	len = write(fd, real, ft_strlen(real));
	printf("\nreal func: in wrong file %d\n", len);
	printf("errno :%d\n", errno);
	errno = 0;
	len = ft_write(fd, mine, ft_strlen(mine));
	printf("\nmine: in wrong file %d\n", len);
	printf("errno :%d\n", errno);

	close(fd);

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);

	errno = 0;
	len = write(fd, real, ft_strlen(real));
	printf("\nreal func: in real file %d\n", len);
	printf("errno :%d\n", errno);
	errno = 0;
	len = ft_write(fd, mine, ft_strlen(mine));
	printf("\nmine: in real file %d\n", len);
	printf("errno :%d\n", errno);

	close(fd);
	errno = 0;
	len = write(45, real, ft_strlen(real));
	printf("\nreal func: in wrong fd %d\n", len);
	printf("errno :%d\n", errno);
	errno = 0;
	len = ft_write(45, mine, ft_strlen(mine));
	printf("\nmine: in wrong fd %d\n", len);
	printf("errno :%d\n", errno);
}

void test_read() {

	int fd = 0;
	fd = open("test.txt", O_RDWR, 0777);

	char buff[256];
	errno = 0;
	int len = read(fd, buff, sizeof(buff) - 1);
	if (len >= 0) {
		buff[len] = '\0';
	}
	printf("\nreal func: in real file :\n%d %s\n", len, buff);
	printf("errno :%d\n", errno);
	close(fd);
	char buff2[256];
	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	errno = 0;
	len = ft_read(fd, buff2, sizeof(buff2) - 1);
	if (len >= 0) {
		buff2[len] = '\0';
	}
	printf("\nmine: in real file: \n%d %s\n", len, buff2);
	printf("errno :%d\n", errno);
	close(fd);
	char buff3[256];
	fd = open("wrong_file.txt", O_RDWR, 0000);
	errno = 0;
	len = read(fd, buff3, sizeof(buff3) - 1);
	buff3[0] = '\0';
	printf("\nreal func: in wrong file :\n%d %s\n", len, buff3);
	printf("errno :%d\n", errno);
	close(fd);
	char buff4[256];
	fd = open("wrong_file.txt", O_RDWR, 0000);
	errno = 0;
	len = ft_read(fd, buff4, sizeof(buff4) - 1);
	buff4[0] = '\0';
	printf("\nmine: in wrong file: \n%d %s\n", len, buff4);
	printf("errno :%d\n", errno);
	close(fd);
}

void test_strdup() {
	char *str1 = "Hello World!";

	char *str2 = NULL;
	errno = 0;
	str2 = strdup(str1);
	printf("real function: %s\n", str2);
	printf("errno: %d\n", errno);
	free(str2);

	char *str3 = NULL;
	errno = 0;
	str3 = ft_strdup(str1);
	printf("mine: %s\n", str3);
	printf("errno: %d\n", errno);
	free(str3);

	char *str4 = "Le club est né de la fusion des deux clubs professionnels de la ville, l'Olympique lillois et le Sporting Club fivois, situés dans deux quartiers lillois différents, qui avaient participé aux sept premières éditions du championnat de France professionnel avant l'arrêt de la compétition à cause de la Seconde Guerre mondiale. D'abord appelé Stade lillois, le club prend dès novembre 1944 le nom de Lille Olympique Sporting Club, qui rappelle ceux des deux clubs d'origine. Abrégé en Lille OSC, il donne lieu à l'acronyme LOSC, qui s'impose pour former le nom courant du club, avec mention redondante du nom de la ville : LOSC Lille.";

	char *str5 = NULL;
	errno = 0;
	str5 = ft_strdup(str4);
	printf("real function: %s\n", str5);
	printf("errno: %d\n", errno);
	free(str5);

	char *str6 = NULL;
	errno = 0;
	str6 = ft_strdup(str4);
	printf("mine: %s\n", str6);
	printf("errno: %d\n", errno);
	free(str6);
}

int main(void) {
	printf("-----ft_strlen-----\n");
	test_strlen();
	printf("-----ft_strcpy-----\n");
	test_strcpy();
	printf("-----ft_strcmp-----\n");
	test_strcmp();
	printf("-----ft_write-----\n");
	test_write();
	printf("-----ft_read-----\n");
	test_read();
	printf("-----ft_strdup-----\n");
	test_strdup();
	return (0);
}

// 1er argument rdi
// 2eme argument rsi
// 3eme argument rdx
// 4eme argument rcx
// 5eme argument r8
// 6eme argument r9
