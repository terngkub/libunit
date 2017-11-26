/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:06:26 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/28 19:38:22 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*memarea;

	if ((memarea = malloc(size)))
	{
		ft_bzero(memarea, size);
		return (memarea);
	}
	else
		return (NULL);
}
