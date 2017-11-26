/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:26:10 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/11 21:42:53 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ib;
	size_t	jb;
	size_t	il;
	char	*ret;

	ib = 0;
	if (ft_strlen(little))
	{
		while (big[ib] && (ib < len))
		{
			il = 0;
			jb = ib;
			while ((big[jb]) && (big[jb] == little[il]) \
					&& (jb < len))
			{
				jb++;
				if (!(little[++il]))
					return ((ret = (char *)&big[ib]));
			}
			ib++;
		}
		return (NULL);
	}
	else
		return ((ret = (char *)big));
}
