/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:52:28 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/04 10:46:30 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_small(t_stack *stack)
{
	t_stack	*tmp;
	int		index;
	int		j;
	int		min;

	if (stack)
	{
		min = stack->content;
		tmp = stack->next;
		index = 0;
		j = 1;
		while (tmp)
		{
			if (tmp->content < min)
			{
				index = j;
				min = tmp->content;
			}
			j++;
			tmp = tmp->next;
		}
		return (index);
	}
	return (4);
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

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack_a;
	min = find_small(tmp);
    if (check_sort(*stack_a))
    {
        if (min == 1)
            swap(stack_a, 'a');
        else if(min == 2)
        {
            rotate(stack_a, 'a');
            rotate(stack_a, 'a');
        }
        else if(min == 3)
        {
            r_rotate(stack_a, 'a');
            r_rotate(stack_a, 'a');
        }
        else if (min == 4)
            r_rotate(stack_a, 'a');
        push_stack(stack_a, stack_b, 'b');
        sort_four(stack_a, stack_b);
        push_stack(stack_b, stack_a, 'a');
    }
}
