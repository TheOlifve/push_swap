/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:55:25 by hrahovha          #+#    #+#             */
/*   Updated: 2023/05/27 13:55:40 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ssa(t_ps *a)
{
	int	index;
	int	num;

	if (a && a->next)
	{
		index = a->index;
		num = a->num;
		a->index = a->next->index;
		a->num = a->next->num;
		a->next->index = index;
		a->next->num = num;
	}
}

void	ssb(t_ps *b)
{
	int	index;
	int	num;
	
	if (b && b->next)
	{
		index = b->index;
		num = b->num;
		b->index = b->next->index;
		b->num = b->next->num;
		b->next->index = index;
		b->next->num = num;
	}
}

void	ss(t_ps *a, t_ps *b)
{
	ssa(a);
	ssb(b);
	write(1, "ss\n", 3);
}

void	rra(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (a)
	{
		tmp = *a;
		tmp2 = tmp->next;
		tmp2->prev = NULL;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = tmp;
		tmp2 = tmp2->next;
		tmp2->next = NULL;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (b)
	{
		tmp = *b;
		tmp2 = tmp->next;
		tmp2->prev = NULL;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = tmp;
		tmp2 = tmp2->next;
		tmp2->next = NULL;
	}
	write(1, "rrb\n", 4);
}
