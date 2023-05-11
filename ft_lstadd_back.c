/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:10:19 by hrahovha          #+#    #+#             */
/*   Updated: 2023/01/27 17:28:25 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_lstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*k;

	k = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	k = ft_lstlast(*lst);
	k->next = new;
	new->prev = k;
}
