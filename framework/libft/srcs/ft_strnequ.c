/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:19:41 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/25 00:15:37 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	range;

	if ((s1) && (s2))
	{
		range = ft_strlen(s1) + 1;
		range = ((range > n) ? n : range);
		if (!(ft_memcmp((void *)s1, (void *)s2, range)))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
