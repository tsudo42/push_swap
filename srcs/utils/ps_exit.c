/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:47:27 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/04 18:55:15 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	exit_with_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(-1);
}

void	ps_free_and_abort(t_push_swap sp)
{
	free(sp.stack_a);
	free(sp.stack_b);
	free(sp.size_a);
	free(sp.size_b);
	ft_putendl_fd("Error", 2);
	exit(-1);
}
