/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:14 by hrahovha          #+#    #+#             */
/*   Updated: 2023/01/31 14:34:26 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bps.h"

t_ps	*ft_lstnew(int num, int index)
{
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
