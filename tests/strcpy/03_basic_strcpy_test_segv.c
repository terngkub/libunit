/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_basic_strcpy_test_segv.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:57:37 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 17:32:03 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_strcpy_tests.h"

int		basic_strcpy_test_segv(void)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = "Hello";
	if (test_strcpy(s1, s2))
		return (0);
	else
		return (-1);
}
