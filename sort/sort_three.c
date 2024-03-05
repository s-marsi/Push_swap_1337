/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:43:19 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 19:11:44 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	find_small(t_stack *stack)
{
	t_stack	*tmp;
	int		value;

	value = stack->content;
	if (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->content < value)
				value = tmp->content;
			tmp = tmp->next;
		}
	}
	return (value);
}

static	int	find_max(t_stack *stack)
{
	t_stack	*tmp;
	int		value;

	value = stack->content;
	if (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->content > value)
				value = tmp->content;
			tmp = tmp->next;
		}
	}
	return (value);
}

static int	check_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	sort_three(t_stack **stack_a)
{
	int	min;
	int	max;

	min = find_small(*stack_a);
	max = find_max(*stack_a);
	if (ft_lstsize(*stack_a) < 3 && check_sort(*stack_a) == 1)
	{
		swap(stack_a, 'a');
		return ;
	}
	while (check_sort(*stack_a) == 1)
	{
		if (max == (*stack_a)->content)
			rotate(stack_a, 'a');
		if (min == (*stack_a)->next->content)
			swap(stack_a, 'a');
		if (max == (*stack_a)->next->content)
			r_rotate(stack_a, 'a');
	}
}
