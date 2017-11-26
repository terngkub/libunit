/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:45:00 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/19 17:42:59 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Writes both the number of wchars and the number of bytes necessary to hold
**	them all in a multibyte charstring at the adresses passed by the wslen
**	pointer.
**	Returns : 1 in case of success, 0 otherwise.
*/

_Bool		ft_wcstrlen(const wchar_t *s, t_wslen *wslen)
{
	if (!s || !wslen)
		return (0);
	wslen->count = -1;
	wslen->bytes = 0;
	while (s[++(wslen->count)] != L'\0')
	{
		if (ft_wcharlen(s[wslen->count]) != -1)
			wslen->bytes += ft_wcharlen(s[wslen->count]);
		else
			return (0);
	}
	return (1);
}
