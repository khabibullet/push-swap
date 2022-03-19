/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:02:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/19 17:25:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	a = parse_args(argc, argv);
	b = create_stack();
	str = get_next_line(0);
	while (str)
	{
		check_rule(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	issorted_bonus(a, b);
	return (0);
}
