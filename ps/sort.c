/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:55:25 by hrahovha          #+#    #+#             */
/*   Updated: 2023/05/11 13:55:40 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_3(t_ps **a)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->index;
	j = (*a)->next->index;
	k = (*a)->next->next->index;
	if (i < j && j < k && i < k)
		;
	else if (i > j && j < k && i < k)
		sa(*a);
	else if (i > j && j < k && i > k)
		ra(a);
	else if (i < j && j > k && i < k)
	{
		rra(a);
		sa(*a);
	}
	else if (i < j && j > k && i > k)
		rra(a);
	else if (i > j && j > k && i > k)
	{
		ra(a);
		sa(*a);
	}
}

int	find_min(t_ps **a, t_list *ps)
{
	int	i;

	i = 0;
	while ((*a)->next && (*a)->index != ps->min_index)
	{
		i++;
		a = &(*a)->next;
	}
	ps->min_index += 1;
	return (i);
}

void	sort_more(t_ps **a, t_ps **b, t_list *ps)
{
	int	i;

	i = find_min(a, ps);
	if (i <= ps->n_cnt / 2)
		while (--i >= 0)
			ra(a);
	else if (i > ps->n_cnt / 2)
		while (i++ < ps->n_cnt)
			rra(a);
	ps->n_cnt -= 1;
	pb(a, b);
}

void	n_sqrt(t_list *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i * i <= ps->n_cnt)
		i++;
	ps->n_sqrt = i - 1;
	i = 1;
	while (i <= ps->n_cnt)
	{
		i *= 2;
		j++;
	}
	ps->n_sqrt += j - 1;
}

void	sort(t_ps **a, t_ps **b, t_list *ps)
{
	if (ps->n_cnt == 2)
		sa(*a);
	else if (ps->n_cnt <= 12)
	{
		while (ps->n_cnt2 > 3)
		{
			sort_more(a, b, ps);
			ps->n_cnt2 -= 1;
		}
		sort_3(a);
		while (*b)
			pa(a, b);
	}
	else
	{
		n_sqrt(ps);
		while (*a)
			butterfly(a, b, ps);
		ps->n_cnt -= 1;
		while (*b)
			here_we_go(a, b, ps);
	}
}
