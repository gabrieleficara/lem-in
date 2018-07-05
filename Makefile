# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gficara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:25:41 by gficara           #+#    #+#              #
#    Updated: 2018/04/04 14:13:42 by syboeuf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB = $(NAME).a
LIB2 = lib/ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
INC = -I includes
SRC = parsing/lemin.c parsing/checkinput.c srcs/astar.c \
	  srcs/free.c srcs/main.c srcs/place.c srcs/read.c srcs/room.c \
	  srcs/stock.c srcs/walking.c
OBJ = $(SRC:.c=.o)

.PHONY : all clean fclean name

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	@make -C lib/ft_printf
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@$(CC) $(FLAGS) $(INC) -o $(NAME) $(LIB) $(LIB2)
	@echo "Creating $(NAME)"

%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean :
	@make clean -C lib/ft_printf
	@rm -rf $(OBJ)
	@echo "Removing $(NAME) objects"

fclean : clean
	@make fclean -C lib/ft_printf
	@rm -rf $(NAME) $(LIB)
	@echo "Removing $(LIB) and $(NAME)"

re: fclean all
