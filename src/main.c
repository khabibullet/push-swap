/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:48:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 21:12:39 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_node	*tmp;

	a = parse_args(argc, argv);
	presort_stack(a);
	tmp = a->head;
	while (tmp)
	{
		ft_printf("%d // %d\n", tmp->val, tmp->order);
		tmp = tmp->next;
	}
	// ft_printf("size %d\n", a->size);
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
