/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_almost_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:08:00 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/23 16:08:40 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_almost_sorted(int *arr, int arr_size, int min_idx)
{
	int		*dup_arr;
	size_t	lis_len;

	dup_arr = malloc(sizeof(int) * arr_size);
	if (dup_arr == NULL)
		return (-1);
	ft_memmove(dup_arr, arr + min_idx, sizeof(int) * (arr_size - min_idx));
	ft_memmove(dup_arr + (arr_size - min_idx), arr, sizeof(int) * (min_idx));
	lis_len = ft_lis_len(dup_arr, arr_size);
	free(dup_arr);
	if (arr_size - lis_len <= 2)
		return (1);
	return (0);
}

int	ps_almost_sorted(t_push_swap ps)
{
	int	min_idx;

	if (*ps.size_a <= 0)
		return (-1);
	min_idx = ps_min_index(ps.stack_a, *ps.size_a);
	return (check_if_almost_sorted(ps.stack_a, *ps.size_a, min_idx));
}
