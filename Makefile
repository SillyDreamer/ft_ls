NAME = ft_ls

CFLAGS = -Wall -Werror -Wextra -I libft/includes/ -I includes/ \
                                                            -I srcs/ft_printf/

SRC = ./srcs/ft_printf/ft_printf.c ./srcs/ft_printf/ft_specifier.c \
      ./srcs/ft_printf/ft_type.c ./srcs/print_utils.c ./srcs/display.c \
      ./srcs/ls_errors.c ./srcs/ls_parser.c ./srcs/ls_sort.c \
      ./srcs/ls_stat_parser.c ./srcs/main.c ./srcs/utils.c \
      ./srcs/print_long_format.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\x1B[34mComplete!"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
