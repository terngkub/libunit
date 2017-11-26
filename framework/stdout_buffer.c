/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:23:51 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 17:24:07 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int		stdout_to_pipe(int *fd_pipe)
{
	int		stdout_copy;

	stdout_copy = dup(STDOUT_FILENO);
	pipe(fd_pipe);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[1]);
	return (stdout_copy);
}

char	*get_pipe_buffer(int stdout_copy, int *fd_pipe, char *buff, size_t size)
{
	int		ret;

	ret = read(fd_pipe[0], buff, size);
	if (ret != -1)
		buff[ret] = '\0';
	dup2(stdout_copy, STDOUT_FILENO);
	close(fd_pipe[0]);
	return (buff);
}
