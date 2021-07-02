# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 22:15:31 by bbrassar          #+#    #+#              #
#    Updated: 2021/07/02 04:21:11 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS					= -Wall -Werror -Wextra -g

BASE_DIR_LIBFT			= libft

NAME					= libftprintf.a

DIR_SRC					= src

SRC						= $(addsuffix .c,									\
							ft_printf										\
							ft_parse_options								\
							ft_get_printer									\
							ft_print_char									\
							ft_print_string									\
						)

DIR_OBJ					= obj

OBJ						= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

DIR_INCLUDE				= include

INCLUDE					= $(addprefix $(DIR_INCLUDE)/, $(addsuffix .h,		\
							ft_printf.h										\
							ft_options.h									\
							print_functions.h								\
							libft.h											\
						))

all:					$(NAME)

-include $(BASE_DIR_LIBFT)/Makefile

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

run_test:				test/main.c all
						$(CC) -g $< -o $@ -l ftprintf -L .

.PHONY:					all clean fclean re
