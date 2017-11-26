/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:23:31 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/10 17:29:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	if ((newstr = (char *)ft_memalloc(size + 1)))
	{
		while (i <= (unsigned int)size)
		{
			newstr[i] = '\0';
			i++;
		}
		return (newstr);
	}
	else
		return (NULL);
}
