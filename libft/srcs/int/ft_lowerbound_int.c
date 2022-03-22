/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerbound_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:35:55 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/05 23:19:28 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"

/* ************************************************************************** */
/*  This function returns the index of key in sorted_arr if exists.           */
/*  Otherwise, returns idx where sorted_arr[idx-1] < key < sorted_arr[idx].   */
/* ************************************************************************** */
size_t	ft_lowerbound_int(int key, int *sorted_arr, size_t size)
{
	size_t	left;
	size_t	right;
	size_t	mid_left;
	size_t	mid_right;

	if (size == 0)
		return (1);
	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid_left = (left + right) / 2;
		mid_right = (left + right + 1) / 2;
		if (key == sorted_arr[mid_left])
			return (mid_left);
		else if (key == sorted_arr[mid_right])
			return (mid_right);
		else if (key > sorted_arr[mid_right])
			left = mid_right + 1;
		else if (mid_left == 0)
			break ;
		else
			right = mid_left - 1;
	}
	return (mid_right + 1);
}
