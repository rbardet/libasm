NAME = libasm.a
NAME_BONUS = libasm_bonus.a

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

ASM = nasm
AFLAGS = -f elf64

OBJECTS = $(SOURCES:.s=.o)
OBJECTS_BONUS = ${SOURCES_BONUS:.s=.o}

all: ${NAME} ${EXEC}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.s
	${ASM} ${AFLAGS} $< -o $@

clean:
	rm -f ${OBJECTS} ${OBJECTS_BONUS}

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: ${NAME_BONUS} ${EXEC_BONUS}

${NAME_BONUS}: ${OBJECTS_BONUS}
	ar rcs ${NAME_BONUS} ${OBJECTS_BONUS}

%.o: %.s
	${ASM} ${AFLAGS} $< -o $@

.PHONY: all clean fclean re bonus
