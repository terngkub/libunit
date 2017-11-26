/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:17:46 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 21:33:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

_Bool	is_0x(t_tag *tag)
{
	if (tag->type == P || ((tag->type >= X && tag->type <= ZXX) && tag->alter\
				&& !(tag->null_val)))
		return (1);
	return (0);
}