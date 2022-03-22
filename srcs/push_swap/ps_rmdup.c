/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rmdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:26:44 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 16:00:31 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	helper_push(t_ps_op op)
{
	static int	pa_count;

	if (op != PS_PA && op != PS_PB)
	{
		while (pa_count > 0)
		{
			ft_wrapped_puts(ps_op_to_str(PS_PA), -1, "Error");
			pa_count--;
		}
		while (pa_count < 0)
		{
			ft_wrapped_puts(ps_op_to_str(PS_PB), -1, "Error");
			pa_count++;
		}
	}
	if (op == PS_PA)
		pa_count++;
	if (op == PS_PB)
		pa_count--;
}

static void	helper_swap(t_ps_op op)
{
	static int	sa_count;
	static int	sb_count;

	if (op != PS_SA && op != PS_SB && op != PS_SS)
	{
		if (sa_count % 2 == 1 && sb_count % 2 == 1)
			ft_wrapped_puts(ps_op_to_str(PS_SS), -1, "Error");
		else if (sa_count % 2 == 1)
			ft_wrapped_puts(ps_op_to_str(PS_SA), -1, "Error");
		else if (sb_count % 2 == 1)
			ft_wrapped_puts(ps_op_to_str(PS_SB), -1, "Error");
		sa_count = 0;
		sb_count = 0;
	}
	if (op == PS_SA || op == PS_SS)
		sa_count++;
	if (op == PS_SB || op == PS_SS)
		sb_count++;
}

static void	helper_reset_rotate(int ra_count, int rb_count)
{
	while (ra_count < 0 && rb_count < 0)
	{
		ft_wrapped_puts(ps_op_to_str(PS_RRR), -1, "Error");
		ra_count++;
		rb_count++;
	}
	while (ra_count > 0)
	{
		ft_wrapped_puts(ps_op_to_str(PS_RA), -1, "Error");
		ra_count--;
	}
	while (ra_count < 0)
	{
		ft_wrapped_puts(ps_op_to_str(PS_RRA), -1, "Error");
		ra_count++;
	}
	while (rb_count > 0)
	{
		ft_wrapped_puts(ps_op_to_str(PS_RB), -1, "Error");
		rb_count--;
	}
	while (rb_count++ < 0)
		ft_wrapped_puts(ps_op_to_str(PS_RRB), -1, "Error");
}

static void	helper_rotate(t_ps_op op)
{
	static int	ra_count;
	static int	rb_count;

	if (op != PS_RA && op != PS_RB && op != PS_RRA && op != PS_RRB && \
		op != PS_RR && op != PS_RRR)
	{
		while (ra_count > 0 && rb_count > 0)
		{
			ft_wrapped_puts(ps_op_to_str(PS_RR), -1, "Error");
			ra_count--;
			rb_count--;
		}
		helper_reset_rotate(ra_count, rb_count);
		ra_count = 0;
		rb_count = 0;
	}
	if (op == PS_RA || op == PS_RR)
		ra_count++;
	if (op == PS_RB || op == PS_RR)
		rb_count++;
	if (op == PS_RRA || op == PS_RRR)
		ra_count--;
	if (op == PS_RRB || op == PS_RRR)
		rb_count--;
}

char	*ps_rmdup(char *str)
{
	t_ps_op	op;
	char	*op_str;

	op_str = ft_strtok(str, "\n");
	while (op_str != NULL)
	{
		op = ps_str_to_op(op_str);
		helper_push(op);
		helper_swap(op);
		helper_rotate(op);
		op_str = ft_strtok(NULL, "\n");
	}
	helper_push(PS_INVAL);
	helper_swap(PS_INVAL);
	helper_rotate(PS_INVAL);
	return (str);
}
