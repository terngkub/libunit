/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_word_after_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:50:18 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 19:51:05 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_atoi.h"

int	word_after_test(void)
{
	if (rt_atoi("123abc") == 123)
		return (0);
	else
		return (-1);
}
