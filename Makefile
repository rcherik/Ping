# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 14:31:01 by rcherik           #+#    #+#              #
#    Updated: 2015/11/20 15:29:52 by rcherik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME = ft_ping
CFLAGS = gcc -Wall -Werror -Wextra
OFLAGS = -I libft/includes/. -I ./includes/.
LFLAGS = -L libft -lft -L /usr/lib
LIB = libft/libft.a
MKLIB = make -C libft
PATH_SRC = src
PATH_OBJ = obj
SRC = main.c\
	  ft_error.c\
	  error_message.c\
	  ping.c\
	  ft_sig_handler.c\
	  statistic.c\

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all : $(NAME)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@mkdir -p $(PATH_OBJ)
	@$(CFLAGS) $(OFLAGS) -o $@ -c $^

$(LIB) :
	@$(MKLIB)

$(NAME) : $(LIB) $(OBJ)
	@$(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

lib :
	@$(MKLIB)
	@make

clean :
	@$(MKLIB) clean
	@rm -f $(OBJ)

fclean : clean
	@$(MKLIB) fclean
	@rm -f $(NAME)
	@rm -rf $(PATH_OBJ)

re : fclean all

.PHONY : fclean re clean all
