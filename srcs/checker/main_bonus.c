/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:32:50 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/06 15:14:34 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker_bonus.h"

static void	exit_with_status(t_push_swap ps)
{
	int	i;

	if (*ps.size_b == 0)
	{
		i = 0;
		while (i < *ps.size_a - 1)
		{
			if (ps.stack_a[i] > ps.stack_a[i + 1])
			{
				ft_putendl_fd("KO", 1);
				exit(0);
			}
			i++;
		}
		ft_putendl_fd("OK", 1);
	}
	else
		ft_putendl_fd("KO", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		*line;

	if (argc - 1 <= 0)
		return (0);
	ps = ps_get_stacks(argc - 1, (const char **)(argv + 1));
	line = get_next_line(0);
	while (line != NULL)
	{
		if (push_swap(ps, ps_str_to_op(ft_trimnl(line))) != 0)
		{
			free(line);
			exit_with_error();
		}
		free(line);
		line = get_next_line(0);
	}
	exit_with_status(ps);
}
