/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:06:13 by hrahovha          #+#    #+#             */
/*   Updated: 2023/01/31 14:20:10 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bps.h"

int	sort_check(t_ps **a)
{
	int	i;

	i = (*a)->index;
	while ((*a) && (*a)->next)
	{
		(*a) = (*a)->next;
		if (i > (*a)->index)
			return (0);
		i = (*a)->index;
	}
	return (1);
}

void	rule_check(char *str, t_ps **a, t_ps **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b);
	else
		msg("ERROR");
}

void	ft_checker(t_ps **a, t_ps **b)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (str)
			rule_check(str, a, b);
		else
			break ;
		free(str);
	}
	if (!*a || *b || !(sort_check(a)))
		write (2, "KO\n", 3);
	else
		write (2, "OK\n", 3);
}
