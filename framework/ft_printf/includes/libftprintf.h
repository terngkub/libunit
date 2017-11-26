/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:38:48 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 18:02:44 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <wchar.h>
# include <locale.h>
# include "../../libft/includes/libft.h"
# define HEXLO "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DECIM "0123456789"
# define OCTAL "01234567"

typedef enum				e_type
{
	TABEND = -1,
	D,
	HD,
	HHD,
	LD,
	LLD,
	JD,
	ZD,
	U,
	HU,
	HHU,
	LU,
	LLU,
	JU,
	ZU,
	O,
	HO,
	HHO,
	LO,
	LLO,
	JO,
	ZO,
	X,
	HX,
	HHX,
	LX,
	LLX,
	JX,
	ZX,
	XX,
	HXX,
	HHXX,
	LXX,
	LLXX,
	JXX,
	ZXX,
	P,
	C,
	CC,
	S,
	SS,
	PC
}							t_type;

union						u_intype
{
	int						d;
	int						i;
	short int				hd;
	signed char				hhd;
	long int				ld;
	long long int			lld;
	intmax_t				jd;
	intmax_t				zd;
	unsigned int			u;
	unsigned short int		hu;
	unsigned char			hhu;
	unsigned long int		lu;
	unsigned long long int	llu;
	uintmax_t				ju;
	size_t					zu;
	unsigned int			o;
	unsigned short int		ho;
	unsigned char			hho;
	unsigned long int		lo;
	unsigned long long int	llo;
	uintmax_t				jo;
	size_t					zo;
	unsigned int			x;
	unsigned short int		hx;
	unsigned char			hhx;
	unsigned long int		lx;
	unsigned long long int	llx;
	uintmax_t				jx;
	size_t					zx;
};

typedef union				u_cast
{
	char					*(*uitoa)(uintmax_t, char *);
	char					*(*itoa)(intmax_t, char *);
	void					*(*memcpy)(void *, const void *, size_t);
	ssize_t					(*wcrtomb)(unsigned char *, wchar_t);
	unsigned char			*(*wcstombs)(const wchar_t *);
	char					*(*strdup)(const char *);
	void					(*err)(void);
}							t_cast;

typedef struct				s_padding
{
	_Bool					zeroes;
	_Bool					neg_width;
}							t_padding;

typedef struct				s_prefix
{
	_Bool					space;
	_Bool					plus;
}							t_prefix;

typedef struct				s_tag
{
	t_type					type;
	t_cast					to_out;
	int						width;
	int						precision;
	_Bool					alter;
	t_padding				*padding;
	t_prefix				*prefix;
	_Bool					null_val;
}							t_tag;

int							ret_val(int val);
int							ft_printf(char *fmt, ...);
void						put_list(t_list *elem);
void						clean_elem(void *content, size_t content_size);
t_list						*get_queue(char *fmt);
_Bool						tagend(char c);
ssize_t						get_taglen(const char *s);
ssize_t						get_len(const char *s);
void						process_fmt(va_list *pap, t_list *start);
t_tag						*init_tag(void);
void						ft_reinit_tag(t_tag *tag);
void						preset_conversion(t_tag *tag, char *s);
t_type						get_type(char *s);
t_type						get_d(char *s);
t_type						get_u(char *s);
t_type						get_o(char *s);
t_type						get_x(char *s);
t_type						get_xx(char *s);
t_type						get_txt(char *s);
t_type						get_p(char *s);
t_type						get_pc(char *s);
_Bool						get_class(t_type *table, t_type tocheck);
t_cast						get_action(t_type intype);
_Bool						ft_parse(t_tag *tag, char *s);
_Bool						check_flags(t_tag *tag, char **pts);
_Bool						check_width(t_tag *tag, char **pts);
_Bool						check_prec(t_tag *tag, char **pts);
_Bool						check_length(char **pts);
void						set_flags(t_tag *tag, char *flags);
void						ft_convert(va_list *pap, t_tag *tag, void **addr);
void						d_to_str(va_list *pap, t_tag *tag, void **addr);
void						u_to_str(va_list *pap, t_tag *tag, void **addr);
void						o_to_str(va_list *pap, t_tag *tag, void **addr);
void						x_to_str(va_list *pap, t_tag *tag, void **addr);
void						p_to_str(va_list *pap, t_tag *tag, void **addr);
void						txt_to_str(va_list *pap, t_tag *tag, void **addr);
void						pc_to_str(t_tag *tag, void **addr);
void						ft_format(t_tag *tag, void **addr);
void						set_empty(t_tag *tag, void **addr);
void						cut_mbs(unsigned char *mbs);
void						ft_clean_tag(t_tag *tag);
void						transfer_minus(char **ppad, void **addr);
void						transfer_0x(char **ppad, void **addr);
_Bool						is_0x(t_tag *tag);
void						launch_conversion(t_tag *tag, va_list *pap,\
		void **addr);
void						transfer_plus(char **ppad, void **addr);
void						fmt_unconvertible(void **addr);
#endif
