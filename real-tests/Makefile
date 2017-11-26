.PHONY = all test clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FWK_DIR = ../framework/
FWK_HDR = $(addprefix $(FWK_DIR), libunit.h)
FWK = $(addprefix $(FWK_DIR), libunit.a)

PRINT_DIR = $(addprefix $(FWK_DIR), ft_printf/)
PRINT_HDR_DIR = $(addprefix $(PRINT_DIR), includes/)
PRINT = $(addprefix $(PRINT_DIR), libftprintf.a)

FT_DIR = $(addprefix $(FWK_DIR), libft/)
FT_HDR_DIR = $(addprefix $(FT_DIR), includes/)
FT = $(addprefix $(FT_DIR), libft.a)

INCLUDES = -I $(FWK_DIR) -I $(PRINT_HDR_DIR) -I $(FT_HDR_DIR)\
		   -I $(PUTCHAR_DIR)\
		   -I $(PUTSTR_DIR)\
		   -I $(ATOI_DIR)
LIBS = -L$(FWK_DIR) -lunit -L$(PRINT_DIR) -lftprintf -L$(FT_DIR) -lft

MAIN = main.c
ROUTINE = rt_project

PROJECT_DIR = ./project/

PUTCHAR_DIR = ./rt_putchar/
PUTCHAR_RT = $(addprefix $(PROJECT_DIR), rt_putchar.c)
PUTCHAR_RT_OBJ = $(patsubst %.c,%.o,$(PUTCHAR_RT))
PUTCHAR_TESTS_SRC = 00_rt_putchar_launcher 01_basic_test 02_unprintable_char_test
PUTCHAR_SRC = $(addprefix $(PUTCHAR_DIR), $(addsuffix .c, $(PUTCHAR_TESTS_SRC)))
PUTCHAR_OBJ = $(patsubst %.c,%.o,$(PUTCHAR_SRC))

PUTSTR_DIR = ./rt_putstr/
PUTSTR_RT = $(addprefix $(PROJECT_DIR), rt_putstr.c)
PUTSTR_RT_OBJ = $(patsubst %.c,%.o,$(PUTSTR_RT))
PUTSTR_TESTS_SRC = 00_rt_putstr_launcher 01_basic_putstr_test 02_null_test
PUTSTR_SRC = $(addprefix $(PUTSTR_DIR), $(addsuffix .c, $(PUTSTR_TESTS_SRC)))
PUTSTR_OBJ = $(patsubst %.c,%.o,$(PUTSTR_SRC))

ATOI_DIR = ./rt_atoi/
ATOI_RT = $(addprefix $(PROJECT_DIR), rt_atoi.c)
ATOI_RT_OBJ = $(patsubst %.c,%.o,$(ATOI_RT))
ATOI_TESTS_SRC = 00_rt_atoi_launcher 01_basic_atoi_test 02_zero_test 03_negative_test\
				 04_plus_sign_test 05_space_test 06_space_plus_test 07_space_negative_test\
				 08_word_after_test 09_zero_before_num_test 10_zero_before_neg_num_test\
				 11_multiple_zero_test
ATOI_SRC = $(addprefix $(ATOI_DIR), $(addsuffix .c, $(ATOI_TESTS_SRC)))
ATOI_OBJ = $(patsubst %.c,%.o,$(ATOI_SRC))

all : $(ROUTINE)

test : $(ROUTINE)
	./$(ROUTINE)

$(ROUTINE) : $(MAIN)\
	$(PUTCHAR_OBJ) $(PUTCHAR_RT_OBJ)\
	$(PUTSTR_OBJ) $(PUTSTR_RT_OBJ)\
	$(ATOI_OBJ) $(ATOI_RT_OBJ)
	@make -C $(FWK_DIR)
	@$(CC) $(CFLAGS) $^ $(INCLUDES) $(LIBS) -o $@

$(PROJECT_DIR)%.o : $(PROJECT_DIR)%.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(PUTCHAR_DIR)%.o : $(PUTCHAR_DIR)%.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(PUTSTR_DIR)%.o : $(PUTSTR_DIR)%.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(ATOI_DIR)%.o : $(ATOI_DIR)%.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

clean : 
	@make clean -C $(FWK_DIR)
	@make clean -C $(PRINT_DIR)
	@make clean -C $(FT_DIR)
	@rm -f $(PUTCHAR_RT_OBJ) $(PUTCHAR_OBJ)
	@rm -f $(PUTSTR_RT_OBJ) $(PUTSTR_OBJ)
	@rm -f $(ATOI_RT_OBJ) $(ATOI_OBJ)

fclean : clean
	@rm -f $(ROUTINE) $(FWK) $(PRINT) $(FT)

re : fclean all
