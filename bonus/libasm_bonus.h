#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
} 				t_list;

extern t_list *ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin_list);

#endif
