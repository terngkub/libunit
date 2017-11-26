/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:06:39 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 20:50:21 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static char	*read_status(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return ("\033[32mOK\033[0m");
		else if (WEXITSTATUS(status) == SIGALRM)
			return ("\033[31mTIMEOUT\033[0m");
	}
	else
	{
		if (WTERMSIG(status) == SIGSEGV)
			return ("\033[31mSIGV\033[0m");
		else if (WTERMSIG(status) == SIGBUS)
			return ("\033[31mBUSE\033[0m");
	}
	return ("\033[31mKO\033[0m");
}

static void	kill_child(int sig)
{
	(void)sig;
	exit(SIGALRM);
}

static void	child_process(t_unit_test **tests)
{
	signal(SIGALRM, kill_child);
	alarm(TIMEOUT_SECONDS);
	exit(((*tests)->test)() == 0 ? 0 : 1);
}

static void	parent_process(char *name, int *point)
{
	int		status;

	status = 0;
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		*point += 1;
	ft_printf("    > %s : [%s]\n", name, read_status(status));
}

int			launch_tests(t_unit_test **tests)
{
	int		point;
	int		full_point;
	pid_t	pid;

	point = 0;
	full_point = 0;
	while (*tests)
	{
		pid = fork();
		if (pid < 0)
			return (-1);
		else if (pid == 0)
			child_process(tests);
		else if (pid > 0)
			parent_process((*tests)->name, &point);
		*tests = (*tests)->next;
		full_point++;
	}
	ft_printf("\n%d/%d tests checked\n", point, full_point);
	return ((point == full_point) ? 0 : -1);
}
