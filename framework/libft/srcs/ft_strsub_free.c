/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:20:22 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/05 17:22:32 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s && (substr = (char *)ft_memalloc(len + 1)))
	{
		ft_strlcpy(substr, &s[start], len + 1);
		ft_memdel((void **)&s);
		return (substr);
	}
	else
		return (NULL);
}
