/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:07:00 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 15:47:40 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ps_utils.h"

int		arr_to_idx_4(int a, int b, int c, int d);
int		arr_to_idx_5(int a, int b, int *c, int e);
void	idx_to_arr_4(int *arr, int idx);
void	idx_to_arr_5(int *arr, int idx);

void	ps_bfs_enque(t_ps_op *op_arr, int *fifo, int index, t_ps_op op);
void	ps_bfs_sort(t_push_swap ps);
void	ps_bfs_sort_4(t_push_swap ps, int tmp);
void	ps_bfs_sort_5(t_push_swap ps, int tmp);

void	ps_bubble_sort(t_push_swap ps);
void	ps_radix_sort(t_push_swap ps);
void	ps_smart_wheel(int index_a, int index_b, t_push_swap ps);
void	ps_wheel_sort(t_push_swap ps);
void	ps_merge(t_push_swap ps);
char	*ps_rmdup(char *str);

#endif /* PUSH_SWAP_H */
