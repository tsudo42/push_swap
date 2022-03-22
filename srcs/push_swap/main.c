/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:59:02 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 15:47:27 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		*str;

	if (argc - 1 <= 0)
		return (0);
	ps = ps_get_stacks(argc - 1, (const char **)(argv + 1));
	if (*ps.size_a <= 5)
		ps_bfs_sort(ps);
	else
		ps_wheel_sort(ps);
	str = ps_store_str(NULL);
	if (str != NULL)
		ps_rmdup(str);
	free(str);
	ps_free(&ps);
	return (0);
}
