/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:36:47 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/14 20:03:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	clean_elem(void *content, size_t content_size)
{
	if (content)
	{
		ft_bzero(content, content_size - 1);
		ft_memdel(&content);
	}
}

void	put_list(t_list *elem)
{
	const char	*cast;

	if (elem && elem->content)
	{
		ft_putstr(cast = (const char *)elem->content);
		ret_val(ft_strlen(cast));
	}
}

int		ret_val(int val)
{
	static int	ret = 0;

	if (val == -2)
	{
		if (ret != -1)
			ret = 0;
	}
	else
		ret = (val == -1) || (ret == -1) ? -1 : ret + val;
	return (ret);
}

int		ft_printf(char *fmt, ...)
{
	void		(*del)(void *, size_t);
	void		(*put)(t_list *elem);
	va_list		ap;
	t_list		*start;
	t_list		*lst;

	del = &clean_elem;
	put = &put_list;
	ret_val(-2);
	if (fmt)
		if ((start = get_queue(fmt)))
		{
			lst = start;
			va_start(ap, fmt);
			process_fmt(&ap, start);
			ft_lstiter(lst, put);
			ft_lstdel(&start, del);
			va_end(ap);
		}
	return (ret_val(0));
}
