/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:48:25 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/25 00:23:29 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s && (substr = (char *)ft_memalloc(len + 1)))
	{
		ft_strlcpy(substr, &s[start], len + 1);
		return (substr);
	}
	else
		return (NULL);
}
