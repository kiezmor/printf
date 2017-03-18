# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 12:52:28 by vpluchar          #+#    #+#              #
#    Updated: 2017/03/19 00:25:26 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf
cc	= gcc
FLAGS	= -Wall -Werror -Wextra
SRC	= main.c ft_printf.c ft_flag.c
OBJ	= $(SRC:.c=.o)
HEADER	= /libft/includes/

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I$(HEADER) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "$(NAME) files created"

clean:
	@rm -f $(OBJ)
	@echo "object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "binary files deleted"

re: fclean all
