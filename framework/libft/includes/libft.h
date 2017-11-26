/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:19:39 by jdaufin           #+#    #+#             */
/*   Updated: 2017/10/05 14:34:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <locale.h>
# include <inttypes.h>
# include <wchar.h>
# define BUFF_SIZE 15

typedef struct		s_str
{
	char			*addr;
	size_t			len;
}					t_str;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buffer
{
	int				fildes;
	char			buf[BUFF_SIZE + 1];
}					t_buffer;

typedef struct		s_wslen
{
	ssize_t			count;
	ssize_t			bytes;
}					t_wslen;

int					ft_atoi(const char *str);
intmax_t			ft_atoimax(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t nbr, char *base);
char				*ft_uitoa_base(uintmax_t nbr, char *base);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_abs(int c);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstrtab(char **tab);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putbstr(const void *s, size_t len, char sep);

void				init_wslen(t_wslen *p_wslen);
void				ft_putwchar(wint_t c);
void				ft_putwstr(const wchar_t *s);
void				ft_putwstr_fd(const wchar_t *s, int fd);
ssize_t				ft_wcharlen(wchar_t wcr);
_Bool				ft_wcstrlen(const wchar_t *s, t_wslen *wslen);
ssize_t				ft_wcrtomb(unsigned char *mbs, wchar_t val);
unsigned char		*ft_wcstombs(const wchar_t *wstr);

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *s);
size_t				ft_wordcount(char const *s, char c);
int					get_next_line(const int fd, char **line);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_free(char const *s, unsigned int start, \
		size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, _Bool b1, char const *s2, \
		_Bool b2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_blanks(char *s);
void				ft_stabdel(char ***pstab);

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void **addr, size_t oldsize, size_t newsize);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **addr, t_list *new);
void				ft_linkdel(void *ptr, size_t size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstpop(t_list **alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
ssize_t				ft_lstlen(t_list *lst);
#endif
