/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:25:28 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/01 19:34:57 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if ((s1 && s2) && (ft_strlen(s1)) == (ft_strlen(s2)))
	{
		if (!(ft_memcmp((void *)s1, (void *)s2, ft_strlen(s1) + 1)))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
