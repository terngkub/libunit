/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:51:14 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/08 20:53:23 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*head;

	if (lst && f)
	{
		buf = f(lst);
		head = buf;
		while ((lst = lst->next))
		{
			if (buf)
				buf->next = f(lst);
			else
				return ((t_list *)NULL);
			buf = buf->next;
		}
		return (head);
	}
	else
		return ((t_list *)NULL);
}
