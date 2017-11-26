/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:56:11 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/11 22:45:27 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (f && s && (ret = ft_memalloc(ft_strlen(s) + 1)))
	{
		i = 0;
		while (s[i])
		{
			ret[i] = f(i, s[i]);
			i++;
		}
		return (ret);
	}
	else
		return (NULL);
}
