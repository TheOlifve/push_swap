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

#include "bps.h"

void	sa(t_ps *a)
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

void	sb(t_ps *b)
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

void	pa(t_ps **a, t_ps **b)
{
	t_ps	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = *a;
		if (*a)
			(*a)->prev = tmp;
		*a = tmp;
	}
}

void	pb(t_ps **a, t_ps **b)
{
	t_ps	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		tmp->next = *b;
		if (*b)
			(*b)->prev = tmp;
		*b = tmp;
	}
}

void	ra(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (*a && (*a)->next)
	{
		tmp = *a;
		tmp2 = tmp->next;
		tmp2->prev = NULL;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = tmp;
		tmp->prev = (*a);
		tmp->next = NULL;
		(*a) = (*a)->next;
		(*a) = tmp2;
	}
}
