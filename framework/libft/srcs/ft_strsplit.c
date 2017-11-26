/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:21:49 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/12 23:04:49 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wdlen(char const *sub, char c)
{
	size_t	len;

	len = 0;
	if (!sub)
		return (0);
	while (sub[len] && (sub[len] != c))
		len++;
	return (len);
}

static char		*nextwd(char const *s, char c)
{
	size_t	count;
	char	*ret;

	if (s)
	{
		count = 0;
		while (s[count] && (s[count] == c))
			count++;
		if (s[count])
			return ((ret = (char *)&s[count]));
		else
			return (NULL);
	}
	return (NULL);
}

static void		set_wdmap(t_str **pmap, char const *s, char c)
{
	size_t	i;

	i = 0;
	if (*s != c && *s)
	{
		(*pmap)[i].addr = (char *)s;
		(*pmap)[i].len = wdlen(s, c);
	}
	else
	{
		(*pmap)[i].addr = nextwd(s, c);
		(*pmap)[i].len = wdlen((*pmap)[i].addr, c);
	}
	while ((*pmap)[i].addr != NULL)
	{
		i++;
		(*pmap)[i].addr = nextwd((*pmap)[i - 1].addr + (*pmap)[i - 1].len, c);
		(*pmap)[i].len = wdlen((*pmap)[i].addr, c);
	}
}

static void		settab(char ***ptab, t_str **pmap)
{
	char	**tab;
	t_str	*map;
	size_t	i;

	tab = *ptab;
	map = *pmap;
	i = 0;
	while (map[i].addr != NULL)
	{
		tab[i] = (char *)ft_memalloc(map[i].len + 1);
		ft_strlcpy(tab[i], map[i].addr, map[i].len + 1);
		i++;
	}
	tab[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	t_str	*map;
	size_t	retsize;

	if (s)
	{
		retsize = ft_wordcount(s, c);
		if ((map = (t_str *)ft_memalloc((retsize + 1) * (sizeof(t_str)))))
		{
			set_wdmap(&map, s, c);
			if ((ret = (char **)ft_memalloc((retsize + 1) * sizeof(char *))))
			{
				settab(&ret, &map);
				ft_memdel((void **)&map);
				return (ret);
			}
			ft_memdel((void **)&map);
		}
	}
	return (NULL);
}
