SRCS_DIR	= ./
SRCS_FILES	= main.c control.c map.c images.c movements.c management.c animation.c get_next_line.c get_next_line_utils.c
SRCS		= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

BONUS_DIR	= ./
BONUS_FILES	= 
BONUS		= ${patsubst %, ${BONUS_DIR}%, ${BONUS_FILES}}

LIBFT		= ./libft
MAKELIB		= ${MAKE} -C ${LIBFT}

LIBX		= ./minilibx
MAKELIBX	= ${MAKE} -C ${LIBX}

HEADS		= ./

OBJS		= ${SRCS:.c=.o}
OBJSB		= ${BONUS:.c=.o}

NAME		= so_long

CC		= gcc
AR		= ar rcs
CP		= cp -f
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${HEADS}

${NAME}:	${OBJS}
		${MAKELIBX} all
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I${HEADS} -Lminilibx -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

bonus:		${NAME}

clean:
		${RM} ${OBJS} ${OBJSB}
		${MAKELIBX} clean

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all bonus clean fclean re
