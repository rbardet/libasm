NAME = libasm.a
MAIN = main.c
EXEC = a.out

FILE = test.txt
WRONG_FILE = wrong_file.txt

SOURCES = ft_strlen.s ft_strcpy.s ft_strcmp.s \
	ft_write.s ft_read.s ft_strdup.s \
	ft_list_push_front.s ft_list_size.s

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

ASM = nasm
AFLAGS = -f elf64

OBJECTS = $(SOURCES:.s=.o)

all: ${NAME} ${EXEC}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.s
	${ASM} ${AFLAGS} $< -o $@

${EXEC}: ${NAME} ${MAIN}
	${CC} ${CFLAGS} ${MAIN} ${NAME}

clean:
	rm -f ${OBJECTS} ${FILE} ${WRONG_FILE}

fclean: clean
	rm -f ${NAME} ${EXEC}

re: fclean all

.PHONY: all clean fclean re
