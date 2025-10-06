NAME = libasm.a
NAME_BONUS = libasm_bonus.a
MAIN = main.c
MAIN_BONUS = main_bonus.c
EXEC = libasm
EXEC_BONUS = libasm_bonus

FILE = test.txt
WRONG_FILE = wrong_file.txt

SRC_FILE = src
BONUS_FILE = bonus

SOURCES = ${SRC_FILE}/ft_strlen.s \
	${SRC_FILE}/ft_strcpy.s \
	${SRC_FILE}/ft_strcmp.s \
	${SRC_FILE}/ft_write.s \
	${SRC_FILE}/ft_read.s \
	${SRC_FILE}/ft_strdup.s

SOURCES_BONUS = ${BONUS_FILE}/ft_list_push_front.s \
	${BONUS_FILE}/ft_list_size.s

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

ASM = nasm
AFLAGS = -f elf64

OBJECTS = $(SOURCES:.s=.o)
OBJECTS_BONUS = ${SOURCES_BONUS:.s=.o}

all: ${NAME} ${EXEC}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.s
	${ASM} ${AFLAGS} $< -o $@

${EXEC}: ${NAME} ${MAIN}
	${CC} ${CFLAGS} ${MAIN} ${NAME} -o ${EXEC}

clean:
	rm -f ${OBJECTS} ${OBJECTS_BONUS} ${FILE} ${WRONG_FILE}

fclean: clean
	rm -f ${NAME} ${NAME_BONUS} ${EXEC} ${EXEC_BONUS}

re: fclean all

bonus: ${NAME_BONUS} ${EXEC_BONUS}

${NAME_BONUS}: ${OBJECTS_BONUS}
	ar rcs ${NAME_BONUS} ${OBJECTS_BONUS}

%.o: %.s
	${ASM} ${AFLAGS} $< -o $@

${EXEC_BONUS}: ${NAME_BONUS} ${MAIN_BONUS}
	${CC} ${CFLAGS} ${MAIN_BONUS} ${NAME_BONUS} -o ${EXEC_BONUS}

.PHONY: all clean fclean re bonus
