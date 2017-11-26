/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:03:36 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/12 16:38:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** lstnew does not free the original content field memory, this operation
** must be done by the caller.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	if ((newlink = (t_list *)ft_memalloc(sizeof(t_list))) && \
			(newlink->content = ft_memalloc(content_size)))
	{
		if (content)
		{
			ft_memcpy(newlink->content, content, content_size);
			newlink->content_size = content_size;
		}
		else
		{
			newlink->content = NULL;
			newlink->content_size = 0;
		}
		newlink->next = (t_list *)NULL;
		return (newlink);
	}
	else
		return ((t_list *)NULL);
}
