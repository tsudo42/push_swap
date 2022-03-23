/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_wheel_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:23:00 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 14:17:27 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_b(int val, t_push_swap ps)
{
	int	i;
	int	left;
	int	max;

	i = 0;
	left = -1;
	max = 0;
	while (i < *ps.size_b)
	{
		if (left < ps.stack_b[i] && ps.stack_b[i] < val)
			left = ps.stack_b[i];
		if (max < ps.stack_b[i])
			max = ps.stack_b[i];
		i++;
	}
	if (left == -1)
		return (ft_index(max, ps.stack_b, *ps.size_b));
	return (ft_index(left, ps.stack_b, *ps.size_b));
}

static int	calc_min_op(int index_a, int index_b, t_push_swap ps)
{
	int	min;
	int	tmp;

	min = *ps.size_a - index_a + index_b;
	tmp = index_a + *ps.size_b - index_b;
	if (min > tmp)
		min = tmp;
	tmp = index_a;
	if (tmp < index_b)
		tmp = index_b;
	if (min > tmp)
		min = tmp;
	tmp = *ps.size_a - index_a;
	if (tmp < *ps.size_b - index_b)
		tmp = *ps.size_b - index_b;
	if (min > tmp)
		min = tmp;
	return (min);
}

static int	ps_wheel_sort_helper_2(int i, int *min, int save, t_push_swap ps)
{
	int	tmp;

	tmp = get_index_b(ps.stack_a[i], ps);
	tmp = calc_min_op(i, tmp, ps);
	if (*min > tmp)
	{
		*min = tmp;
		return (i);
	}
	return (save);
}

static int	ps_wheel_sort_helper(t_push_swap ps)
{
	int	i;
	int	min;
	int	save;

	i = 0;
	save = -1;
	min = *ps.size_a + *ps.size_b;
	while (i < min && i < *ps.size_a)
	{
		if (i != 0)
			save = ps_wheel_sort_helper_2(*ps.size_a - i, &min, save, ps);
		save = ps_wheel_sort_helper_2(i, &min, save, ps);
		i++;
	}
	return (save);
}

void	ps_wheel_sort(t_push_swap ps)
{
	int	size;
	int	index_a;
	int	index_b;

	size = *ps.size_a;
	ps_op_wrapper(PS_PB, ps);
	ps_op_wrapper(PS_PB, ps);
	index_a = ps_wheel_sort_helper(ps);
	while (index_a != -1 && *ps.size_a > size / 50 + 1)
	{
		index_b = get_index_b(ps.stack_a[index_a], ps);
		ps_smart_wheel(index_a, index_b, ps);
		ps_op_wrapper(PS_PB, ps);
		index_a = ps_wheel_sort_helper(ps);
	}
	if (*ps.size_a > 0)
	{
		if (*ps.size_a <= 5)
			ps_bfs_sort(ps);
		else if (ps_almost_sorted(ps) == 1)
			ps_small_wheel_sort(ps);
		else
			ps_radix_sort(ps);
	}
	ps_merge(ps);
}
