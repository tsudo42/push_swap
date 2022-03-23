/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:32:41 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/11 15:58:24 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

# include "libft.h"

typedef enum e_ps_op
{
	PS_SA = 0x1,
	PS_SB = 0x2,
	PS_SS = 0x3,
	PS_PA = 0x10,
	PS_PB = 0x20,
	PS_RA = 0x100,
	PS_RB = 0x200,
	PS_RR = 0x300,
	PS_RRA = 0x1000,
	PS_RRB = 0x2000,
	PS_RRR = 0x3000,
	PS_INVAL = 0x0
}	t_ps_op;

typedef struct s_push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	*size_a;
	int	*size_b;
}	t_push_swap;

void		ps_free(t_push_swap *ps);
int			ps_alloc(int size, t_push_swap *ps);
int			ps_copy(t_push_swap *dst, const t_push_swap *src);
void		exit_with_error(void);
void		ps_free_and_abort(t_push_swap sp);
t_push_swap	ps_get_stacks(int argc, const char **argv);
int			push_swap(t_push_swap ps, t_ps_op op);
t_ps_op		ps_str_to_op(const char *str);
const char	*ps_op_to_str(t_ps_op op);
char		*ps_store_str(const char *str);
void		ps_op_wrapper(t_ps_op op, t_push_swap ps);
int			ps_min_index(int *arr, int size);
int			ps_max_index(int *arr, int size);

#endif /* PS_UTILS_H */
