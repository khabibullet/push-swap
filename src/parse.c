/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:00:05 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/14 19:01:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	validate_args(int argc, char **argv)
{
	int	prev;
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		exit_error();
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j])
				&& argv[i][j] != '-')
				exit_error();
			if (j > 0 && ((prev == '-' && !ft_isdigit(argv[i][j]))
				|| (ft_isdigit(prev) && argv[i][j] == '-')))
				exit_error();
			prev = (int)argv[i][j];
			j++;
		}
		i++;
	}
}

char	*concatenate_args(char **argv)
{
	char	*str;
	int		i;

	str = malloc(sizeof(*str));
	if (!str)
		exit_error();
	*str = '\0';
	i = 1;
	while (argv[i])
	{
		str = ft_strjoin_free(str, argv[i]);
		str = ft_strjoin_free(str, " ");
		i++;
	}
	if (!str)
		exit_error();
	return (str);
}

t_stack	*fill_stack(char **strs)
{
	t_stack	*a;
	int		i;

	a = create_stack();
	i = 0;
	while (strs[i])
	{
		push_stack_back(a, ft_atoi_limited(strs[i]));
		free(strs[i]);
		a->tail->order = -1;
		i++;
	}
	free(strs);
	return (a);
}

void	check_doubles(t_stack	*a)
{
	int		buf;
	t_node	*ptr1;
	t_node	*ptr2;

	if (a->head == NULL)
		exit_error();
	ptr1 = a->head->next;
	buf = a->head->val;
	while (ptr1)
	{
		ptr2 = ptr1;
		while (ptr2)
		{
			if (buf == ptr2->val)
				exit_error();
			ptr2 = ptr2->next;
		}
		buf = ptr1->val;
		ptr1 = ptr1->next;
	}
}

t_stack	*parse_args(int argc, char **argv)
{
	char	*str;
	char	**strs;
	t_stack	*a;

	validate_args(argc, argv);
	str = concatenate_args(argv);
	strs = ft_split_isspace(str);
	free(str);
	a = fill_stack(strs);
	check_doubles(a);
	return (a);
}
