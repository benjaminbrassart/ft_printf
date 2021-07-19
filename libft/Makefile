# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 02:36:44 by bbrassar          #+#    #+#              #
#    Updated: 2021/07/14 03:59:18 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a

NAME_SO				= libft.so

CFLAGS				= -Wall -Werror -Wextra -I$(DIR_INCLUDE) -c -MMD

LDFLAGS				= -fPIC -shared

DIR_SRC				= src

SRC					=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
						ft_memmove.c ft_memchr.c ft_memrchr.c ft_rawmemchr.c \
						ft_memcmp.c ft_strlen.c ft_isalnum.c ft_isalpha.c \
						ft_isascii.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c \
						ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c \
						ft_isupper.c ft_isxdigit.c ft_toupper.c ft_tolower.c \
						ft_strchr.c ft_strrchr.c ft_strcspn.c ft_strnlen.c \
						ft_strncmp.c ft_strncpy.c ft_strncat.c ft_strndup.c \
						ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
						ft_strcat.c ft_strcpy.c ft_strcmp.c ft_strstr.c \
						ft_atoll.c ft_calloc.c ft_strdup.c ft_substr.c \
						ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
						ft_lltoa.c ft_strmapi.c ft_putchar.c ft_putchar_fd.c \
						ft_putstr.c ft_putstr_fd.c ft_putendl.c \
						ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_lstnew.c \
						ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
						ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
						ft_lstiter.c ft_lstmap.c ft_strrepeat.c get_next_line.c

DIR_OBJ				= obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

DIR_INCLUDE			= include

DEPENDENCIES		= $(OBJ:.o=.d)

$(NAME):			$(OBJ)
					ar rcs $@ $^

-include $(DEPENDENCIES)

$(DIR_OBJ):
					mkdir -p $@

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c |$(DIR_OBJ)
					$(CC) $(CFLAGS) $< -o $@

$(NAME_SO):			$(OBJ)
					$(CC) $^ -o $@ $(LDFLAGS)

all:				$(NAME) $(NAME_SO)

clean:
					rm -rf $(DIR_OBJ)

fclean:				clean
					rm -f $(NAME) $(NAME_SO)

re:					fclean all

.PHONY:				all clean fclean re
