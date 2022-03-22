/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_store_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:42:23 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/14 15:41:36 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

static char	*ps_store_str_reset(char **buf, size_t *size, size_t *ofs)
{
	char	*tmp;

	if (*buf == NULL)
		tmp = NULL;
	else
		tmp = ft_strdup(*buf);
	free(*buf);
	*buf = NULL;
	*size = 0;
	*ofs = 0;
	return (tmp);
}

char	*ps_store_str(const char *str)
{
	static size_t	size;
	static size_t	ofs;
	static char		*buf;
	size_t			len;

	if (str == NULL)
		return (ps_store_str_reset(&buf, &size, &ofs));
	len = ft_strlen(str);
	while (len + ofs + 1 > size)
	{
		if (size == 0)
			size = 16;
		buf = ft_realloc(buf, size, size * 2);
		if (buf == NULL)
			return (ps_store_str_reset(&buf, &size, &ofs));
		size *= 2;
	}
	ft_memcpy(buf + ofs, str, len + 1);
	ft_strlcpy(buf + ofs, str, size - ofs);
	ofs += len;
	return (buf);
}

void	ps_op_wrapper(t_ps_op op, t_push_swap ps)
{
	push_swap(ps, op);
	if (ps_store_str(ps_op_to_str(op)) == NULL)
		ft_exit(-1, "Error");
	if (ps_store_str("\n") == NULL)
		ft_exit(-1, "Error");
}
