/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:17:46 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/14 17:45:42 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool		tagend(char c)
{
	char	*check;

	check = "dDiuUoOxXpcCsS%";
	return ((check = ft_strchr(check, c)) && *check ? 1 : 0);
}

ssize_t		get_taglen(const char *s)
{
	ssize_t	ret;

	if (*s != '%')
		return (-1);
	ret = 1;
	while (s[ret] && !tagend(s[ret]))
		++ret;
	return (tagend(s[ret]) ? ++ret : -1);
}

ssize_t		get_len(const char *s)
{
	ssize_t	ret;

	if (!s)
		return (-1);
	ret = 0;
	while (s[ret] && s[ret] != '%')
		ret++;
	return (ret);
}
