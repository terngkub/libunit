/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:39:43 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 20:48:01 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	wc_to_str(va_list *pap, t_tag *tag, void **addr)
{
	wint_t			input;
	unsigned char	*mbs;
	ssize_t			len;

	input = va_arg(*pap, wint_t);
	ft_memdel(addr);
	if (MB_CUR_MAX == 4)
	{
		if (input && (len = ft_wcharlen((wchar_t)input)) \
				> -1 && (mbs = (unsigned char *)ft_strnew((size_t)len)))
			if ((tag->to_out.wcrtomb)(mbs, (wchar_t)input) > -1)
			{
				*addr = (void *)mbs;
				return ;
			}
	}
	else
		ret_val(-1);
}

void	c_to_str(va_list *pap, t_tag *tag, void **addr)
{
	char	input;

	input = (char)va_arg(*pap, int);
	ft_memdel(addr);
	if (input && (*addr = (void *)ft_strnew(1)))
		(tag->to_out.memcpy)((char *)*addr, (const void *)&input, 1);
	else if (input == 0)
		ret_val(1);
}

void	wcs_to_str(va_list *pap, t_tag *tag, void **addr)
{
	wchar_t	*input;

	ft_memdel(addr);
	if (MB_CUR_MAX == 4)
	{
		if ((input = va_arg(*pap, wchar_t *)))
			*addr = (void *)(tag->to_out.wcstombs)((const wchar_t *)input);
		else
			*addr = (void *)ft_strdup("(null)");
	}
	else
		ret_val(-1);
}

void	s_to_str(va_list *pap, t_tag *tag, void **addr)
{
	char	*input;

	ft_memdel(addr);
	if ((input = va_arg(*pap, char *)))
		*addr = (void *)(tag->to_out.strdup)(input);
	else
		*addr = (void *)ft_strdup("(null)");
}

void	txt_to_str(va_list *pap, t_tag *tag, void **addr)
{
	if (tag->type == CC)
		wc_to_str(pap, tag, addr);
	else if (tag->type == C)
		c_to_str(pap, tag, addr);
	else if (tag->type == SS)
		wcs_to_str(pap, tag, addr);
	else if (tag->type == S)
		s_to_str(pap, tag, addr);
}
