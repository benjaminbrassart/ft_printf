# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 22:15:31 by bbrassar          #+#    #+#              #
#    Updated: 2021/06/30 23:58:21 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS					= -Wall -Werror -Wextra -g

BASE_DIR_LIBFT			= libft

# ft_printf
NAME					= libftprintf.a

DIR_SRC					= src

SRC						= $(addsuffix .c,									\
																			\
						)

DIR_OBJ					= obj

OBJ						= $(SRC:.c=.o)

DIR_INCLUDE				= include
#

all:					$(NAME)

$(DIR_OBJ):
						mkdir -p $@

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c |$(DIR_OBJ)
						$(CC) $(CFLAGS) $< -o $@ -c -I $(DIR_INCLUDE)

$(NAME):				$(OBJ) $(OBJ_LIBFT)
						ar rcs $@ $^

clean:					libft-clean
						rm -rf $(DIR_OBJ)

fclean:					libft-fclean clean
						rm -f $(NAME)

re:						fclean all

.PHONY:					all clean fclean re

-include $(BASE_DIR_LIBFT)/Makefile