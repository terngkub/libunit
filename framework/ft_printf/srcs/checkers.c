/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:49:34 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 20:43:04 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	cflags_init(char **flags, char **res, size_t *i)
{
	*flags = "#0-+ ";
	*res = ft_strnew(5);
	*i = 0;
}

_Bool		check_flags(t_tag *tag, char **pts)
{
	char	*flags;
	char	*res;
	char	c;
	size_t	i;

	cflags_init(&flags, &res, &i);
	c = **pts;
	if (ft_strchr(flags, (int)c))
	{
		while (ft_strchr(flags, (int)c) && **pts)
		{
			if (!ft_strchr(res, (int)c))
				res[i++] = c;
			(*pts)++;
			c = **pts;
		}
		set_flags(tag, res);
	}
	ft_memdel((void **)&res);
	return (1);
}

_Bool		check_width(t_tag *tag, char **pts)
{
	char	*width;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (ft_isdigit((int)**pts))
	{
		while (&((*pts)[len]) && ft_isdigit((int)((*pts)[len])))
			len++;
		width = ft_strnew(len);
		while (i < len)
		{
			width[i++] = **pts;
			(*pts)++;
		}
		tag->width = ft_atoi(width);
		ft_memdel((void **)&width);
	}
	return (1);
}

_Bool		check_prec(t_tag *tag, char **pts)
{
	char	*prec;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	tag->precision = (**pts == '.' ? 0 : -1);
	if (**pts == '.')
	{
		if (!ft_isdigit((int)*(++(*pts))))
			return (1);
		while (&((*pts)[len]) && ft_isdigit((int)(*pts)[len]))
			len++;
		prec = ft_strnew(len);
		while (i < len)
		{
			prec[i++] = **pts;
			(*pts)++;
		}
		tag->precision = ft_atoi(prec);
		ft_memdel((void **)&prec);
	}
	return (1);
}
