/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_rt_putstr_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:10:41 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 20:47:39 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_putstr.h"

int	rt_putstr_launcher(void)
{
	t_unit_test	*lst;
	int			ret;

	ft_printf("rt_putstr:\n");
	lst = NULL;
	load_test(&lst, "basic_putstr_test", &basic_putstr_test);
	load_test(&lst, "null_test", &null_test);
	ret = launch_tests(&lst);
	clean_list(&lst);
	return (ret);
}
