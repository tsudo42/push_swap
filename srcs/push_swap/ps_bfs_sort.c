/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bfs_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:16:38 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 15:29:48 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_swap_a(t_push_swap ps)
{
	if (*ps.size_a < 2)
		return ;
	if (ps.stack_a[0] > ps.stack_a[1])
		ps_op_wrapper(PS_SA, ps);
}

static void	ps_bfs_sort_3(t_push_swap ps)
{
	if (*ps.size_a == 3)
	{
		if (ps.stack_a[0] > ps.stack_a[1] && ps.stack_a[0] > ps.stack_a[2])
			ps_op_wrapper(PS_RA, ps);
		else if (ps.stack_a[0] < ps.stack_a[1] && ps.stack_a[1] > ps.stack_a[2])
			ps_op_wrapper(PS_RRA, ps);
	}
	ps_swap_a(ps);
}

void	ps_bfs_enque(t_ps_op *op_arr, int *fifo, int index, t_ps_op op)
{
	if (op_arr[index] != PS_INVAL)
		return ;
	op_arr[index] = op;
	fifo[fifo[1]] = index;
	fifo[1]++;
}

void	ps_bfs_sort(t_push_swap ps)
{
	if (*ps.size_a <= 3)
		ps_bfs_sort_3(ps);
	else if (*ps.size_a == 4)
		ps_bfs_sort_4(ps, 0);
	else if (*ps.size_a == 5)
		ps_bfs_sort_5(ps, 0);
}
