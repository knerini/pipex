NAME			=	libft.a

CFILES			=	ft_printf/ft_check_conversion.c ft_printf/ft_convert_c.c ft_printf/ft_convert_di.c ft_printf/ft_convert_p.c ft_printf/ft_convert_s.c ft_printf/ft_convert_u.c ft_printf/ft_convert_x.c ft_printf/ft_printf.c ft_printf/ft_write_string.c \
					gnl/get_next_line_utils.c gnl/get_next_line.c \
					is_fct/ft_isalnum.c is_fct/ft_isalpha.c is_fct/ft_isascii.c is_fct/ft_isdigit.c is_fct/ft_isprint.c \
					lst_fct/ft_lstadd_back.c lst_fct/ft_lstadd_front.c lst_fct/ft_lstclear.c lst_fct/ft_lstdelone.c lst_fct/ft_lstiter.c lst_fct/ft_lstlast.c lst_fct/ft_lstmap.c lst_fct/ft_lstnew.c lst_fct/ft_lstsize.c \
					mem_fct/ft_bzero.c mem_fct/ft_calloc.c mem_fct/ft_memchr.c mem_fct/ft_memcmp.c mem_fct/ft_memcpy.c mem_fct/ft_memmove.c mem_fct/ft_memset.c \
					put_fct/ft_putchar_fd.c put_fct/ft_putendl_fd.c put_fct/ft_putnbr_base.c put_fct/ft_putnbr_fd.c put_fct/ft_putstr_fd.c \
					str_fct/ft_nbrlen_base.c str_fct/ft_split.c str_fct/ft_strchr.c str_fct/ft_strdup.c str_fct/ft_striteri.c str_fct/ft_strjoin.c str_fct/ft_strlcat.c str_fct/ft_strlcpy.c str_fct/ft_strlen.c str_fct/ft_strmapi.c str_fct/ft_strncmp.c str_fct/ft_strnstr.c str_fct/ft_strrchr.c str_fct/ft_strtrim.c str_fct/ft_substr.c \
					to_fct/ft_atoi.c to_fct/ft_itoa.c to_fct/ft_tolower.c to_fct/ft_toupper.c

DIR_SRCS		=	srcs
DIR_OBJS		=	objs
SUB_DIRS		=	ft_printf gnl is_fct lst_fct mem_fct put_fct str_fct to_fct

SRCS			=	${foreach dir, ${CFILES}, ${addprefix ${DIR_SRCS}/, ${dir}}}
DIRS_OBJS		=	${foreach dir, ${SUB_DIRS}, ${addprefix ${DIR_OBJS}/, ${dir}}}
OBJS			=	${subst ${DIR_SRCS}, ${DIR_OBJS}, ${SRCS:.c=.o}}

INCLUDES		=	-I./../includes

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f
AR				=	ar rc
DEL_DIR			=	-r

GREEN			=	"\033[32m"
BLUE			=	"\033[34m"
MAGENTA			=	"\033[35m"
CYAN			=	"\033[96m"
RESET			=	"\033[0m"

${DIR_OBJS}/%.o:	${DIR_SRCS}/%.c
						@mkdir -p ${DIR_OBJS} ${DIRS_OBJS}
						@${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${@:.c=.o}

${NAME}:			${OBJS}
						@${AR} ${NAME} ${OBJS}
						@echo ${GREEN}"(===||:"${RESET}${BLUE}":::::::"${RESET}${MAGENTA}"::::::>"${RESET} \
						${CYAN}"'${NAME}' compiled with success \o/"${RESET} \
						${MAGENTA}"<::::::"${RESET}${BLUE}":::::::"${RESET}${GREEN}":||===)\n"${RESET}

all:				${NAME}

clean:
						@${RM} ${OBJS}
						@${RM} ${DEL_DIR} ${DIR_OBJS}
#						@echo ${CYAN}"Clean 'libft' dirs and objects ="${RESET} ${GREEN}"OK"${RESET}


fclean:				clean
						@${RM} ${NAME}
						@echo ${CYAN}"'${NAME}' cleaned with"${RESET} ${GREEN}"!!!SUCCESS!!!"${RESET}

re:					clean fclean all

.PHONY:				all clean fclean re
