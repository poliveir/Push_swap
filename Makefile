# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poliveir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 13:20:38 by poliveir          #+#    #+#              #
#    Updated: 2021/07/15 14:08:28 by poliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#VARIABLES:

LIBFT_PATH	= ./libft

NAME		= libpush_swap.a

PROGRAM_NAME	= push_swap

SRCS_DIR	= ./source_files

HDRS_DIR	= ./header_files

PUSH_SWAP_SRC = push_swap.c

SRCS		= source_files/fill_stack.c source_files/instructions_set.c source_files/utils.c source_files/sort_stack.c \
		source_files/sort_utils1.c source_files/sort_utils2.c source_files/commands1.c source_files/commands2.c \
		source_files/commands3.c

OBJS		= ${SRCS:.c=.o}

LIBFT_SRCS	= libft/ft_atoi.c libft/ft_atol.c libft/ft_isascii.c libft/ft_memchr.c libft/ft_putchar_fd.c libft/ft_strchr.c \
			  libft/ft_strlen.c libft/ft_strtrim.c libft/ft_bzero.c libft/ft_isdigit.c libft/ft_memcmp.c \
			  libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strmapi.c libft/ft_substr.c libft/ft_calloc.c \
			  libft/ft_isprint.c libft/ft_memcpy.c libft/ft_putnbr_fd.c libft/ft_strjoin.c libft/ft_strncmp.c \
			  libft/ft_tolower.c libft/ft_isalnum.c libft/ft_itoa.c libft/ft_memmove.c libft/ft_putstr_fd.c \
			  libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_memccpy.c \
			  libft/ft_memset.c libft/ft_split.c libft/ft_strlcpy.c libft/ft_strrchr.c libft/ft_lstnew.c \
			  libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c \
			  libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c

LIBFT_OBJS	= ${LIBFT_SRCS:.c=.o}

CC		= gcc

CFLAGS		= -fsanitize=address -Wall -Werror -Wextra

AR		= ar

ARFLAGS		= -rcs

RM		= rm -rf

#RULES:

.SILENT:
all: ${NAME} ${PUSH_SWAP_SRC}


$(NAME): ${OBJS}
	${MAKE} re bonus -C ${LIBFT_PATH}
	${CC} -c ${CFLAGS} -I${HDRS_DIR} ${SRCS}
	${AR} ${ARFLAGS} $@ $^ ${LIBFT_OBJS}
	$(CC) ${CFLAGS} ${PUSH_SWAP_SRC} ${NAME} -o ${PROGRAM_NAME}

clean:
	${RM} *.o ${SRCS_DIR}/*.o
	${MAKE} clean -C ${LIBFT_PATH}

fclean: clean
	${RM} ${NAME} ${PROGRAM_NAME}
	${MAKE} fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: all clean fclean re
