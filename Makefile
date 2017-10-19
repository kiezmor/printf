# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/19 05:06:16 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/19 02:52:48 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation

NAME	=	libftprintf.a
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

# Directories

SDIR	=	src
DOBJ	=	obj
INC		=	-I inc/

# Colors

G		=	\x1b[32m
R		=	\x1b[31m
Y		=	\x1b[33m
NC		=	\x1b[0m

# Files

LIB		=	libft/libft.a

OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))

SRC		=	src/ft_g_flags.c\
			src/ft_printf.c\
			src/ft_ptf_bin.c\
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
			src/ft_wchar.c\
			src/ft_wstring.c

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${Y}create the library${NC}"
	@make -C libft/
	@ar rc ptf.a $(OBJ)
	@libtool -static -o $(NAME) ptf.a $(LIB)
	@rm -f ptf.a
	@echo "${G}$(NAME) created${NC}"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

#REMOVE KEBAB >>

test:
	@make re
	@make clean
	@$(CC) $(FLAGS) m.c $(NAME) 
	@./a.out
	@rm ./a.out

# << REMOVE KEBAB

clean:
	@make -C libft/ clean
	@rm -rf obj/
	@echo "${R}objects deleted${NC}"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "${Y}$(NAME) ${R}deleted${NC}"

re: fclean all
