/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:21:30 by jdaufin           #+#    #+#             */
/*   Updated: 2017/04/21 12:12:25 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	jzu_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == JU)
	{
		input.ju = va_arg(*pap, uintmax_t);
		tag->null_val = input.ju == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.ju, DECIM);
	}
	else if (tag->type == ZU)
	{
		input.zu = va_arg(*pap, size_t);
		tag->null_val = input.zu == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.zu, DECIM);
	}
}

static void	su_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == HU)
	{
		input.hu = (unsigned short int)va_arg(*pap, unsigned int);
		tag->null_val = input.hu == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.hu, DECIM);
	}
	else if (tag->type == HHU)
	{
		input.hhu = (unsigned char)va_arg(*pap, unsigned int);
		tag->null_val = input.hhu == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.hhu, DECIM);
	}
}

static void	lu_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == LU)
	{
		input.lu = va_arg(*pap, unsigned long int);
		tag->null_val = input.lu == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.lu, DECIM);
	}
	else if (tag->type == LLU)
	{
		input.llu = va_arg(*pap, unsigned long long int);
		tag->null_val = input.llu == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.llu, DECIM);
	}
}

void		u_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (pap && tag && addr)
	{
		ft_memdel(addr);
		if (tag->type == U)
		{
			input.u = va_arg(*pap, unsigned int);
			tag->null_val = input.u == 0 ? 1 : 0;
			*addr = (void *)(tag->to_out.uitoa)(input.u, DECIM);
		}
		else if ((tag->type == ZU) || (tag->type == JU))
			jzu_to_str(pap, tag, addr);
		else if ((tag->type == HU) || (tag->type == HHU))
			su_to_str(pap, tag, addr);
		else if ((tag->type == LU) || (tag->type == LLU))
			lu_to_str(pap, tag, addr);
	}
}
