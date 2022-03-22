/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_wheel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:41:13 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/11 15:59:13 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_smart_wheel_helper_a(int index_a, t_push_swap ps)
{
	int	i;

	i = 0;
	if (index_a < *ps.size_a / 2)
	{
		while (i < index_a)
		{
			ps_op_wrapper(PS_RA, ps);
			i++;
		}
	}
	else
	{
		while (i < *ps.size_a - index_a)
		{
			ps_op_wrapper(PS_RRA, ps);
			i++;
		}
	}
}

static void	ps_smart_wheel_helper_b(int index_b, t_push_swap ps)
{
	int	i;

	i = 0;
	if (index_b < *ps.size_b / 2)
	{
		while (i < index_b)
		{
			ps_op_wrapper(PS_RB, ps);
			i++;
		}
	}
	else
	{
		while (i < *ps.size_b - index_b)
		{
			ps_op_wrapper(PS_RRB, ps);
			i++;
		}
	}
}

void	ps_smart_wheel(int index_a, int index_b, t_push_swap ps)
{
	if (index_a >= 0)
		ps_smart_wheel_helper_a(index_a, ps);
	if (index_b >= 0)
		ps_smart_wheel_helper_b(index_b, ps);
}
