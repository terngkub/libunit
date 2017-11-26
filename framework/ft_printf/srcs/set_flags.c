/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:13:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/04 17:43:14 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_flags(t_tag *tag, char *flags)
{
	if (tag && flags)
	{
		tag->alter = ft_strchr(flags, (int)'#') ? 1 : 0;
		tag->padding->zeroes = ft_strchr(flags, (int)'0') ? 1 : 0;
		tag->padding->neg_width = ft_strchr(flags, (int)'-') ? 1 : 0;
		tag->prefix->space = ft_strchr(flags, (int)' ') ? 1 : 0;
		tag->prefix->plus = ft_strchr(flags, (int)'+') ? 1 : 0;
	}
}
