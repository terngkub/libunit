/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:31:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/14 20:45:39 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_type	get_type(char *s)
{
	t_type	ret;

	if ((ret = get_d(s)) == TABEND)
		if ((ret = get_u(s)) == TABEND)
			if ((ret = get_o(s)) == TABEND)
				if ((ret = get_x(s)) == TABEND)
					if ((ret = get_xx(s)) == TABEND)
						if ((ret = get_txt(s)) == TABEND)
							if ((ret = get_p(s)) == TABEND)
								if ((ret = get_pc(s + 1)) == TABEND)
								{
									ret_val(-1);
									return (ret);
								}
	return (ret);
}

_Bool	get_class(t_type *table, t_type tocheck)
{
	ssize_t	i;

	i = -1;
	while (table[++i] != TABEND)
		if (table[i] == tocheck)
			return (1);
	return (0);
}

t_cast	get_action(t_type intype)
{
	t_type	*signed_int;
	t_type	*unsigned_int;
	t_cast	ret;

	signed_int = (t_type[]){D, HD, HHD, LD, LLD, JD, ZD, TABEND};
	unsigned_int = (t_type[]){O, HO, HHO, LO, LLO, ZO, JO, X, HX, HHX, LX, \
		LLX, ZX, JX, XX, HXX, HHXX, LXX, LLXX, ZXX, JXX, U, HU, HHU, LU, LLU, \
			ZU, JU, P, TABEND};
	if (get_class(signed_int, intype))
		ret.itoa = &ft_itoa_base;
	else if (get_class(unsigned_int, intype))
		ret.uitoa = &ft_uitoa_base;
	else if (intype == C)
		ret.memcpy = &ft_memcpy;
	else if (intype == CC)
		ret.wcrtomb = &ft_wcrtomb;
	else if (intype == S)
		ret.strdup = &ft_strdup;
	else if (intype == SS)
		ret.wcstombs = &ft_wcstombs;
	else
		ret.err = NULL;
	return (ret);
}

void	ft_convert(va_list *pap, t_tag *tag, void **addr)
{
	if (pap && tag && addr)
	{
		if ((tag->type >= D) && (tag->type <= ZD))
			d_to_str(pap, tag, addr);
		else if ((tag->type >= U) && (tag->type <= ZU))
			u_to_str(pap, tag, addr);
		else if ((tag->type >= O) && (tag->type <= ZO))
			o_to_str(pap, tag, addr);
		else if ((tag->type >= X) && (tag->type <= ZX))
			x_to_str(pap, tag, addr);
		else if ((tag->type >= XX) && (tag->type <= ZXX))
			x_to_str(pap, tag, addr);
		else if (tag->type == P)
			p_to_str(pap, tag, addr);
		else if ((tag->type >= C) && (tag->type <= SS))
			txt_to_str(pap, tag, addr);
		else if (tag->type == PC)
			pc_to_str(tag, addr);
		else
			ret_val(-1);
	}
}

void	process_fmt(va_list *pap, t_list *start)
{
	t_list	*lst;
	t_tag	*tag;
	char	*check;

	if (pap && start)
	{
		lst = start;
		tag = init_tag();
		while (lst)
		{
			check = (char *)lst->content;
			if (check[0] == '%')
			{
				if (tagend(check[lst->content_size - 2]) \
						&& ft_parse(tag, check))
					launch_conversion(tag, pap, &lst->content);
				else if (lst->content)
					fmt_unconvertible(&(lst->content));
				ft_reinit_tag(tag);
			}
			lst = lst->next;
		}
		ft_clean_tag(tag);
	}
}
