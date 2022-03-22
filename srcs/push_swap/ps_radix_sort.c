/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:01:51 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 14:16:30 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	helper(t_push_swap ps, int *shrink_arr, int size, int mask)
{
	int	i;
	int	count;

	ft_memcpy(shrink_arr, ps.stack_a, sizeof(int) * size);
	if (ft_shrinkarr_int(shrink_arr, NULL, size) == -1)
		ft_exit(-1, "Error");
	i = 0;
	count = 0;
	while (i < size)
	{
		if ((shrink_arr[i] & mask) == 0)
		{
			ps_op_wrapper(PS_PB, ps);
			count++;
		}
		else
			ps_op_wrapper(PS_RA, ps);
		i++;
	}
	i = 0;
	while (i < count)
	{
		ps_op_wrapper(PS_PA, ps);
		i++;
	}
}

void	ps_radix_sort(t_push_swap ps)
{
	int	size;
	int	max;
	int	mask;
	int	*shrink_arr;

	size = *ps.size_a;
	shrink_arr = malloc(sizeof(int) * size);
	if (shrink_arr == NULL)
		ft_exit(-1, "Error");
	mask = 1;
	max = size - 1;
	while (max > 0)
	{
		helper(ps, shrink_arr, size, mask);
		mask = mask << 1;
		max >>= 1;
	}
	free(shrink_arr);
}
