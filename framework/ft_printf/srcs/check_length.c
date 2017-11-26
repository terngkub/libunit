/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:36:13 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/12 21:19:47 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static _Bool	check_length_exit(char ***check, char **ret, _Bool out)
{
	if (!check)
		return (0);
	ft_stabdel(check);
	ft_strdel(ret);
	return (out);
}

_Bool			check_length(char **pts)
{
	char	*ret;
	char	**check;
	size_t	len;
	size_t	i_ret;

	len = 0;
	i_ret = 0;
	if (ft_strchr("hljz", (int)**pts))
	{
		check = ft_strsplit("hh h ll l j z", ' ');
		while (&((*pts)[len]) && !tagend((*pts)[len]))
			len++;
		ret = ft_strsub(*pts, 0, len);
		*pts += len;
		while (check[i_ret])
		{
			if (ft_strequ(ret, check[i_ret]))
				return (check_length_exit(&check, &ret, 1));
			i_ret++;
		}
		return (check_length_exit(&check, &ret, 0));
	}
	return (1);
}
