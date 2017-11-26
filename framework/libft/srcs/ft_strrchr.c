/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:50:55 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/17 19:05:59 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tgt;
	char	*scast;
	size_t	size;

	size = ft_strlen(s);
	tgt = (char)c;
	scast = (char *)s;
	while (size && (scast[size] != tgt))
		size--;
	if (scast[size] == tgt)
		return (&scast[size]);
	else
		return (NULL);
}
