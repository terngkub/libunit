/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_unprintable_char_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:52:39 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 21:26:43 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_putchar.h"

int	unprintable_char_test(void)
{
	int		stdout_copy;
	int		fd_pipe[2];
	char	buff[100];
	char	buff2[2];

	stdout_copy = stdout_to_pipe(fd_pipe);
	rt_putchar(1);
	get_pipe_buffer(stdout_copy, fd_pipe, buff, 100);
	buff2[0] = 1;
	buff2[1] = '\0';
	if (ft_strcmp(buff, buff2) == 0)
		return (0);
	else
		return (-1);
}
