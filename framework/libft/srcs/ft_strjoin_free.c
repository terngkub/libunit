/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:23:34 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/02 12:28:49 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, _Bool b1, char const *s2, _Bool b2)
{
	char	*ret;
	size_t	retsize;

	if (s1 && s2)
	{
		retsize = ft_strlen(s1) + ft_strlen(s2) + 1;
		if ((ret = (char *)ft_memalloc(retsize)))
		{
			ft_strlcpy(ret, s1, retsize);
			ft_strlcat(ret, s2, retsize);
			if (b1)
				ft_memdel((void **)&s1);
			if (b2)
				ft_memdel((void **)&s2);
			return (ret);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
