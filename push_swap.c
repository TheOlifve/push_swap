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

int	valid_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[++i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == 32
				|| argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			else
				return (0);
		}
		j = 0;
	}
	return (1);
}

char	**indexing(char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	char	*num_list;

	i = 0;
	j = -1;
	if (!valid_args(argv))
		exit (0);
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
	i = -1;
	while(tmp[++i])
	 	printf("%s\n", tmp[i]);
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_ps	*a;
	t_ps	*b;
	int		i;
	char	**num_list;

	i = -1;
	if (argc < 3)
		return (0);
	num_list = indexing(argv);
	//while(num_list[++i])
		//printf("%s\n", num_list[i]);
	while (num_list[++i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(num_list[i]), i));
	// t_ps *t = a;
	// while (t)
	// {
	// 	printf("%d\n", t->num);
	// 	t = t->next;
	// }
	return (0);
}