# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 12:08:49 by rgalyeon          #+#    #+#              #
#    Updated: 2019/01/24 22:47:03 by rgalyeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
CC = gcc
NORM = norminette
INCLUDES = ./includes/
OFILES = *.o

CHAR_FILES = ./srcs/char/ft_isalnum.c \
			 ./srcs/char/ft_isalpha.c \
			 ./srcs/char/ft_isascii.c \
			 ./srcs/char/ft_isdigit.c \
			 ./srcs/char/ft_isprint.c \
			 ./srcs/char/ft_isspace.c \
			 ./srcs/char/ft_tolower.c \
			 ./srcs/char/ft_toupper.c

CONV_FILES = ./srcs/conv/ft_atoi.c \
			 ./srcs/conv/ft_ftoa.c \
			 ./srcs/conv/ft_itoa.c 

MATH_FILES = ./srcs/math/ft_int_len.c \
			 ./srcs/math/ft_pow.c 

MEM_FILES = ./srcs/memory/ft_bzero.c \
			./srcs/memory/ft_memalloc.c \
			./srcs/memory/ft_memccpy.c \
			./srcs/memory/ft_memchr.c \
			./srcs/memory/ft_memcmp.c \
			./srcs/memory/ft_memcpy.c \
			./srcs/memory/ft_memdel.c \
			./srcs/memory/ft_memmove.c \
			./srcs/memory/ft_memset.c

PUT_FILES = ./srcs/put/ft_putchar.c \
			./srcs/put/ft_putchar_fd.c \
			./srcs/put/ft_putendl.c \
			./srcs/put/ft_putendl_fd.c \
			./srcs/put/ft_putnbr.c \
			./srcs/put/ft_putnbr_fd.c \
			./srcs/put/ft_putstr.c \
			./srcs/put/ft_putstr_fd.c

STR_FILES = ./srcs/string/ft_strcat.c \
			./srcs/string/ft_strchr.c \
			./srcs/string/ft_strclr.c \
			./srcs/string/ft_strcmp.c \
			./srcs/string/ft_strcpy.c \
			./srcs/string/ft_strdel.c \
			./srcs/string/ft_strdup.c \
			./srcs/string/ft_strequ.c \
			./srcs/string/ft_striter.c \
			./srcs/string/ft_striteri.c \
			./srcs/string/ft_strjoin.c \
			./srcs/string/ft_strlcat.c \
			./srcs/string/ft_strlen.c \
			./srcs/string/ft_strmap.c \
			./srcs/string/ft_strmapi.c \
			./srcs/string/ft_strncat.c \
			./srcs/string/ft_strncmp.c \
			./srcs/string/ft_strncpy.c \
			./srcs/string/ft_strnequ.c \
			./srcs/string/ft_strnew.c \
			./srcs/string/ft_strnstr.c \
			./srcs/string/ft_strrchr.c \
			./srcs/string/ft_strreverse.c \
			./srcs/string/ft_strsplit.c \
			./srcs/string/ft_strstr.c \
			./srcs/string/ft_strsub.c \
			./srcs/string/ft_strtrim.c \
			./srcs/string/get_next_line.c	

LIST_FILES = ./srcs/struct/list/ft_lstadd.c \
			 ./srcs/struct/list/ft_lstdel.c \
			 ./srcs/struct/list/ft_lstdelone.c \
			 ./srcs/struct/list/ft_lstiter.c \
			 ./srcs/struct/list/ft_lstmap.c \
			 ./srcs/struct/list/ft_lstnew.c \
			 ./srcs/struct/list/ft_lst_map_init.c

MATRIX_FILES = ./srcs/struct/matrix/ft_matrix_copy.c \
			   ./srcs/struct/matrix/ft_matrix_create.c \
			   ./srcs/struct/matrix/ft_matrix_digit_mul.c \
			   ./srcs/struct/matrix/ft_matrix_max.c \
			   ./srcs/struct/matrix/ft_matrix_mul.c \
			   ./srcs/struct/matrix/ft_matrix_print.c \
			   ./srcs/struct/matrix/ft_matrix_sub.c \
			   ./srcs/struct/matrix/ft_matrix_trans.c

RB_TREES_FILES = ./srcs/struct/rb_trees/ft_rb_del_fix.c \
				 ./srcs/struct/rb_trees/ft_rb_del_node.c \
				 ./srcs/struct/rb_trees/ft_rb_find_node.c \
				 ./srcs/struct/rb_trees/ft_rb_free.c \
				 ./srcs/struct/rb_trees/ft_rb_infix.c \
				 ./srcs/struct/rb_trees/ft_rb_ins_fix.c \
				 ./srcs/struct/rb_trees/ft_rb_ins_node.c \
				 ./srcs/struct/rb_trees/ft_rb_left_rot.c \
				 ./srcs/struct/rb_trees/ft_rb_node_creat.c \
				 ./srcs/struct/rb_trees/ft_rb_prefix.c \
				 ./srcs/struct/rb_trees/ft_rb_print_key.c \
				 ./srcs/struct/rb_trees/ft_rb_right_rot.c \
				 ./srcs/struct/rb_trees/ft_rb_suffix.c \
				 ./srcs/struct/rb_trees/ft_rb_tree_init.c \
				 ./srcs/struct/rb_trees/ft_rb_free_map.c 

VEC_FILES = ./srcs/struct/vector/ft_vec_init.c \
			./srcs/struct/vector/ft_vec_push.c \
			./srcs/struct/vector/ft_ls_vec_init.c \
			./srcs/struct/vector/ft_ls_vec_push.c \
			./srcs/struct/vector/vec_pro_init.c \
			./srcs/struct/vector/vec_pro_push.c

SORT_FILES = ./srcs/sort/ft_swap.c \

FILES = $(CHAR_FILES) $(CONV_FILES) $(MATH_FILES) $(MEM_FILES) $(PUT_FILES) \
		$(STR_FILES) $(LIST_FILES) $(MATRIX_FILES) $(RB_TREES_FILES) \
		$(VEC_FILES) $(SORT_FILES)
OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES)
	@$(CC) $(FLAG) -I $(INCLUDES) -c $(FILES)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I $(INCLUDES) -c $<

norm:
	@$(NORM) $(FILES) $(HEADER)

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
