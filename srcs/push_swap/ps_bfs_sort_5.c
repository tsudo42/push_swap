/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bfs_sort_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:46:52 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 15:27:52 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_to_idx_5(int a, int b, int *c, int e)
{
	int	index;

	index = arr_to_idx_4(b, c[0], c[1], e);
	if (a > b)
		index += 24;
	if (a > c[0])
		index += 24;
	if (a > c[1])
		index += 24;
	if (a > e)
		index += 24;
	return (index);
}

void	idx_to_arr_5(int *arr, int idx)
{
	int	i;

	arr[0] = idx / 24;
	idx_to_arr_4(arr + 1, idx % 24);
	i = 1;
	while (i < 5)
	{
		if (arr[0] <= arr[i])
			arr[i]++;
		i++;
	}
}

static int	bf_search_5(t_ps_op op_arr[120], int fifo[122], int index, int dest)
{
	int	arr[5];

	if (index == dest)
		return (1);
	idx_to_arr_5(arr, index);
	ps_bfs_enque(op_arr, fifo, \
		arr_to_idx_5(arr[1], arr[0], &(arr[2]), arr[4]), PS_SA);
	ps_bfs_enque(op_arr, fifo, \
		arr_to_idx_5(arr[4], arr[0], &(arr[1]), arr[3]), PS_RA);
	ps_bfs_enque(op_arr, fifo, \
		arr_to_idx_5(arr[1], arr[2], &(arr[3]), arr[0]), PS_RRA);
	return (0);
}

static void	ps_bfs_finish(t_push_swap ps, t_ps_op *op_arr, int dest)
{
	int	i;

	i = dest;
	while (i != 0)
	{
		ps_op_wrapper(op_arr[i], ps);
		i = arr_to_idx_5(ps.stack_a[0], ps.stack_a[1], \
			&(ps.stack_a[2]), ps.stack_a[4]);
	}
}

void	ps_bfs_sort_5(t_push_swap ps, int tmp)
{
	t_ps_op	op_arr[120];
	int		fifo[122];
	int		ret;
	int		dest;

	tmp = 0;
	while (tmp < 120)
	{
		op_arr[tmp] = PS_INVAL;
		tmp++;
	}
	dest = arr_to_idx_5(ps.stack_a[0], ps.stack_a[1], \
		&(ps.stack_a[2]), ps.stack_a[4]);
	fifo[0] = 2;
	fifo[1] = 2;
	bf_search_5(op_arr, fifo, 0, dest);
	ret = 0;
	while (ret != 1)
	{
		tmp = fifo[fifo[0]++];
		ret = bf_search_5(op_arr, fifo, tmp, dest);
	}
	ps_bfs_finish(ps, op_arr, dest);
}
