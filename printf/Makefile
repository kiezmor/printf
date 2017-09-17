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

DSRC	=	src
DOBJ	=	obj
INC		=	-I inc/
LIB		=	./libft/libft.a

SRC		=	$(shell find $(DSRC) -name '*.c' -type f)
SDIR	=	$(shell find $(DSRC) -type d)
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))
OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(INC) $(OBJ)
	@echo "lib created"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

##REMOVE KEBAB >>

test:
	@make re
	@make clean
	@$(CC) $(FLAGS) main.c $(LIB) $(NAME) 
	@./a.out
	@rm ./a.out

lib:
	@make -C $(LIB_DIR)
	@make clean -C $(LIB_DIR)

## << REMOVE KEBAB

clean:
	rm -f $(OBJ)
	@echo "obj deleted"

fclean: clean
	rm -f $(NAME)
	@echo "lib deleted"

re: fclean all
