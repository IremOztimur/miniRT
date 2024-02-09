SRC = 	ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_strlen.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isnum.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_atoi.c \
		ft_atod.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_strclen.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_itoa.c \
		ft_split.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_clamp.c \
		ft_free.c \
		ft_vector_clear.c \
		ft_vector_delete.c \
		ft_vector_new.c \
		ft_vector_pop.c \
		ft_vector_push.c \
		ft_matrix_delete.c \
		ft_matrix_size.c \
		ft_matrix_append.c \
		ft_matrix_new.c \
		ft_count.c \
		ft_vector_at.c

SRCS = ${addprefix ./libft/,${SRC}} \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c


OBJS = ${SRCS:.c=.o}
NAME = lib.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
AR = ar -rcs


all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@echo "Succesfully archieved"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

run: ${NAME}
	@${CC} ${CFLAGS} ${MAIN} ${NAME}
	@${OUT}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean clean all re .c.o
