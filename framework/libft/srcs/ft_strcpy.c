/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:01:58 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/13 22:08:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	size;
	size_t	count;

	size = ft_strlen(src) + 1;
	count = 0;
	while (count < size)
	{
		dst[count] = src[count];
		count++;
	}
	return (dst);
}
