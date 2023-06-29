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

void    butterfly(t_ps **a, t_ps **b, t_list *ps)
{
	if ((*a)->index <= ps->cnt)
	{
		pb(a, b);
		rb(b);
			ps->test += 2; //
		ps->cnt += 1;
	}
	else if ((*a)->index <= ps->cnt + ps->n_sqrt)
	{
			ps->test += 1; //
		pb(a, b);
		ps->cnt += 1;
	}
	else
	{                      //
		ra(a);
			ps->test += 1; //
	}                      //	
}

void    here_we_go(t_ps **a, t_ps **b, t_list *ps)
{
	int i;

	i = 0;
	// t_ps **tmp = b;
	// while (*b)
	// {
	// 	printf("B - %d\n",(*b)->index);
	// 	*b = (*b)->next;
	// }
	// *b = *tmp;
   while ((*b)->index != ps->n_cnt)
   {
		i++;
		*b = (*b)->next;
   }
   printf("i - %d\n",i);
	if (i <= ps->n_cnt / 2)
		while (i-- > 0)
			rb(b);
	else
		while (i++ < ps->n_cnt + 1)
			rrb(b);
	pa(a, b);
	ps->n_cnt -= 1;
}