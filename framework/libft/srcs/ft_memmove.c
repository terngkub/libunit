/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:52:19 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/08 21:46:18 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fwd_copy(unsigned char **pdst, unsigned char **psrc, size_t len)
{
	size_t	count;

	if (len)
	{
		count = 0;
		while (count < len)
		{
			*(*pdst + count) = *(*psrc + count);
			count++;
		}
	}
}

static void	bckwd_copy(unsigned char **pdst, unsigned char **psrc, size_t len)
{
	size_t	count;

	if (len)
	{
		count = len - 1;
		while (count)
		{
			*(*pdst + count) = *(*psrc + count);
			count--;
		}
		**pdst = **psrc;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		bckwd_copy((unsigned char **)(&dst), (unsigned char **)(&src), len);
	else
		fwd_copy((unsigned char **)(&dst), (unsigned char **)(&src), len);
	return (dst);
}
