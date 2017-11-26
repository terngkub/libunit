/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_rt_putchar_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:28:06 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 18:55:01 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_putchar.h"

int	rt_putchar_launcher(void)
{
	t_unit_test	*lst;
	int			ret;

	ft_printf("rt_putchar:\n");
	lst = NULL;
	load_test(&lst, "basic_test", &basic_test);
	load_test(&lst, "unprintable_char_test", &unprintable_char_test);
	ret = launch_tests(&lst);
	clean_list(&lst);
	return (ret);
}
