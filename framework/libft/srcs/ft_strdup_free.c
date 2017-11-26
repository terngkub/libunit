/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:59:33 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/08 17:24:54 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*s2;
	size_t			size;

	i = 0;
	size = ft_strlen(s1);
	if ((s2 = ft_strnew((size))))
	{
		while (i < (unsigned int)size)
		{
			s2[i] = s1[i];
			i++;
		}
		ft_strdel((char **)&s1);
		return (s2);
	}
	else
	{
		return (NULL);
	}
}
