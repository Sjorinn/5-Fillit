# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2019/03/19 16:51:44 by jpoulvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \
		check_tetri.c \
		pos_tetri.c \
		resolve_tetri.c \
		extra_functions.c

OBJ = $(SRCS:.c=.o)

LIB_DIR = libft

INCL = fillit.h \
		$(LIB_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror -I $(INCL)

CC = clang

all: $(NAME)

$(NAME): FORCE LIB $(OBJ)
	@gcc -o $(NAME) $(FLAGS) $(OBJ)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $<

LIB:
	@$(MAKE) -C $(LIB_DIR)

clean: 
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean $(NAME)

FORCE:

.PHONY: all clean fclean re FORCE
