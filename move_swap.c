/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:48:51 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/02 22:15:40 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		tmp2 = (*stack)->next;
		*stack = (*stack)->next->next;
		ft_lstadd_front(stack, tmp);
		ft_lstadd_front(stack, tmp2);
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		swap(stack_a, 'c');
		swap(stack_b, 'c');
		write(1, "ss\n", 3);
	}
}
