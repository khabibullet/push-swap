/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:59:47 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/17 21:13:06 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_success(t_stack *a, t_stack *b)
{
	delete_stack(&a);
	delete_stack(&b);
	exit(EXIT_SUCCESS);
}

void	issorted(t_stack *a, t_stack *b)
{
	t_node	*ptr;

	ptr = a->head;
	while (ptr->next)
	{
		if (ptr->val > ptr->next->val)
			return ;
		ptr = ptr->next;
	}
	exit_success(a, b);
}
