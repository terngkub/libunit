/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:07:17 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/10 23:05:10 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*endp;
	char	*scast;

	endp = ft_strchr(src, 0);
	scast = (char *)src;
	while (len--)
	{
		if (&scast[len] > endp)
			dst[len] = '\0';
		else
			dst[len] = scast[len];
	}
	return (dst);
}
