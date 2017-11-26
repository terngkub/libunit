.PHONY: all re clean fclean

NAME = libunit.a

RADIX = launch_tests load_test clean_list stdout_buffer
DIR = ./
SRC = $(addprefix $(DIR), $(addsuffix .c, $(RADIX)))
OBJ = $(addprefix $(DIR), $(addsuffix .o, $(RADIX)))
HDR = $(addprefix $(DIR), libunit.h)

PRINT_DIR = ./ft_printf/
PRINT_HDR_DIR = $(addprefix $(PRINT_DIR), includes/)
PRINT_HDR = $(addprefix $(PRINT_HDR_DIR), libftprintf.h)
PRINT = $(addprefix $(PRINT_DIR), libftprintf.a)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(PRINT)
	@libtool -static -o $@ $^

$(PRINT) :
	@make -C $(PRINT_DIR)

$(DIR)%.o : $(DIR)%.c $(HDR) $(PRINT_HDR)
	@$(CC) $(CFLAGS) -c $< -I $(DIR) -I $(PRINT_HDR_DIR) -o $@

clean :
	@make clean -C $(PRINT_DIR)
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME) $(PRINT)

re : fclean all
