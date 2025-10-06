#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
} 				t_list;

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);
extern t_list *ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin_list);

#endif
