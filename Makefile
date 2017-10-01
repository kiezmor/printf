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

LIB_O	=	ft_atoi.o\
			ft_itoa.o\
			ft_memcmp.o\
			ft_putnbr_fd.o\
			ft_strcmp.o\
			ft_strlen.o\
			ft_strrchr.o\
			ft_bzero.o\
			ft_lstadd.o\
			ft_memcpy.o\
			ft_putstr.o\
			ft_strcpy.o\
			ft_strmap.o\
			ft_strrev.o\
			ft_countwords.o\
			ft_lstdel.o\
			ft_memdel.o\
			ft_putstr_fd.o\
			ft_strdel.o\
			ft_strmapi.o\
			ft_strsplit.o\
			ft_fibonacci.o\
			ft_lstdelone.o\
			ft_memmove.o\
			ft_putwchar.o\
			ft_strdup.o\
			ft_strncat.o\
			ft_strstr.o\
			ft_isalnum.o\
			ft_lstiter.o\
			ft_memset.o\
			ft_putwcs.o\
			ft_strequ.o\
			ft_strncmp.o\
			ft_strsub.o\
			ft_isalpha.o\
			ft_lstmap.o\
			ft_putchar.o\
			ft_range.o\
			ft_striter.o\
			ft_strncpy.o\
			ft_strtrim.o\
			ft_isascii.o\
			ft_lstnew.o\
			ft_putchar_fd.o\
			ft_sqrt.o\
			ft_striteri.o\
			ft_strndup.o\
			ft_tolower.o\
			ft_isdigit.o\
			ft_memalloc.o\
			ft_putendl.o\
			ft_strcat.o\
			ft_strjoin.o\
			ft_strnequ.o\
			ft_toupper.o\
			ft_isprint.o\
			ft_memccpy.o\
			ft_putendl_fd.o\
			ft_strchr.o\
			ft_strlcat.o\
			ft_strnew.o\
			ft_wcslen.o\
			ft_isspace.o\
			ft_memchr.o\
			ft_putnbr.o\
			ft_strclr.o\
			ft_strlcpy.o\
			ft_strnstr.o\
			get_next_line.o

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
	ar rc ptf.a $(OBJ)
	libtool $(NAME) ptf.a $(LIB)
	rm -f ptf.a
	@echo "${G}library created${NC}"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

#REMOVE KEBAB >>

test:
	@make re
	@make clean
	@$(CC) $(FLAGS) main.c $(NAME) 
	@./a.out
	@rm ./a.out

# << REMOVE KEBAB

clean:
	@rm -rf obj/
	@echo "${R}objects deleted${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${R}library deleted${NC}"

re: fclean all
