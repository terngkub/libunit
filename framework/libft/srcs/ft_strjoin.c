/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:18:26 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/21 17:36:07 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
			return (ret);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
