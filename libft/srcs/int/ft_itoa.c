/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:43:25 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/04 16:13:49 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"

/* ************************************************************************** */
/*  This helper function returns the minimum length to represent int n in     */
/*  string, including negative sign.                                          */
/* ************************************************************************** */
static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n <= -10 || 10 <= n)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

/* ************************************************************************** */
/*  This helper function swaps memory range [left, right].                    */
/* ************************************************************************** */
static void	*ft_memswap(void *left, void *right)
{
	void			*ret;
	unsigned char	tmp;

	ret = left;
	while (left < right)
	{
		tmp = *(unsigned char *)right;
		*(unsigned char *)right = *(unsigned char *)left;
		*(unsigned char *)left = tmp;
		right--;
		left++;
	}
	return (ret);
}

/* ************************************************************************** */
/*  This function allocates (with malloc(3)) and returns a string             */
/*  representing the integer received as an argument.                         */
/* ************************************************************************** */
char	*ft_itoa(int n)
{
	char	*left;
	char	*right;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (ptr == NULL)
		return (NULL);
	left = ptr;
	right = ptr;
	if (n <= 0)
	{
		*left++ = "0-"[n < 0];
		right++;
	}
	while (n != 0)
	{
		*right++ = (n % 10) * (1 - 2 * (n < 0)) + '0';
		n /= 10;
	}
	*right-- = '\0';
	ft_memswap(left, right);
	return (ptr);
}

/* ************************************************************************** */
/*  left points the first character of digits, right points the last.         */
/* ************************************************************************** */
/*  (n % 10) * (1 - 2 * (n < 0)) + '0' means the last character of signed n.  */
/* ************************************************************************** */
