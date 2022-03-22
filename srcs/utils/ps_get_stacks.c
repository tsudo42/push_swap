/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:15:36 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/22 19:21:46 by tsudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

static int	ps_count_ints(int argc, const char **argv)
{
	int		count;
	int		i;
	int		j;
	char	**numstrs;
	int		ok;

	count = 0;
	i = 0;
	ok = 1;
	while (i < argc && ok == 1)
	{
		numstrs = ft_split(argv[i++], ' ');
		if (numstrs == NULL)
			return (-1);
		j = 0;
		while (numstrs[j] != NULL)
		{
			if (!ft_isintstr(numstrs[j]))
				ok = 0;
			free(numstrs[j++]);
			count++;
		}
		free(numstrs);
	}
	return (count * ok);
}

static int	ps_store_ints(int argc, const char **argv, int *stack, int *size)
{
	int		i;
	int		j;
	char	**numstrs;
	int		ok;

	(*size) = 0;
	i = 0;
	ok = 1;
	while (i < argc && ok == 1)
	{
		numstrs = ft_split(argv[i++], ' ');
		if (numstrs == NULL)
			return (-1);
		j = 0;
		while (numstrs[j] != NULL)
		{
			if (!ft_isintstr(numstrs[j]))
				ok = 0;
			stack[(*size)++] = ft_atoi(numstrs[j]);
			free(numstrs[j++]);
		}
		free(numstrs);
	}
	return (ok != 1);
}

static int	check_valid_stack(int *stack, int size)
{
	int	*sorted;
	int	i;

	if (size <= 0)
		return (-1);
	sorted = ft_memdup(stack, sizeof(int) * size);
	if (sorted == NULL)
		return (-1);
	ft_heapsort_int(sorted, size);
	i = 0;
	while (i < size - 1)
	{
		if (sorted[i] == sorted[i + 1])
		{
			free(sorted);
			return (-1);
		}
		i++;
	}
	ft_shrinkarr_int(stack, sorted, size);
	free(sorted);
	return (0);
}

t_push_swap	ps_get_stacks(int argc, const char **argv)
{
	int			size;
	t_push_swap	ps;

	size = ps_count_ints(argc, argv);
	if (size <= 0)
		exit_with_error();
	if (ps_alloc(size, &ps) != 0)
		ps_free_and_abort(ps);
	if (ps_store_ints(argc, argv, ps.stack_a, ps.size_a) != 0)
		ps_free_and_abort(ps);
	if (check_valid_stack(ps.stack_a, *ps.size_a) != 0)
		ps_free_and_abort(ps);
	*ps.size_b = 0;
	return (ps);
}
