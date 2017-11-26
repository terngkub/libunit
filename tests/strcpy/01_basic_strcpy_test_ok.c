/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_strcpy_test_ok.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:30:39 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 17:37:57 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_strcpy_tests.h"

int		basic_strcpy_test_ok(void)
{
	char	s1[10];
	char	*s2;

	ft_bzero(s1, 10);
	s2 = "Hello";
	if (ft_strequ(test_strcpy(s1, s2), "Hello"))
		return (0);
	else
		return (-1);
}
