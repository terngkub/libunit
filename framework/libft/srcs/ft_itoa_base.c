/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:58:19 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/28 19:03:43 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	check_base(char *base)
{
	char	*res;
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!base || (len = ft_strlen(base)) < 2)
		return (0);
	res = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		if (i > 0 && ((tmp = ft_strchr(res, (int)base[i])) \
					|| !ft_isalnum(base[i])))
			return (0);
		res[i] = base[i];
		i++;
	}
	if (tmp)
		ft_memdel((void **)&tmp);
	if (res)
		ft_memdel((void **)&res);
	return (1);
}

static size_t	get_length(intmax_t nbr, size_t base_len)
{
	size_t	i;

	i = (nbr ? 0 : 1);
	while (nbr)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(intmax_t nbr, char *base)
{
	ssize_t	i;
	size_t	base_len;
	size_t	len;
	_Bool	neg;
	char	*ret;

	if (!check_base(base))
		return (NULL);
	base_len = ft_strlen(base);
	neg = (nbr < 0 ? 1 : 0);
	nbr = (neg ? -nbr : nbr);
	len = get_length(nbr, base_len);
	i = (neg ? len + 1 : len);
	ret = ft_strnew(i);
	while (--i > -1)
	{
		if (!nbr && neg)
			ret[i] = '-';
		else
			ret[i] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (ret);
}
