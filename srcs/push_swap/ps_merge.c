/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 03:00:28 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 14:16:38 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	b_max_index(t_push_swap ps)
{
	int	i;
	int	max;
	int	max_index;

	max = 0;
	i = 0;
	while (i < *ps.size_b)
	{
		if (max < ps.stack_b[i])
		{
			max = ps.stack_b[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

void	ps_merge(t_push_swap ps)
{
	int	i;
	int	*tmp_a;
	int	size_a;

	size_a = *ps.size_a;
	tmp_a = ft_memdup(ps.stack_a, sizeof(int) * size_a);
	if (tmp_a == NULL)
		ft_exit(-1, "Error");
	i = size_a - 1;
	while (i >= 0)
	{
		ps_smart_wheel(0, b_max_index(ps), ps);
		while (*ps.size_b > 0 && tmp_a[i] < ps.stack_b[0])
			ps_op_wrapper(PS_PA, ps);
		ps_op_wrapper(PS_RRA, ps);
		i--;
	}
	while (*ps.size_b > 0)
		ps_op_wrapper(PS_PA, ps);
	free(tmp_a);
}
