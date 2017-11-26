/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:34:25 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/28 22:27:52 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	if (n)
	{
		while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && (i < (n - 1)))
			i++;
		diff = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (diff);
}
