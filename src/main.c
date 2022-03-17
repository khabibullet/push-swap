/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:48:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/17 21:10:58 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*tmp;

	a = parse_args(argc, argv);
	b = create_stack();
	presort_stack(a);
	if (a->size < 6)
		mini_sort(a, b);
	else
		launch_algo(a, b);
	tmp = a->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	exit_success(a, b);
	return (0);
}

// int	main(void)
// {
// 	t_stack	*a;

// 	a = create_stack();
// 	push_stack_front(a, 2);
// 	push_stack_front(a, 1);
// 	push_stack_back(a, 3);
// 	while (a->head)
// 		ft_printf("%d\n", pop_stack_back(a));
// 	return (0);
// }
