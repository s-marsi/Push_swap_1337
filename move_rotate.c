/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:48:08 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/28 09:10:47 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && *stack_b)
	{
		rotate(stack_a, 'r');
		rotate(stack_b, 'r');
		write(1, "rr\n", 3);
	}
}

void	r_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*stack_clone;
	int		i;

	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		stack_clone = *stack;
		i = 1;
		while (i < ft_lstsize(*stack) - 1)
		{
			stack_clone = stack_clone->next;
			i++;
		}
		stack_clone->next = NULL;
		ft_lstadd_front(stack, tmp);
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}

void	r_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && *stack_b)
	{
		r_rotate(stack_a, 'r');
		r_rotate(stack_b, 'r');
		write(1, "rrr\n", 4);
	}
}
