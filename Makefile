NAME = libasm.a

SOURCES = ft_strlen.s ft_strcpy.s ft_strcmp.s \
	ft_write.s ft_read.s ft_strdup.s \
	ft_list_push_front.s

OBJECTS = $(SOURCES:.s=.o)

all: ${NAME}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME} a.out

re: fclean all

.PHONY: all clean fclean re
