/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:44:11 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/06 15:13:59 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

static void	swap(t_push_swap ps, t_ps_op op)
{
	int	tmp;

	if ((op == PS_SA || op == PS_SS) && *ps.size_a >= 2)
	{
		tmp = ps.stack_a[1];
		ps.stack_a[1] = ps.stack_a[0];
		ps.stack_a[0] = tmp;
	}
	if ((op == PS_SB || op == PS_SS) && *ps.size_b >= 2)
	{
		tmp = ps.stack_b[1];
		ps.stack_b[1] = ps.stack_b[0];
		ps.stack_b[0] = tmp;
	}
}

static void	push(t_push_swap ps, t_ps_op op)
{
	int	i;
	int	*tmp;

	if (op == PS_PA && *ps.size_b >= 1)
	{
		i = *ps.size_a;
		while (--i >= 0)
			ps.stack_a[i + 1] = ps.stack_a[i];
		(*ps.size_a)++;
		ps.stack_a[0] = ps.stack_b[0];
		i = -1;
		while (++i < *ps.size_b - 1)
			ps.stack_b[i] = ps.stack_b[i + 1];
		(*ps.size_b)--;
	}
	else if (op == PS_PB && *ps.size_a >= 1)
	{
		tmp = ps.stack_b;
		ps.stack_b = ps.stack_a;
		ps.stack_a = tmp;
		tmp = ps.size_b;
		ps.size_b = ps.size_a;
		ps.size_a = tmp;
		push(ps, PS_PA);
	}
}

static void	rotate(t_push_swap ps, t_ps_op op)
{
	int	tmp;
	int	i;

	if ((op == PS_RA || op == PS_RR) && *ps.size_a > 1)
	{
		tmp = ps.stack_a[0];
		i = 0;
		while (i < *ps.size_a - 1)
		{
			ps.stack_a[i] = ps.stack_a[i + 1];
			i++;
		}
		ps.stack_a[*ps.size_a - 1] = tmp;
	}
	if ((op == PS_RB || op == PS_RR) && *ps.size_b > 1)
	{
		tmp = ps.stack_b[0];
		i = 0;
		while (i < *ps.size_b - 1)
		{
			ps.stack_b[i] = ps.stack_b[i + 1];
			i++;
		}
		ps.stack_b[*ps.size_b - 1] = tmp;
	}
}

static void	reverse(t_push_swap ps, t_ps_op op)
{
	int	tmp;
	int	i;

	if ((op == PS_RRA || op == PS_RRR) && *ps.size_a > 1)
	{
		tmp = ps.stack_a[*ps.size_a - 1];
		i = *ps.size_a - 2;
		while (i >= 0)
		{
			ps.stack_a[i + 1] = ps.stack_a[i];
			i--;
		}
		ps.stack_a[0] = tmp;
	}
	if ((op == PS_RRB || op == PS_RRR) && *ps.size_b > 1)
	{
		tmp = ps.stack_b[*ps.size_b - 1];
		i = *ps.size_b - 2;
		while (i >= 0)
		{
			ps.stack_b[i + 1] = ps.stack_b[i];
			i--;
		}
		ps.stack_b[0] = tmp;
	}
}

int	push_swap(t_push_swap ps, t_ps_op op)
{
	if (op == PS_SA || op == PS_SB || op == PS_SS)
		swap(ps, op);
	else if (op == PS_PA || op == PS_PB)
		push(ps, op);
	else if (op == PS_RA || op == PS_RB || op == PS_RR)
		rotate(ps, op);
	else if (op == PS_RRA || op == PS_RRB || op == PS_RRR)
		reverse(ps, op);
	else
		return (-1);
	return (0);
}
