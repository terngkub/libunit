/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:40:56 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/09 11:51:13 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_type	get_d(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "lld") || ft_strstr(s, "lli"))
		ret = LLD;
	else if (ft_strstr(s, "ld") || ft_strstr(s, "D") || ft_strstr(s, "li"))
		ret = LD;
	else if (ft_strstr(s, "hhd") || ft_strstr(s, "hhi"))
		ret = HHD;
	else if (ft_strstr(s, "hd") || ft_strstr(s, "hi"))
		ret = HD;
	else if (ft_strstr(s, "zd") || ft_strstr(s, "zi"))
		ret = ZD;
	else if (ft_strstr(s, "jd") || ft_strstr(s, "ji"))
		ret = JD;
	else if (ft_strstr(s, "d") || ft_strstr(s, "i"))
		ret = D;
	else
		ret = TABEND;
	return (ret);
}

t_type	get_u(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "llu"))
		ret = LLU;
	else if (ft_strstr(s, "lu") || ft_strstr(s, "U"))
		ret = LU;
	else if (ft_strstr(s, "hhu"))
		ret = HHU;
	else if (ft_strstr(s, "hu"))
		ret = HU;
	else if (ft_strstr(s, "zu"))
		ret = ZU;
	else if (ft_strstr(s, "ju"))
		ret = JU;
	else if (ft_strstr(s, "u"))
		ret = U;
	else
		ret = TABEND;
	return (ret);
}

t_type	get_o(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "llo"))
		ret = LLO;
	else if (ft_strstr(s, "lo") || ft_strstr(s, "O"))
		ret = LO;
	else if (ft_strstr(s, "hho"))
		ret = HHO;
	else if (ft_strstr(s, "ho"))
		ret = HO;
	else if (ft_strstr(s, "jo"))
		ret = JO;
	else if (ft_strstr(s, "zo"))
		ret = ZO;
	else if (ft_strstr(s, "o"))
		ret = O;
	else
		ret = TABEND;
	return (ret);
}

t_type	get_x(char *s)
{
	t_type ret;

	if (ft_strstr(s, "llx"))
		ret = LLX;
	else if (ft_strstr(s, "lx"))
		ret = LX;
	else if (ft_strstr(s, "hhx"))
		ret = HHX;
	else if (ft_strstr(s, "hx"))
		ret = HX;
	else if (ft_strstr(s, "jx"))
		ret = JX;
	else if (ft_strstr(s, "zx"))
		ret = ZX;
	else if (ft_strstr(s, "x"))
		ret = X;
	else
		ret = TABEND;
	return (ret);
}

t_type	get_xx(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "llX"))
		ret = LLXX;
	else if (ft_strstr(s, "lX"))
		ret = LXX;
	else if (ft_strstr(s, "hhX"))
		ret = HHXX;
	else if (ft_strstr(s, "hX"))
		ret = HXX;
	else if (ft_strstr(s, "jX"))
		ret = JXX;
	else if (ft_strstr(s, "zX"))
		ret = ZXX;
	else if (ft_strstr(s, "X"))
		ret = XX;
	else
		ret = TABEND;
	return (ret);
}
