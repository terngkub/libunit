/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_unconvertible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:34:23 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/14 20:42:45 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	fmt_unconvertible(void **addr)
{
	if (addr && *addr)
	{
		*addr = (void *)ft_strsub_free((char *)*addr,\
				1, ft_strlen((char *)*addr));
	}
}
