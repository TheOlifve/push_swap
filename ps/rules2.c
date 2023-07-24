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

void	rb(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (*b && (*b)->next)
	{
		tmp = (*b);
		tmp2 = tmp->next;
		tmp2->prev = NULL;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = tmp;
		tmp->prev = (*b);
		tmp->next = NULL;
		(*b) = (*b)->next;
		(*b) = tmp2;
	}
	write(1, "rb\n", 3);
}

void	rr(t_ps **a, t_ps **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	ss(t_ps *a, t_ps *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	rra(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while ((*a)->next)
			*a = (*a)->next;
		tmp2 = *a;
		*a = (*a)->prev;
		(*a)->next = NULL;
		*a = tmp;
		tmp2->next = *a;
		tmp2->prev = NULL;
		(*a)->prev = tmp2;
		(*a) = tmp2;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (*b && (*b)->next)
	{
		tmp = *b;
		while ((*b)->next)
			*b = (*b)->next;
		tmp2 = *b;
		*b = (*b)->prev;
		(*b)->next = NULL;
		*b = tmp;
		tmp2->next = *b;
		tmp2->prev = NULL;
		(*b)->prev = tmp2;
		(*b) = tmp2;
	}
	write(1, "rrb\n", 4);
}
