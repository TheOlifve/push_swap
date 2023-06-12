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

void	rrra(t_ps **a)
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
}

void	rrrb(t_ps **b)
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
}

void	rrr(t_ps **a, t_ps **b)
{
	rrra(a);
	rrrb(b);
	write(1, "rrr\n", 4);
}
