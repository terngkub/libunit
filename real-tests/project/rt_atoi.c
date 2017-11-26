/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:26:22 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 20:57:59 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rt_atoi(const char *str)
{
	int	neg;
	int	num;

	neg = 1;
	num = 0;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * neg);
}