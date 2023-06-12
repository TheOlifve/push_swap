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

#ifndef PS_H
# define PS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./utils/utils.h"

typedef struct s_ps
{
	int			num;
	int			index;
	struct s_ps	*next;
	struct s_ps	*prev;
}t_ps;

typedef struct s_list
{
	char	**num_list;
	int		*srt_lst;
	int		*lst;
	int		n_cnt;
	int		tmp;
}t_list;

void	ft_lstadd_back(t_ps **lst, t_ps *new);
t_ps	*ft_lstlast(t_ps *lst);
int		ft_lstsize(t_ps *lst);
t_ps	*ft_lstnew(int num, int index);
int		check_nums(t_list *ps);
int		check_nums2(t_list *ps);
void	sa(t_ps	*a);
void	sb(t_ps	*b);
void	ss(t_ps *a, t_ps *b);
void	pa(t_ps **a, t_ps **b);
void	pb(t_ps **a, t_ps **b);
void	ra(t_ps **a);
void	rb(t_ps **b);
void	rr(t_ps **a, t_ps **b);
void	rra(t_ps **a);
void	rrb(t_ps **b);
void	rrr(t_ps **a, t_ps **b);

#endif