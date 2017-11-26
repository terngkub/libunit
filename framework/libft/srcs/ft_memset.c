/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:09:32 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/11 17:10:13 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	unsigned char	*bcast;
	size_t			count;

	count = 0;
	bcast = (unsigned char *)b;
	val = (unsigned char)c;
	while (count < len)
	{
		bcast[count] = val;
		count++;
	}
	return (b);
}
