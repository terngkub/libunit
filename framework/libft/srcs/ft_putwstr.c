/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:13:55 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/19 17:41:16 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(const wchar_t *s)
{
	unsigned char	*mbs;
	t_wslen			wslen;

	if (s && ft_wcstrlen(s, &wslen) && (mbs = ft_wcstombs(s)))
	{
		write(1, mbs, wslen.bytes);
		ft_memdel((void **)&mbs);
	}
}
