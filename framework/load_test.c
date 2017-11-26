/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:47:13 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/25 19:14:12 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_unit_test	*new_test(char *name, int (*test)(void))
{
	t_unit_test	*list;

	if (!(list = (t_unit_test *)malloc(sizeof(t_unit_test))))
		return (NULL);
	list->name = name;
	list->test = test;
	list->next = NULL;
	return (list);
}

void		load_test(t_unit_test **testlist, char *name, int (*test)(void))
{
	t_unit_test	*tmp;

	if (*testlist == NULL)
		*testlist = new_test(name, test);
	else
	{
		tmp = *testlist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_test(name, test);
	}
}
