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

#ifndef BPS_H
# define BPS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/utils.h"

typedef struct s_ps
{
	int			num;
	int			index;
	struct s_ps	*next;
	struct s_ps	*prev;
}t_ps;

typedef struct s_list
{
	int			n_cnt;
	int			n_cnt2;
	int			min_index;
	char		**num_list;
	long		*srt_lst;
	long		*lst;
	long		tmp;
}t_list;

int		check_nums(t_list *ps);
int		check_nums2(t_list *ps);
int		check_nums3(int i);
t_ps	*ft_lstlast(t_ps *lst);
t_ps	*ft_lstnew(int num, int index);
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
void	ft_lstadd_back(t_ps **lst, t_ps *new);
void	ft_checker(t_ps **a, t_ps **b);

#endif