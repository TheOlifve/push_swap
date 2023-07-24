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

#include "bps.h"

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

char	**args_list(char **argv, char *tmp_lst, int i, int j)
{
	char	**tmp;
	char	*num_list;

	num_list = ft_strdup("");
	if (!valid_args(argv, 0, 0) || !num_list)
		msg("ERROR");
	while (argv[++i])
	{
		tmp = ft_split(argv[i], ' ');
		while (tmp[++j])
		{
			tmp_lst = num_list;
			free(num_list);
			num_list = ft_strjoin(tmp_lst, tmp[j]);
			tmp_lst = num_list;
			free(num_list);
			num_list = ft_strjoin(tmp_lst, " ");
			free(tmp[j]);
		}
		free(tmp);
		j = -1;
	}
	tmp = ft_split(num_list, ' ');
	free(num_list);
	return (tmp);
}

void	sorting(t_list *ps, int i, int j, int k)
{
	while (ps->num_list && ps->num_list[++k])
		;
	ps->n_cnt = k;
	ps->srt_lst = malloc(sizeof(long) * k);
	if (!ps->srt_lst)
		msg("ERROR");
	k = -1;
	while (ps->num_list && ps->num_list[++k])
		ps->srt_lst[k] = ft_atoi(ps->num_list[k]);
	while (++i < k)
	{
		while (++j < k)
		{
			if (ps->srt_lst[i] < ps->srt_lst[j])
			{
				ps->tmp = ps->srt_lst[i];
				ps->srt_lst[i] = ps->srt_lst[j];
				ps->srt_lst[j] = ps->tmp;
			}
		}
		j = -1;
	}
}

void	indexing(t_ps **a, t_list *ps, int i)
{
	int	j;

	j = -1;
	ps->lst = malloc(sizeof(long) * ps->n_cnt);
	if (!check_nums(ps) || !ps->lst)
		msg("ERROR");
	while (++i < ps->n_cnt)
		ps->lst[i] = ft_atoi(ps->num_list[i]);
	i = -1;
	while (++i < ps->n_cnt)
	{
		j = -1;
		while (++j < ps->n_cnt)
		{
			if (ps->lst[i] == ps->srt_lst[j])
			{
				ft_lstadd_back(a, ft_lstnew(ps->srt_lst[j], j));
				check_nums3(ps->srt_lst[j]);
			}
		}
	}
	if (!check_nums2(ps) && ps->n_cnt > 1)
		exit (0);
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	t_list	ps;

	if (argc < 2)
		exit (0);
	a = NULL;
	b = NULL;
	ps.min_index = 0;
	ps.num_list = args_list(argv, NULL, 0, -1);
	sorting(&ps, -1, -1, -1);
	ps.n_cnt2 = ps.n_cnt;
	indexing(&a, &ps, -1);
	ft_checker(&a, &b);
	return (0);
}
