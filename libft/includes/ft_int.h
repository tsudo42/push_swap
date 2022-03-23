/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:13:01 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/12 14:47:42 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_H
# define FT_INT_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include "ft_char.h"
# include "ft_mem.h"
# include "ft_string.h"

int		ft_atoi(const char *str);
void	ft_heapify_int(int *lst, int size);
void	ft_heapsort_int(int *lst, int size);
int		ft_index(int key, int *arr, int size);
int		ft_isintstr(const char *str);
char	*ft_itoa(int n);
size_t	ft_lis_len(const int *arr, size_t size);
size_t	ft_lowerbound_int(int key, int *sorted_arr, size_t size);
size_t	ft_nbrlen(intmax_t n, int base);
int		ft_numstrcmp(const char *s1, const char *s2);
int		ft_shrinkarr_int(int *arr, int *sorted_arr, int size);
size_t	ft_unbrlen(uintmax_t n, unsigned int base);

#endif /* FT_INT_H */
