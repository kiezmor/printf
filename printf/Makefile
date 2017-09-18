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

NAME	=	libftprintf.a
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

SDIR	=	src
DOBJ	=	obj
INC		=	-I inc/

LIB		=	libft/libft.a

OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))

SRC		=	src/ft_printf.c\
			src/ft_ptf_buff.c\
			src/ft_ptf_cands.c\
			src/ft_ptf_char.c\
			src/ft_ptf_clr.c\
			src/ft_ptf_conversion.c\
			src/ft_ptf_double.c\
			src/ft_ptf_flags_1.c\
			src/ft_ptf_flags_2.c\
			src/ft_ptf_int.c\
			src/ft_ptf_join.c\
			src/ft_ptf_pdsc.c\
			src/ft_ptf_putd.c\
			src/ft_ptf_putnbr.c\
			src/ft_ptf_tmp.c\
			src/ft_ptf_uint.c\
			src/ft_set_ptf_cfp.c\
			src/ft_set_ptf_lw.c\
			src/get_ptf_flags.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "lib created"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

#REMOVE KEBAB >>

test:
	@make re
	@make clean
	@$(CC) $(FLAGS) main.c $(LIB) $(NAME) 
	@./a.out
	@rm ./a.out

lib:
	@make -C $(LIB_DIR)
	@make clean -C $(LIB_DIR)

# << REMOVE KEBAB

clean:
	rm -f $(OBJ)
	@echo "obj deleted"

fclean: clean
	rm -f $(NAME)
	@echo "lib deleted"

re: fclean all
