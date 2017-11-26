# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 14:41:14 by jdaufin           #+#    #+#              #
#    Updated: 2017/11/26 22:14:29 by jdaufin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re clean fclean

NAME = libftprintf.a
RADIX = ft_printf get_queue mappers process_fmt \
		converters_decimals converters_unsigned converters_octal converters_hex\
		converters_specials get_integer_t get_special_t ft_parse checkers\
		set_flags init_tag ft_format set_empty converters_chars\
		get_txt_t cut_mbs transfer_prefixes is_0x launch_conversion\
		check_length fmt_unconvertible
SRCDIR = srcs/
OBJDIR = builds/
HDRDIR = includes/
HDR = $(HDRDIR)libftprintf.h
SRC = $(addprefix $(SRCDIR), $(addsuffix .c, $(RADIX)))
OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(RADIX)))
LIBDIR = ../libft/
LIBHDR = $(addprefix $(LIBDIR), includes)
LIB = $(addprefix $(LIBDIR), libft.a)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(LIBDIR)/libft.a
	@libtool -static -o $@ $^

$(OBJDIR)%.o : $(SRCDIR)%.c $(HDR) $(LIBHDR)/libft.h
	@if [ ! -f $(LIB) ]; then make -C $(LIBDIR); fi
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -I $(HDRDIR) -I $(LIBHDR) -o $@

clean :
	@make clean -C $(LIBDIR) 
	@rm -rf $(OBJDIR)

fclean : clean
	@make fclean -C $(LIBDIR) 
	@rm -f $(NAME)

re : fclean all
