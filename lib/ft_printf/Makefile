# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 15:19:50 by syboeuf           #+#    #+#              #
#    Updated: 2018/04/04 14:14:03 by syboeuf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRCS = srcs/apel.c srcs/appel_caractere.c srcs/appel_pourcentage.c \
	   srcs/choix_pointeur.c srcs/conversion.c srcs/conversion_decimal.c \
	   srcs/conversion_grand_s.c srcs/conversion_pointeur.c srcs/ft_printf.c \
	   srcs/ft_putnbra.c srcs/ft_putstra.c srcs/modif_fonction.c \
	   srcs/modif_fonction2.c srcs/premier_flag.c srcs/specifier.c \
	   srcs/trouver_flag.c srcs/type_int.c srcs/unicode.c srcs/ft_strjoin.c \
	   srcs/ft_atoi.c srcs/ft_strnew.c srcs/ft_sfstrjoin.c srcs/get_next_line.c \
	   srcs/ft_strcmp.c srcs/ft_strsplit.c srcs/ft_strchr.c srcs/ft_strstr.c \
	   srcs/ft_bzero.c srcs/ft_memalloc.c srcs/ft_lstadd.c srcs/ft_lstnew.c \
	   srcs/ft_lstdel.c srcs/ft_lstdelone.c srcs/ft_memcpy.c srcs/ft_strsub.c \
	   srcs/ft_strncmp.c srcs/ft_strncpy.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo libftprintf est creer

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@echo Fichier .o supprimer

fclean: clean
	@/bin/rm -f $(NAME)
	@echo All clean

re: fclean all
