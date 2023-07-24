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

void	butterfly(t_ps **a, t_ps **b, t_list *ps)
{
	if ((*a)->index <= ps->cnt)
	{
		pb(a, b);
		rb(b);
		ps->cnt += 1;
	}
	else if ((*a)->index <= ps->cnt + ps->n_sqrt)
	{
		pb(a, b);
		ps->cnt += 1;
	}
	else
		ra(a);
}

void	here_we_go(t_ps **a, t_ps **b, t_list *ps)
{
	int		i;
	t_ps	*t;

	i = 0;
	t = *b;
	while (t && t->index != ps->n_cnt)
	{
		i++;
		t = t->next;
	}
	if (i <= (ps->n_cnt / 2))
		while (i-- > 0)
			rb(b);
	else
		while (i++ < ps->n_cnt + 1)
			rrb(b);
	pa(a, b);
	ps->n_cnt -= 1;
}
