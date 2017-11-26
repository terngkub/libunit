/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:38:22 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/19 17:40:35 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wint_t c)
{
	unsigned char	*mbs;
	ssize_t			len;

	if (MB_CUR_MAX == 4)
	{
		len = ft_wcharlen((wchar_t)c);
		if (len > -1)
		{
			mbs = (unsigned char *)ft_strnew((size_t)len);
			ft_wcrtomb(mbs, (wchar_t)c);
			write(1, mbs, len);
			ft_memdel((void **)&mbs);
		}
	}
	else if (MB_CUR_MAX == 1 && ((c & 0x80) || (ft_isascii((int)c))))
		ft_putchar((char)c);
}
