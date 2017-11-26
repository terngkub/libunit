/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:44:06 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/14 19:42:10 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	set_prec(t_tag *tag, void **addr)
{
	int		slen;
	char	*prec;
	char	*swap;

	slen = tag->type >= D && tag->type <= ZXX && (*((char *)*addr) == '-') ?\
		(int)ft_strlen((char *)*addr) - 1 : (int)ft_strlen((char *)*addr);
	if (slen < tag->precision && tag->type >= D && tag->type <= ZXX)
	{
		slen = tag->precision - slen;
		prec = ft_strnew(slen);
		prec = (char *)ft_memset((void *)prec, (int)'0', slen);
		if (*((char *)*addr) == '-')
		{
			swap = ft_strdup((char *)(*addr + 1));
			ft_memdel(addr);
			prec = ft_strjoin_free("-", 0, prec, 1);
			*addr = ft_strjoin_free(prec, 1, swap, 1);
		}
		else
			*addr = (void *)ft_strjoin_free(prec, 1, *addr, 1);
	}
	else if (tag->type >= S && tag->type <= SS && slen > tag->precision \
			&& tag->precision > -1)
		cut_mbs((unsigned char *)(*addr = \
					(void *)ft_strsub_free((char *)*addr, 0, tag->precision)));
}

static void	set_prefixes(t_tag *tag, void **addr)
{
	if (*(char *)*addr != '-' && (tag->type >= D) && (tag->type <= ZD))
	{
		if (tag->prefix->plus)
			*addr = (void *)ft_strjoin_free("+", 0, (char *)*addr, 1);
		else if (tag->prefix->space)
			*addr = (void *)ft_strjoin_free(" ", 0, (char *)*addr, 1);
	}
	if ((tag->type >= O) && (tag->type <= ZO) && tag->alter \
			&& *((char*)*addr) != '0')
	{
		tag->precision = 1 + (int)ft_strlen((char *)*addr);
		set_prec(tag, addr);
	}
	if (is_0x(tag))
	{
		if (tag->type >= XX && tag->type <= ZXX)
			*addr = (void *)ft_strjoin_free("0X", 0, (char *)*addr, 1);
		else
			*addr = (void *)ft_strjoin_free("0x", 0, (char *)*addr, 1);
	}
}

static void	set_width(t_tag *tag, void **addr)
{
	char	padsign;
	char	*pad;
	int		slen;
	_Bool	move_0x;

	padsign = (((tag->type >= D) && (tag->type <= ZXX) \
				&& (tag->padding->zeroes) && (tag->precision == -1) \
				&& (!tag->padding->neg_width)) ? '0' : ' ');
	slen = (int)ft_strlen((char *)*addr);
	if ((move_0x = is_0x(tag) && slen < tag->width) || slen < tag->width)
	{
		slen = tag->width - slen;
		pad = ft_strnew(slen);
		pad = (char *)ft_memset((void *)pad, (int)padsign, slen);
		if ((padsign == '0') && (*((char *)*addr) == '-'))
			transfer_minus(&pad, addr);
		if ((padsign == '0') && (*((char *)*addr) == '+'))
			transfer_plus(&pad, addr);
		if (move_0x && padsign == '0' && !tag->padding->neg_width)
			transfer_0x(&pad, addr);
		if (tag->padding->neg_width)
			*addr = (void *)ft_strjoin_free((char *)*addr, 1, pad, 1);
		else
			*addr = (void *)ft_strjoin_free(pad, 1, (char *)*addr, 1);
	}
}

void		ft_format(t_tag *tag, void **addr)
{
	if (!(*addr))
	{
		if (tag->width && tag->type == C)
		{
			*addr = (void *)ft_strnew(tag->width);
			*addr = ft_memset(*addr, (int)' ', tag->width - 1);
		}
		return ;
	}
	set_prec(tag, addr);
	set_prefixes(tag, addr);
	set_width(tag, addr);
	set_empty(tag, addr);
}
