/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:24:46 by jdaufin           #+#    #+#             */
/*   Updated: 2017/07/06 19:27:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_lstlen(t_list *lst)
{
	ssize_t	ret;
	t_list	*swap;

	if (!lst)
		return (-1);
	swap = lst;
	ret = 0;
	while (swap)
	{
		ret++;
		swap = swap->next;
	}
	return (ret);
}
