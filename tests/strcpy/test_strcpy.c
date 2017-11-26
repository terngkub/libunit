/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:01:58 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 17:28:57 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*test_strcpy(char *dst, const char *src)
{
	size_t	size;
	size_t	count;

	size = ft_strlen(src);
	count = 0;
	while (count < size)
	{
		dst[count] = src[count];
		count++;
	}
	return (dst);
}
