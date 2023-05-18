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

int	valid_args(char **argv, int i, int j)
{
	while (argv[++i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == 32)
				j++;
			else if ((argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				if ((argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57)
				|| argv[i][j + 1] == 32 || argv[i][j + 1] == '\0')
					j++;
				else
					return (0);
			}
			else if (argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57
				&& (argv[i][j] == '-' || argv[i][j] == '+'))
					j++;
			else
				return (0);
		}
		j = 0;
	}
	return (1);
}

char	**args_list(char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	char	*num_list;

	i = 0;
	j = -1;
	num_list = ft_strdup("");
	if (!valid_args(argv, 0, 0) || !num_list)
		msg("ERROR");
	while (argv[++i])
	{
		tmp = ft_split(argv[i], ' ');
		while (tmp[++j])
		{
			num_list = ft_strjoin(num_list, tmp[j]);
			num_list = ft_strjoin(num_list, " ");
		}
		free(tmp);
		j = -1;
	}
	tmp = ft_split(num_list, ' ');
	free(num_list);
	return (tmp);
}

int	*sorting(char **str, int i, int j, int k)
{
	int	*lst;
	int	tmp;

	while (str && str[++k])
		;
	lst = malloc(sizeof(int) * k);
	if (!lst)
		msg("ERROR");
	k = -1;
	while (str[++k])
		lst[k] = ft_atoi(str[k]);
	while (++i < k)
	{
		while (++j < k)
		{
			if (lst[i] < lst[j])
			{
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
		}
		j = -1;
	}
	return (lst);
}

void	indexing(t_ps **a, char **num_list, int *nlist)
{
	int	i;
	int	j;
	int	k;
	int	*lst;

	i = -1;
	j = -1;
	while (num_list && num_list[++i])
		;
	lst = malloc(sizeof(int) * i);
	if (!lst)
		msg("ERROR");
	i = -1;
	while (num_list[++i])
		lst[i] = ft_atoi(num_list[i]);
	while (++j < i)
	{
		k = -1;
		while (++k < i)
		{
			if (lst[j] == nlist[k])
				ft_lstadd_back(a, ft_lstnew(nlist[k], k));
		}
	}
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	int		i;
	int		*nlist;
	char	**num_list;

	i = -1;
	if (argc < 3)
		return (0);
	num_list = args_list(argv);
	nlist = sorting(num_list, -1, -1, -1);
	indexing(&a, num_list, nlist);
	return (0);
}
