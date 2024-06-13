# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:53:26 by ndurand           #+#    #+#              #
#    Updated: 2022/05/20 15:53:26 by ndurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c op.c op2.c ft_list.c sort.c \
		stack_utils.c stack.c ft_list2.c sort_utils.c utils.c 

OBJS = $(SRCS:.c=.o)

NAME = push_swap

$(NAME): $(OBJS)
		
	@ printf '\033[0;33mCompiling Libft\033[0m\n'
	@ $(MAKE) -s all -C libft
	@ printf '\033[0;32mLibft compiled\033[0m\n'
	@ printf '\033[0;33mCompiling push_swap\033[0m\n'
	@ ${CC} ${CFLAGS} $(OBJS) libft/libft.a -o ${NAME} 
	@ printf '\033[0;32mpush_swap compiled\033[0m\n'

all: $(NAME)

clean:
	@ rm -f $(OBJS)
	@ $(MAKE) -s clean -C libft
	@ printf '\033[0;32mclean done\033[0m\n'

fclean: clean
	@ rm -f ${NAME}
	@ $(MAKE) -s fclean -C libft
	@ printf '\033[0;32mfclean done\033[0m\n'

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJS)