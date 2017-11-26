/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:32:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/19 17:43:52 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns an implicitely zero-ended multibyte string that casts a wchar_t
**	string
*/

static void		ft_init(ssize_t *i, ssize_t *j, ssize_t *k, t_wslen *p_wslen)
{
	if (i && j && p_wslen)
	{
		*i = 0;
		*j = -1;
		*k = 0;
		p_wslen->count = 0;
		p_wslen->bytes = 0;
	}
}

unsigned char	*ft_wcstombs(const wchar_t *wstr)
{
	ssize_t			i;
	ssize_t			j;
	ssize_t			k;
	unsigned char	*mbs;
	t_wslen			wslen;

	ft_init(&i, &j, &k, &wslen);
	if (!wstr || !(ft_wcstrlen(wstr, &wslen)) \
			|| !(mbs = (unsigned char *)ft_strnew(wslen.bytes)))
		return ((unsigned char *)NULL);
	while ((k > -1) && (i < wslen.bytes) && wstr[++j] != L'\0')
	{
		k = ft_wcrtomb(&mbs[i], wstr[j]);
		i += k;
	}
	return (mbs);
}
