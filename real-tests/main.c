/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:12:15 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/26 21:14:38 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "rt_putchar.h"
#include "rt_putstr.h"
#include "rt_atoi.h"

int	main(void)
{
	rt_putchar_launcher();
	rt_putstr_launcher();
	rt_atoi_launcher();
	return (0);
}
