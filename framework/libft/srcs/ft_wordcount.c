/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:31:39 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/08 16:46:59 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(char const *s, char c)
{
	short	is_word;
	size_t	count;

	count = 0;
	is_word = 0;
	if (!s)
		return (count);
	while (*s)
	{
		if ((is_word == 0) && (*s != c))
		{
			is_word = 1;
			count++;
		}
		if ((is_word == 1) && (*s == c))
			is_word = 0;
		s++;
	}
	return (count);
}
