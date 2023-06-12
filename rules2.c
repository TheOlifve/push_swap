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

	if (b)
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

void	trb(t_ps **b)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (b)
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
}

void	tra(t_ps **a)
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
		tmp->prev = (*a);
		tmp->next = NULL;
		(*a) = (*a)->next;
		(*a) = tmp2;
	}
}

void	rr(t_ps **a, t_ps **b)
{
	tra(a);
	trb(b);
	write(1, "rr\n", 3);
}
