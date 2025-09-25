NAME = libasm.a

SOURCES = ft_strlen.s

OBJECTS = $(SOURCES:.s=.o)

all: ${NAME}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
