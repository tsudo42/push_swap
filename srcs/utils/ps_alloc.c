/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:49:10 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/06 14:41:14 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	ps_free(t_push_swap *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps->size_a);
	free(ps->size_b);
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->size_a = NULL;
	ps->size_b = NULL;
}

int	ps_alloc(int size, t_push_swap *ps)
{
	if (ps == NULL)
		return (-1);
	ps->stack_a = malloc(sizeof(int) * size);
	ps->stack_b = malloc(sizeof(int) * size);
	ps->size_a = malloc(sizeof(int));
	ps->size_b = malloc(sizeof(int));
	if (ps->stack_a == NULL || ps->size_a == NULL || \
		ps->stack_b == NULL || ps->size_b == NULL)
	{
		ps_free(ps);
		return (-1);
	}
	return (0);
}

int	ps_copy(t_push_swap *dst, const t_push_swap *src)
{
	int	size;

	size = *src->size_a + *src->size_b;
	if (ps_alloc(size, dst) != 0)
		return (-1);
	ft_memcpy(dst->stack_a, src->stack_a, sizeof(int) * (*src->size_a));
	ft_memcpy(dst->stack_b, src->stack_b, sizeof(int) * (*src->size_b));
	dst->size_a = src->size_a;
	dst->size_b = src->size_b;
	return (0);
}
