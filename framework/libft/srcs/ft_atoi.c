/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:44:30 by jdaufin           #+#    #+#             */
/*   Updated: 2017/03/16 16:25:15 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_scan(short *is_neg, const char **pstr)
{
	int i;

	i = 0;
	while (ft_isspace(pstr[0][i]))
		i++;
	if ((pstr[0][i] == '+') || (pstr[0][i] == '-'))
	{
		if (ft_isdigit(pstr[0][i + 1]))
		{
			if (pstr[0][i] == '-')
				*is_neg = 1;
			i++;
		}
		else
			return (-1);
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	const char	*pstr[1];
	int			i;
	int			n;
	short		is_neg;

	pstr[0] = str;
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
