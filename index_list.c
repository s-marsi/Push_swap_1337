/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:02:28 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/04 07:55:10 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	fill_array(t_stack *stack, int *arr, int arr_size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp && i < arr_size)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
}

static void	swap_arr(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int	find_small(int arr[], int start, int end)
{
	int	j;
	int	i;

	j = start;
	i = j + 1;
	while (i < end)
	{
		if (arr[i] < arr[j])
			j = i;
		i++;
	}
	return (j);
}

static void	sort_arr(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = find_small(arr, i, len);
		if (arr[i] > arr[j])
			swap_arr(arr, i, j);
		i++;
	}
}

void	index_list(t_stack **stack, int len)
{
	int		*arr;
	t_stack	*tmp;
	int		i;

	arr = malloc(len * sizeof(int));
	if (!arr)
	{
		ft_lstclear(stack, NULL);
		exit(1);	
	}
	fill_array(*stack, arr, len);
	sort_arr(arr, len);
	i = 0;
	while (i < len)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->content == arr[i])
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
	free(arr);
}
