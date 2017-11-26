/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:06:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/03/10 17:34:37 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **addr, size_t oldsize, size_t newsize)
{
	void	*swap;

	if (!addr)
		return (NULL);
	if (!(*addr && oldsize && newsize))
		return (NULL);
	swap = ft_memalloc(oldsize);
	ft_memmove(swap, *addr, oldsize);
	ft_memdel(addr);
	*addr = ft_memalloc(newsize);
	*addr = ft_memmove(*addr, swap, oldsize);
	ft_memdel(&swap);
	return (*addr);
}
