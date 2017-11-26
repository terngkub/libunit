/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:51:13 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/28 15:42:05 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbstr(const void *s, size_t len, char sep)
{
	size_t			count;
	unsigned char	*bstr;

	bstr = (unsigned char *)s;
	count = 0;
	if (bstr)
	{
		while (count < len)
		{
			ft_putnbr((int)bstr[count]);
			ft_putchar(sep);
			count++;
		}
		ft_putchar('\n');
	}
}
