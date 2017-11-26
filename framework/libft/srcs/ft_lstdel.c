/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 22:31:47 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/07 21:11:40 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;
	t_list	*next;

	buf = *alst;
	while (buf)
	{
		next = buf->next;
		ft_lstdelone(&buf, del);
		buf = next;
	}
	*alst = NULL;
}
