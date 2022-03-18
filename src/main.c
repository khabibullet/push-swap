/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:48:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/18 21:38:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parse_args(argc, argv);
	b = create_stack();
	presort_stack(a);
	issorted(a, b);
	if (a->size < 6)
		mini_sort(a, b);
	else
	{
		push_median(a, b);
		sort_to_b(a, b);
		sort_to_a(a, b);
		final_rotate(a);
	}
	exit_success(a, b);
	return (0);
}
