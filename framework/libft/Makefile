# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:22:01 by jdaufin           #+#    #+#              #
#    Updated: 2017/11/26 22:36:17 by jdaufin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = libft.a
SRCDIR = srcs/
SRC_NAME = ft_atoi.c ft_memdel.c ft_strcat.c ft_strncat.c ft_bzero.c\
		   ft_memmove.c ft_strchr.c ft_strncpy.c ft_isalnum.c ft_memset.c\
		   ft_strclr.c ft_strnequ.c ft_isalpha.c ft_putbstr.c ft_strcmp.c\
		   ft_strnew.c ft_isascii.c ft_putchar.c ft_strcpy.c ft_strnstr.c\
		   ft_isdigit.c ft_putchar_fd.c ft_strdup.c ft_strrchr.c ft_isprint.c\
		   ft_putendl.c ft_strequ.c ft_strstr.c ft_memalloc.c ft_putendl_fd.c\
		   ft_striter.c ft_tolower.c ft_memccpy.c ft_putnbr.c ft_striteri.c\
		   ft_toupper.c ft_memchr.c ft_putnbr_fd.c ft_strlen.c ft_memcmp.c\
		   ft_putstr.c ft_strmap.c ft_memcpy.c ft_putstr_fd.c ft_strmapi.c\
		   ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strlcat.c ft_strlcpy.c\
		   ft_strsplit.c ft_itoa.c ft_wordcount.c ft_putstrtab.c ft_strncmp.c\
		   ft_strdel.c ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
		   ft_lstiter.c ft_lstmap.c ft_lstappend.c ft_lstinsert.c ft_realloc.c\
		   ft_islower.c ft_isupper.c ft_isspace.c ft_isblank.c ft_abs.c\
		   get_next_line.c init_wslen.c ft_putwchar.c ft_putwstr.c\
		   ft_putwstr_fd.c ft_wcharlen.c ft_wcstrlen.c ft_wcrtomb.c\
		   ft_wcstombs.c ft_strsub_free.c ft_atoimax.c ft_strsplit_blanks.c\
		   ft_strjoin_free.c ft_itoa_base.c ft_uitoa_base.c ft_stabdel.c\
		   ft_lstlen.c ft_linkdel.c ft_lstpop.c
SRC = $(addprefix $(SRCDIR), $(SRC_NAME))
OBJDIR = builts/
OBJ = $(addprefix $(OBJDIR), $(SRC_NAME:.c=.o))
HDRDIR = includes/
HDR = $(addprefix $(HDRDIR), libft.h)
CCFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -urc $@ $^
	@ranlib $@

$(OBJDIR)%.o : $(SRCDIR)%.c $(HDR)
	@mkdir $(OBJDIR) 2> /dev/null || true
	@gcc $(CCFLAGS) -o $@  -c $< -I $(HDRDIR)

clean :
	@rm -rf $(OBJDIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
