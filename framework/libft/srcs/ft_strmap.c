/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:03:06 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/11 22:38:57 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (f && s && (ret = ft_memalloc(ft_strlen(s) + 1)))
	{
		i = 0;
		while (s[i])
		{
			ret[i] = f(s[i]);
			i++;
		}
		return (ret);
	}
	else
		return (NULL);
}
