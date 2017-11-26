/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:43:21 by jdaufin           #+#    #+#             */
/*   Updated: 2017/04/27 20:23:09 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool		ft_parse(t_tag *tag, char *s)
{
	if (!s)
		return (1);
	s++;
	if (*s == '%')
		return (1);
	if (check_flags(tag, &s))
		if (check_width(tag, &s))
			if (check_prec(tag, &s))
				if (check_length(&s))
					if (tagend(*s))
						return (1);
	return (0);
}
