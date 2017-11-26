/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_basic_strcpy_test_buse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:01:18 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 17:32:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_strcpy_tests.h"

int		basic_strcpy_test_buse(void)
{
	char	*s1;
	char	*s2;

	s1 = "AI";
	s2 = "Hello";
	if (test_strcpy(s1, s2))
		return (0);
	else
		return (-1);
}
