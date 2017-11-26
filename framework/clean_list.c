/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:26:37 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 11:52:27 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	clean_list(t_unit_test **ptr)
{
	t_unit_test	*buf[2];

	if (!ptr)
		return ;
	buf[1] = *ptr;
	while ((buf[0] = buf[1]))
	{
		buf[1] = buf[0]->next;
		free(buf[0]);
		buf[0] = NULL;
	}
	ptr = NULL;
}
