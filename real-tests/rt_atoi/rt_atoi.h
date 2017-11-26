/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 20:12:43 by nkamolba          #+#    #+#             */
/*   Updated: 2017/11/26 20:58:17 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ATOI_H
# define RT_ATOI_H

# include "libunit.h"

int	rt_atoi(const char *str);
int	rt_atoi_launcher(void);
int	basic_atoi_test(void);
int	zero_test(void);
int	negative_test(void);
int	plus_sign_test(void);
int	space_test(void);
int	space_plus_test(void);
int	space_negative_test(void);
int	word_after_test(void);
int	zero_before_num_test(void);
int	zero_before_neg_num_test(void);
int	multiple_zero_test(void);

#endif
