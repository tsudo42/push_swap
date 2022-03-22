/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bfs_sort_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:46:52 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 15:27:36 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_to_idx_4(int a, int b, int c, int d)
{
	int	index;

	index = 0;
	if (c > d)
		index++;
	if (b > d)
		index += 2;
	if (b > c)
		index += 2;
	if (a > c)
		index += 6;
	if (a > d)
		index += 6;
	if (a > b)
		index += 6;
	return (index);
}

void	idx_to_arr_4(int *arr, int idx)
{
	int	i;
	int	j;

	arr[0] = idx / 6;
	arr[1] = (idx % 6) / 2;
	arr[2] = idx % 2;
	arr[3] = 0;
	i = 2;
	while (i >= 0)
	{
		j = i + 1;
		while (j < 4)
		{
			if (arr[i] <= arr[j])
				arr[j]++;
			j++;
		}
		i--;
	}
}

static int	bf_search_4(t_ps_op op_arr[24], int fifo[26], int index, int dest)
{
	int	arr[4];

	if (index == dest)
		return (1);
	idx_to_arr_4(arr, index);
	ps_bfs_enque(op_arr, fifo, \
		arr_to_idx_4(arr[1], arr[0], arr[2], arr[3]), PS_SA);
	ps_bfs_enque(op_arr, fifo, \
		arr_to_idx_4(arr[3], arr[0], arr[1], arr[2]), PS_RA);
	ps_bfs_enque(op_arr, fifo, \
		arr_to_idx_4(arr[1], arr[2], arr[3], arr[0]), PS_RRA);
	return (0);
}

static void	ps_bfs_finish(t_push_swap ps, t_ps_op *op_arr, int dest)
{
	int	i;

	i = dest;
	while (i != 0)
	{
		ps_op_wrapper(op_arr[i], ps);
		i = arr_to_idx_4(ps.stack_a[0], ps.stack_a[1], \
			ps.stack_a[2], ps.stack_a[3]);
	}
}

void	ps_bfs_sort_4(t_push_swap ps, int tmp)
{
	t_ps_op	op_arr[24];
	int		fifo[26];
	int		ret;
	int		dest;

	tmp = 0;
	while (tmp < 24)
	{
		op_arr[tmp] = PS_INVAL;
		tmp++;
	}
	dest = arr_to_idx_4(ps.stack_a[0], ps.stack_a[1], \
		ps.stack_a[2], ps.stack_a[3]);
	fifo[0] = 2;
	fifo[1] = 2;
	bf_search_4(op_arr, fifo, 0, dest);
	ret = 0;
	while (ret != 1)
	{
		tmp = fifo[fifo[0]++];
		ret = bf_search_4(op_arr, fifo, tmp, dest);
	}
	ps_bfs_finish(ps, op_arr, dest);
}
