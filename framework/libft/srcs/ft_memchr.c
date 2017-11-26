/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:19:07 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/14 20:29:25 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			count;
	unsigned char	*cast;

	count = 0;
	cast = (unsigned char *)s;
	while (count < len)
	{
		if (cast[count] == (unsigned char)c)
			return ((void *)(&cast[count]));
		else
			count++;
	}
	return (NULL);
}
