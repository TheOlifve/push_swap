/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:55:17 by hrahovha          #+#    #+#             */
/*   Updated: 2023/05/11 13:55:20 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS
# define PS

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./utils/utils.h"

typedef struct s_ps
{
	int			num;
	int			index;
	struct s_ps	*next;
	struct s_ps	*prev;
}t_ps;

void	ft_lstadd_back(t_ps **lst, t_ps *new);
t_ps	*ft_lstlast(t_ps *lst);
int		ft_lstsize(t_ps *lst);
t_ps	*ft_lstnew(int num, int index);


#endif