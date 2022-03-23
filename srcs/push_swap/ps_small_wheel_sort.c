/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_wheel_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:08:00 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/23 16:08:40 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_small_wheel_sort(t_push_swap ps)
{
	size_t	lis_len;
	int		count;
	int		index_a;

	if (*ps.size_a <= 0)
		return ;
	count = 0;
	lis_len = ft_lis_len(ps.stack_a, *ps.size_a);
	if (lis_len == 0)
		ft_exit(-1, "Error");
	while ((int)lis_len < *ps.size_a)
	{
		index_a = ps_min_index(ps.stack_a, *ps.size_a);
		ps_smart_wheel(index_a, -1, ps);
		ps_op_wrapper(PS_PB, ps);
		count++;
		lis_len = ft_lis_len(ps.stack_a, *ps.size_a);
		if (lis_len == 0)
			ft_exit(-1, "Error");
	}
	while (count > 0)
	{
		ps_op_wrapper(PS_PA, ps);
		count--;
	}
}
