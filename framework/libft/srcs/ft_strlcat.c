/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:50:43 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/29 21:00:52 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*buf;
	size_t	count;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	buf = ft_strchr(dst, 0);
	count = 0;
	if (size > dstlen + 1)
	{
		while ((count < (size - dstlen - 1)) && (src[count]))
		{
			buf[count] = src[count];
			count++;
		}
		buf[count] = '\0';
		return (ft_strlen(src) + dstlen);
	}
	else
		return (ft_strlen(src) + size);
}
