/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:45:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/20 13:02:52 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_scan(_Bool *is_neg, const char **pstr)
{
	ssize_t	i;

	i = 0;
	while (ft_isspace((*pstr)[i]))
		i++;
	if (((*pstr)[i] == '+') || ((*pstr)[i] == '-'))
	{
		if (ft_isdigit((*pstr)[i + 1]))
		{
			if ((*pstr)[i] == '-')
				*is_neg = 1;
			i++;
		}
		else
			return (-1);
	}
	return (i);
}

intmax_t		ft_atoimax(const char *str)
{
	const char	*pstr[1];
	ssize_t		i;
	intmax_t	n;
	_Bool		is_neg;

	(*pstr) = str;
	i = 0;
	n = 0;
	is_neg = 0;
	if ((i = ft_scan(&is_neg, pstr)) != -1)
	{
		while (ft_isdigit(str[i]))
		{
			n = 10 * n + (str[i] - 48);
			i++;
		}
		if (is_neg)
			return (-n);
		else
			return (n);
	}
	else
		return (0);
}
