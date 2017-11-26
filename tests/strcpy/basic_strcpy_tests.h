/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_strcpy_tests.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:49:49 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 17:28:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_STRCPY_TESTS_H
# define BASIC_STRCPY_TESTS_H
# include "libunit.h"
# include "libft.h"
# include <string.h>

int		basic_strcpy_launcher(void);
int		basic_strcpy_test_ok(void);
int		basic_strcpy_test_ko(void);
int		basic_strcpy_test_segv(void);
int		basic_strcpy_test_buse(void);

char	*test_strcpy(char *dst, const char *src);

#endif
