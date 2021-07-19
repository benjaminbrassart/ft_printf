# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 21:55:51 by bbrassar          #+#    #+#              #
#    Updated: 2021/07/19 22:19:11 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libftprintf.a

CFLAGS					= -Wall -Werror -Wextra -c -MMD \
							-I$(DIR_INCLUDE) -I$(DIR_LIBFT)/include

DIR_LIBFT				= libft/

NAME_LIBFT				= $(DIR_LIBFT)/libft.a

DIR_SRC					= src

SRC						=	ft_get_printer.c ft_parse_options.c \
							ft_print_char.c ft_print_hex.c ft_print_int.c \
							ft_print_pointer.c ft_print_raw.c \
							ft_print_string.c ft_print_uint.c ft_printf.c \
							ft_putstr_fn.c

DIR_OBJ					= obj

OBJ						= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

DIR_INCLUDE				= include

DEPENDENCIES			= $(OBJ:.o=.d)

$(NAME):				$(NAME_LIBFT) $(OBJ)
						cp -f $< $@
						ar vrs $@ $(filter %.o, $^)

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) $< -o $@

$(NAME_LIBFT):
						$(MAKE) -C $(DIR_LIBFT)

all:					$(NAME)

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME)

re:						fclean all

.PHONY:					all clean fclean re
