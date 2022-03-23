/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:08:00 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/23 16:08:40 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

int	ps_min_index(int *arr, int size)
{
	int	i;
	int	min_val;
	int	min_idx;

	if (arr == NULL || size <= 0)
		return (-1);
	min_val = arr[0];
	min_idx = 0;
	i = 0;
	while (i < size)
	{
		if (min_val > arr[i])
		{
			min_val = arr[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	ps_max_index(int *arr, int size)
{
	int	i;
	int	max_val;
	int	max_idx;

	if (arr == NULL || size <= 0)
		return (-1);
	max_val = arr[0];
	max_idx = 0;
	i = 0;
	while (i < size)
	{
		if (max_val < arr[i])
		{
			max_val = arr[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}
