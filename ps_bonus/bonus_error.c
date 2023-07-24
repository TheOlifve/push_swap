/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:55:25 by hrahovha          #+#    #+#             */
/*   Updated: 2023/05/22 13:55:40 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bps.h"

int	check_nums(t_list *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->n_cnt)
	{
		j = i;
		while (++j < ps->n_cnt)
		{
			if (ps->srt_lst[i] == ps->srt_lst[j])
				return (0);
		}
	}
	return (1);
}

int	check_nums2(t_list *ps)
{
	int	i;

	i = -1;
	while (++i < ps->n_cnt - 1)
	{
		if (ps->lst[i] > ps->lst[i + 1])
			return (1);
	}
	return (0);
}

int	check_nums3(int i)
{
	char	*str;

	str = ft_itoa(i);
	if (i >= 0)
	{
		if (ft_strlen(str) > 10)
		{
			free(str);
			msg("ERROR");
		}
	}
	else
	{
		if (ft_strlen(str) > 11)
		{
			free(str);
			msg("ERROR");
		}
	}
	free(str);
	return (0);
}
