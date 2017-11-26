/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:18:23 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/01 19:18:49 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_compute(long l, size_t *plen)
{
	while ((l /= 10) > 9)
		(*plen)++;
	(*plen)++;
}

static void	ft_fill(char **pret, long l, short is_neg, size_t len)
{
	char	*ret;

	ret = *pret;
	ret += len;
	if (l == 0)
		*(--ret) = (char)48;
	while ((l /= 10))
		*(--ret) = (char)((l % 10) + 48);
	if (is_neg)
		*(--ret) = '-';
}

char		*ft_itoa(int n)
{
	short	is_neg;
	size_t	len;
	char	*ret;
	long	l;

	is_neg = 0;
	len = 0;
	l = (long)n * 10;
	if (l < 0)
	{
		is_neg = 1;
		l *= -1;
	}
	ft_compute(l, &len);
	if (is_neg)
		len++;
	if ((ret = ft_strnew(len)))
	{
		ft_fill(&ret, l, is_neg, len);
		return (ret);
	}
	return (NULL);
}
