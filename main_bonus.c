#include "bonus/libasm_bonus.h"

int main(void) {
	t_list *list = NULL;
	char *test = "1";
	char *test2 = "2";
	char *test3 = "3";
	char *test4 = "4";
	ft_list_push_front(&list, test);
	ft_list_push_front(&list, test2);
	ft_list_push_front(&list, test3);
	ft_list_push_front(&list, test4);
	printf("nb of element in list: %d\n", ft_list_size(list));
	t_list *list2 = NULL;
	while (list) {
		printf("%s\n", (char *)list->data);
		list2 = list;
		list = list->next;
		free(list2);
	}
}
