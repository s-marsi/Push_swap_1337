/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:08:03 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/03 10:22:45 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(t_stack *stack_a, int value)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (value == stack_a->content)
			return (i);
		i++;
		stack_a = stack_a->next;
	}
	return (-1);
}

static int get_value(t_stack *stack_b, int index)
{
	int	value;

	value = -1;
	while (stack_b)
	{
		if (stack_b->index == index)
		{
			value = stack_b->content;
			break ;
		}
		stack_b = stack_b->next;
	}
	return (value);
}

static void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_index;
	int	value;
	int	max_index;

	max_index = ft_lstsize(*stack_b) - 1;
	while (ft_lstsize(*stack_b))
	{
		value = get_value(*stack_b, max_index);
		stack_index = find_index(*stack_b, value);
		while ((*stack_b)->content != value)
		{
			if (stack_index <= ft_lstsize(*stack_b) / 2)
				rotate(stack_b, 'b');
			else
				r_rotate(stack_b, 'b');
		}
		if ((*stack_b)->content == value)
		{
			push_stack(stack_b, stack_a, 'a');
			max_index--;
		}
	}
}
static void	send_to_b(t_stack **stack_a, t_stack **stack_b, int flag)
{
	int	i;

	i = 0;
	while (ft_lstsize(*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			push_stack(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= i + flag)
		{
			push_stack(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int flag)
{
	send_to_b(stack_a, stack_b, flag);
	back_to_a(stack_a, stack_b);
}
