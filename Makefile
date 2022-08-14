NAME			=	pipex

SRCS			=	srcs/pipex.c srcs/struct.c srcs/path.c srcs/arrays.c srcs/files.c srcs/dup_std.c
SRCS_B			=	srcs_bonus/arrays_bonus.c srcs_bonus/dup_std_bonus.c srcs_bonus/files_bonus.c srcs_bonus/parsing_bonus.c srcs_bonus/path_bonus.c srcs_bonus/pipex_bonus.c srcs_bonus/struct_bonus.c

OBJS			=	$(SRCS:.c=.o)
OBJS_B			=	$(SRCS_B:.c=.o)

INCLUDES		= -I./includes/
HEADERS			= includes/libft.h includes/pipex.h

LIBS			= ./libft/

CC				= 	gcc
CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f
AR				=	ar rc
DEL_DIR			=	-r

GREEN			=	"\033[32m"
BLUE			=	"\033[34m"
MAGENTA			=	"\033[35m"
CYAN			=	"\033[96m"
YELLOW			=	"\033[93m"
RESET			=	"\033[0m"

%.o:			%.c
					@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

all:			$(NAME)

bonus:			$(OBJS_B) $(HEADERS)
					@make all -C ${LIBS}
					@echo ${YELLOW}"'libft' updated =^.^=\n"${RESET}
					@${CC} -o ${NAME} ${OBJS_B} ${LIBS}libft.a
					@echo ${GREEN}"><((º>"${RESET}${BLUE}"  ><((º>"${RESET}${MAGENTA}"  ><((º>"${RESET} \
					${CYAN}"PiPeX BoNuS CoMPiLeD"${RESET} \
					${MAGENTA}"<º))><  "${RESET}${BLUE}"<º))><  "${RESET}${GREEN}"<º))><\n"${RESET}


$(NAME):		$(OBJS) ${HEADERS}
					@make all -C ${LIBS}
					@echo ${YELLOW}"'libft' updated =^.^=\n"${RESET}
					@${CC} -o ${NAME} ${OBJS} ${LIBS}libft.a
					@echo ${GREEN}"><((º>"${RESET}${BLUE}"  ><((º>"${RESET}${MAGENTA}"  ><((º>"${RESET} \
					${CYAN}"PiPeX CoMPiLeD"${RESET} \
					${MAGENTA}"<º))><  "${RESET}${BLUE}"<º))><  "${RESET}${GREEN}"<º))><\n"${RESET}

clean:
					@make clean -C ${LIBS}
					@echo ${CYAN}"Clean 'libft' dirs and objects ="${RESET} ${GREEN}"OK"${RESET}
					@${RM} ${OBJS} ${OBJS_B}
					@echo ${CYAN}"Clean 'pipex' objects ="${RESET} ${GREEN}"OK"${RESET}
					@${RM} ${DEL_DIR} ${DIR_OBJS}


fclean:			clean
					@make fclean -C ${LIBS}
					@${RM} ${NAME}
					@echo ${CYAN}"'${NAME}' cleaned with"${RESET} ${GREEN}"!!!SUCCESS!!!"${RESET}

re:				clean fclean all

.PHONY:			all clean fclean re bonus
