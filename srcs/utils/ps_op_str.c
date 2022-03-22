/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:47:47 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/10 20:04:23 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

static t_ps_op	ps_str_to_op_helper(const char *str)
{
	if (str[0] != 'r')
		return (PS_INVAL);
	if (str[1] == 'r')
	{
		if (str[2] == '\0')
			return (PS_RR);
		if (str[2] == 'a' && str[3] == '\0')
			return (PS_RRA);
		if (str[2] == 'b' && str[3] == '\0')
			return (PS_RRB);
		if (str[2] == 'r' && str[3] == '\0')
			return (PS_RRR);
	}
	if (str[1] == 'a' && str[2] == '\0')
		return (PS_RA);
	if (str[1] == 'b' && str[2] == '\0')
		return (PS_RB);
	return (PS_INVAL);
}

t_ps_op	ps_str_to_op(const char *str)
{
	if (str == NULL)
		return (PS_INVAL);
	if (str[0] == 's')
	{
		if (str[1] == 'a' && str[2] == '\0')
			return (PS_SA);
		if (str[1] == 'b' && str[2] == '\0')
			return (PS_SB);
		if (str[1] == 's' && str[2] == '\0')
			return (PS_SS);
	}
	if (str[0] == 'p')
	{
		if (str[1] == 'a' && str[2] == '\0')
			return (PS_PA);
		if (str[1] == 'b' && str[2] == '\0')
			return (PS_PB);
	}
	return (ps_str_to_op_helper(str));
}

static int	ps_op_to_str_helper(t_ps_op op)
{
	if (op == PS_SA)
		return (1);
	if (op == PS_SB)
		return (2);
	if (op == PS_SS)
		return (3);
	if (op == PS_PA)
		return (4);
	if (op == PS_PB)
		return (5);
	if (op == PS_RA)
		return (6);
	if (op == PS_RB)
		return (7);
	if (op == PS_RR)
		return (8);
	if (op == PS_RRA)
		return (9);
	if (op == PS_RRB)
		return (10);
	if (op == PS_RRR)
		return (11);
	return (0);
}

const char	*ps_op_to_str(t_ps_op op)
{
	const char	*strops[12] = {
		NULL,
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};

	return (strops[ps_op_to_str_helper(op)]);
}
