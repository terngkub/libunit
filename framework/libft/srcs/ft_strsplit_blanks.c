/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_blanks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:38:16 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/28 16:31:19 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_wordcount_blanks(char *s)
{
	ssize_t	i;
	size_t	ret;
	_Bool	inword;

	if (!s)
		return (0);
	i = -1;
	ret = 0;
	inword = 0;
	while (s[++i])
	{
		if (ft_isspace(s[i]))
			inword = 0;
		else if (!inword)
		{
			inword = 1;
			ret++;
		}
	}
	return (ret);
}

static unsigned int	nextwd(char *s, unsigned int start)
{
	unsigned int	ret;
	_Bool			inword;

	ret = start;
	if (!s || (start >= ft_strlen(s)) || (!ret && !ft_isspace(s[ret])))
		return (0);
	inword = ft_isspace(s[ret]) ? 0 : 1;
	while (s[ret])
	{
		if (inword)
			while (s[ret] && !ft_isspace(s[ret]))
				ret++;
		while (ft_isspace(s[ret]))
			ret++;
		if (s[ret])
			return (ret);
		else
			return (0);
	}
	return (0);
}

static size_t		ft_wdlen(char *cur)
{
	size_t	ret;

	if (!cur || ft_isspace(*cur))
		return (0);
	ret = 0;
	while (*cur && !ft_isspace(*cur))
	{
		ret++;
		cur++;
	}
	return (ret);
}

char				**ft_strsplit_blanks(char *s)
{
	char			**ret;
	size_t			retsize;
	size_t			i;
	unsigned int	pos;

	retsize = ft_wordcount_blanks(s);
	if (!s || !(ret = (char **)ft_memalloc((retsize + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	pos = 0;
	while (i < retsize)
	{
		pos = i ? nextwd(s, (unsigned int)ft_wdlen(&s[pos]) + pos) \
				: nextwd(s, 0);
		if (i && !pos)
			return (NULL);
		else
			ret[i++] = ft_strsub(s, pos, ft_wdlen(&s[pos]));
	}
	ret[i] = NULL;
	return (ret);
}
