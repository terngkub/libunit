/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:10:22 by jdaufin           #+#    #+#             */
/*   Updated: 2016/11/28 22:22:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int diff;

	i = 0;
	diff = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	diff = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (diff);
}
