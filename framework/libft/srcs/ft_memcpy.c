/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:15:21 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/28 12:02:27 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*bdst;
	unsigned char	*bsrc;
	size_t			count;

	count = 0;
	bdst = (unsigned char *)dst;
	bsrc = (unsigned char *)src;
	while (count < n)
	{
		bdst[count] = bsrc[count];
		count++;
	}
	return (dst);
}
