NAME 	= pipex

SRCS 	= pipex.c ft_split.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_strncmp.c main.c src.c

OBJS 	= ${SRCS:.c=.o}

CFLAGS 	= -Wall -Wextra -Werror

RM 		= rm -f

CC		= gcc

HEDER	= -I pipex.h

.c.o:
		${CC} ${CFLAGS} -c  ${HEDER} $< -o ${<:.c=.o}

all: 	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}
clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re