.PHONY: all test clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FWK_DIR = ../framework/
FWK_HDR = $(addprefix $(FWK_DIR), libunit.h)
FWK = $(addprefix $(FWK_DIR), libunit.a)

PRINT_DIR = $(addprefix $(FWK_DIR), ft_printf/)
PRINT_HDR_DIR = $(addprefix $(PRINT_DIR), includes/)

FT_DIR = $(addprefix $(FWK_DIR), libft/)
FT_HDR_DIR = $(addprefix $(FT_DIR), includes/)
FT = $(addprefix $(FT_DIR), libft.a)

MAIN = ./main.c
STRCPY = bt_strcpy_basic
STRCPY_RADIX = 00_basic_strcpy_launcher 01_basic_strcpy_test_ok\
			   02_basic_strcpy_test_ko 03_basic_strcpy_test_segv\
			   04_basic_strcpy_test_buse test_strcpy
STRCPY_DIR = strcpy/
STRCPY_SRC = $(addprefix $(STRCPY_DIR), $(addsuffix .c, $(STRCPY_RADIX)))
STRCPY_OBJ = $(patsubst %.c,%.o,$(STRCPY_SRC))

all : $(STRCPY)

test : $(STRCPY)
	./$(STRCPY)

$(STRCPY) : $(MAIN) $(STRCPY_OBJ)
	@if [ ! -f $(FT) ]; then make -C $(FT_DIR); fi
	@if [ ! -f $(FWK) ]; then make -C $(FWK_DIR); fi
	@$(CC) $(CFLAGS) $^ -I $(STRCPY_DIR) -I $(FT_HDR_DIR) -L $(FT_DIR) -lft\
		-I $(PRINT_HDR_DIR) -I $(FWK_DIR) -L $(FWK_DIR) -lunit -o $@

$(STRCPY_DIR)%.o : $(STRCPY_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -I $(FWK_DIR) -I $(FT_HDR_DIR) -I $(PRINT_HDR_DIR)\
		-o $@
clean :
	@make clean -C $(FWK_DIR)
	@make clean -C $(FT_DIR)
	@rm -f $(STRCPY_OBJ)

fclean : clean
	@rm -f $(STRCPY) $(FWK) $(FT)

re : fclean all
