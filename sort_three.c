/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:43:19 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/02 07:55:26 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_arr(int *arr, int *index, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	tmp = index[i];
	index[i] = index[j];
	index[j] = tmp;
}

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
				index = tmp->index;
				min = tmp->content;
			}
			j++;
			tmp = tmp->next;
		}
		return (index);
	}
	return (4);
}

static	int	find_moy(t_stack *stack)
{
	t_stack	*tmp;
	int		arr[3];
	int		index[3];
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		arr[i] = tmp->content;
		index[i++] = tmp->index;
		tmp = tmp->next;
	}
	i = 0;
	while (i < 2)
	{
		if (arr[i] > arr[i + 1])
		{
			swap_arr(arr, index, i, i + 1);
			i = 0;
		}
		else
			i++;
	}
	return (index[1]);
}

static void	check_case(t_stack **stack_a, int min, int next_min)
{
	if (min == 0 && next_min == 2)
	{
		r_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if (min == 1 && next_min == 0)
		swap(stack_a, 'a');
	else if (min == 1 && next_min == 2)
		rotate(stack_a, 'a');
	if (min == 2 && next_min == 0)
		r_rotate(stack_a, 'a');
	else if (min == 2 && next_min == 1)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void	sort_three(t_stack **stack_a)
{
	int		min;
	int		next_min;
	t_stack	*tmp;

	tmp = *stack_a;
	min = find_small(tmp);
	next_min = find_moy(tmp);
	check_case(stack_a, min, next_min);
}
