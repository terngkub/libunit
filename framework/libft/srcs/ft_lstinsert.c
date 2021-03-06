/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:54:37 by jdaufin           #+#    #+#             */
/*   Updated: 2017/10/09 16:58:32 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **addr, t_list *new)
{
	if (addr && *addr && new)
	{
		new->next = (*addr)->next;
		(*addr)->next = new;
	}
}
