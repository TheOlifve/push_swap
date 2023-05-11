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

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	int		i;

	i = 0;
	if (argc < 3)
		return (0);
	while (argv[++i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i]), i));
	t_ps *t = a;
	while (t)
	{
		printf("%d\n", t->num);
		t = t->next;
	}
	return (0);
}