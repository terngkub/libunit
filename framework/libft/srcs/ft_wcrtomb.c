/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:59:32 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/20 23:21:50 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the number (last index incremented) of bytes writen in case of
**	success, or -1 otherwise.
*/

ssize_t			ft_wcrtomb(unsigned char *mbs, wchar_t val)
{
	ssize_t			i;
	ssize_t			max;
	unsigned char	swap;

	i = -1;
	max = ft_wcharlen(val);
	while (++i < max)
	{
		if (max == 1)
			mbs[0] = val & 0x7F;
		else if (i == max - 1)
		{
			swap = val & (0x7f >> i);
			mbs[max - i - 1] = swap | (0xF0 << (4 - max));
		}
		else
		{
			swap = val & 0x3F;
			mbs[max - i - 1] = swap | 0x80;
			val >>= 6;
		}
	}
	return (max);
}
