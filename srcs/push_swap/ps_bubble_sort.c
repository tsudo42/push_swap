/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:03:00 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/12 15:22:17 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_bubble_sort(t_push_swap ps)
{
	int	i;
	int	size;

	size = *ps.size_a;
	if (size <= 0)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (ps.stack_a[0] == i)
		{
			ps_op_wrapper(PS_PB, ps);
			i++;
		}
		else
			ps_op_wrapper(PS_RA, ps);
	}
	while (--size > 0)
		ps_op_wrapper(PS_PA, ps);
}
