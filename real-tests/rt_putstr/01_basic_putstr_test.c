/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:13:25 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 21:27:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_putstr.h"

int	basic_putstr_test(void)
{
	int		stdout_copy;
	int		fd_pipe[2];
	char	buff[100];

	stdout_copy = stdout_to_pipe(fd_pipe);
	rt_putstr("abc");
	get_pipe_buffer(stdout_copy, fd_pipe, buff, 100);
	if (ft_strcmp(buff, "abc") == 0)
		return (0);
	else
		return (-1);
}
