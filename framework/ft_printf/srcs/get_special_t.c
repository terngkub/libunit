/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_special_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:47:00 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/22 14:32:48 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_type	get_p(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "p"))
		ret = P;
	else
		ret = TABEND;
	return (ret);
}

t_type	get_pc(char *s)
{
	t_type	ret;

	if (ft_strstr(s, "%"))
		ret = PC;
	else
		ret = TABEND;
	return (ret);
}
