/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:40:20 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/28 19:05:05 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stabdel(char ***pstab)
{
	ssize_t	i;

	i = -1;
	if (!pstab || !(*pstab))
		return ;
	while ((*pstab)[++i])
		ft_strdel(&((*pstab)[i]));
	ft_memdel((void **)pstab);
}
