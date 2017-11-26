/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_mbs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:13:45 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 20:54:38 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Beware the non-conventional error values :
** - get_mask : 0xFF (255)
** - get_sequ : 4
*/

#include "libftprintf.h"

static unsigned char	get_mask(unsigned char byte)
{
	unsigned char	*candidates;
	unsigned char	*checkers;
	ssize_t			i;

	i = 4;
	candidates = (unsigned char[]){0x80, 0xE0, 0xF0, 0xF8};
	checkers = (unsigned char[]){0, 0xC0, 0xE0, 0xF0};
	while (--i > -1)
		if ((byte & candidates[i]) == checkers[i])
			return (candidates[i]);
	return (0xFF);
}

static size_t			get_sequ(unsigned char byte)
{
	unsigned char	*masks;
	ssize_t			ret;

	ret = -1;
	masks = (unsigned char[]){0x80, 0xE0, 0xF0, 0xF8, 0};
	while (masks[++ret])
		if (byte == masks[ret])
			return ((size_t)ret);
	return (4);
}

static _Bool			check_sequ(unsigned char *mbs, size_t start, \
		size_t sequ)
{
	size_t	i;

	i = start;
	if (sequ == 0)
		return (1);
	while (++i <= start + sequ)
	{
		if ((mbs[i] & 0xC0) != 0x80)
		{
			mbs[start] = 0;
			return (0);
		}
	}
	return (1);
}

void					cut_mbs(unsigned char *mbs)
{
	size_t			landmark;
	size_t			sequ;
	unsigned char	mask;

	landmark = 0;
	if (!mbs)
		return ;
	while (mbs[landmark])
	{
		if ((mask = get_mask(mbs[landmark])) == 0xFF \
				|| (sequ = get_sequ(mask)) == 4)
			return ;
		if (!check_sequ(mbs, landmark, sequ))
			return ;
		landmark += sequ + 1;
	}
}
