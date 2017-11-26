/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_strcpy_test_ko.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:34:08 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 17:40:36 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_strcpy_tests.h"

int		basic_strcpy_test_ko(void)
{
	char	s1[10];
	char	*s2;

	ft_memset(s1, 42, 10);
	s2 = "Hello";
	if (ft_strequ(test_strcpy(s1, s2), "Hello"))
		return (0);
	else
		return (-1);
}
