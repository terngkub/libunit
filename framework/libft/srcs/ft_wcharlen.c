/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:09:47 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/20 23:21:22 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	WARNING : this function is not designed to handle the private unicode
**	planes, ie values from 0x200000 to 0x7FFFFFFF. Please rewrite it if
**	needed.
*/

ssize_t	ft_wcharlen(wchar_t wcr)
{
	ssize_t	ret;

	ret = 0;
	if (wcr < 0)
		ret = -1;
	else if (wcr < 0x80)
		ret = 1;
	else if (wcr < 0x800)
		ret = 2;
	else if (wcr < 0x10000)
		ret = 3;
	else if (wcr < 0x200000)
		ret = 4;
	else
		ret = -1;
	return (ret);
}
