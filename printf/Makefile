# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/19 05:06:16 by vpluchar          #+#    #+#              #
#    Updated: 2017/04/24 09:38:49 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= gcc
FLAGS	= -Wall -Werror -Wextra

##REMOVE KEBAB >>

LIB = ./libft/libft.a
LIB_DIR = ./libft/
LIB_INC = ./libft/includes/

## << REMOVE KEBAB

SRC	= ft_printf.c ft_ptf_buff.c ft_ptf_cands.c ft_ptf_char.c ft_ptf_clr.c\
ft_ptf_conversion.c ft_ptf_flags_1.c ft_ptf_flags_2.c ft_ptf_int.c\
ft_ptf_join.c ft_ptf_tmp.c ft_ptf_uint.c ft_set_ptf_cfp.c ft_set_ptf_lw.c\
get_ptf_flags.c ft_ptf_putnbr.c ft_ptf_double.c ft_ptf_pdsc.c ft_ptf_putd.c\

OBJ	= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
##	@echo "lib created"

$(OBJ):
	@$(CC) $(FLAGS) -c $(SRC) -I $(LIB_INC)
##	@echo "obj created"

##REMOVE KEBAB >>

test:
	@make re
	@make clean
	@$(CC) $(FLAGS) main.c $(NAME) $(LIB)
	@./a.out
	@rm ./a.out
##	@./a.exe
##	@rm ./a.exe

lib:
	@make -C $(LIB_DIR)
	@make clean -C $(LIB_DIR)

## << REMOVE KEBAB

clean:
	@rm -f $(OBJ)
##	@echo "obj deleted"

fclean: clean
	@rm -f $(NAME)
##	@echo "lib deleted"

re: fclean all
