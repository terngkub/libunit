/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_negative_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:44:30 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 20:58:55 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_atoi.h"

int	negative_test(void)
{
	if (rt_atoi("-123") == -123)
		return (0);
	else
		return (-1);
}