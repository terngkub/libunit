/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:39:44 by jdaufin           #+#    #+#             */
/*   Updated: 2017/07/12 21:35:53 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*buf;

	if (alst && new)
	{
		buf = *alst;
		while (buf->next)
			buf = buf->next;
		new->next = NULL;
		buf->next = new;
	}
}
