/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:16:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/03/16 16:28:21 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		startskips(char const *s, size_t *ptn)
{
	while ((ft_isblank(*s)))
	{
		(*ptn)++;
		s++;
	}
}

static void		endskips(char const *s, size_t *ptn)
{
	s += ft_strlen(s) - 1;
	while ((ft_isblank(*s)))
	{
		(*ptn)++;
		s--;
	}
}

static size_t	ft_trimsize(char const *s, size_t beg, size_t end)
{
	if (ft_strlen(s) != beg)
		return ((ft_strlen((char *)&s[beg]) - end + 1));
	else
		return (1);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	beg;
	size_t	end;

	if (s)
	{
		beg = 0;
		end = 0;
		startskips(s, &beg);
		endskips(s, &end);
		if ((ret = (char *)ft_memalloc(ft_trimsize(s, beg, end))))
		{
			if (beg || end)
				ft_strlcpy(ret, &s[beg], ft_trimsize(s, beg, end));
			else
				ft_strlcpy(ret, s, ft_strlen(s) + 1);
			return (ret);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
