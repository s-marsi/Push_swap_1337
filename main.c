/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:35:23 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 22:49:19 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_is_number_no_dup(char	**numbers)
{
	long long	num;
	int			i;
	int			j;

	i = 0;
	check_dup(numbers);
	while (numbers[i])
	{
		check_int(numbers[i]);
		j = 0;
		while (numbers[i] && numbers[i][j])
		{
			num = numbers[i][j];
			if ((num == '-' || num == '+') && numbers[i][j + 1])
				j++;
			if (!ft_isdigit(numbers[i][j]))
			{
				ft_free(numbers);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static char	**check_args(int ac, char *av[])
{
	char	**split_numbers;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t'))
			j++;
		if (!av[i][j])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	split_numbers = get_args(ac, av);
	check_is_number_no_dup(split_numbers);
	return (split_numbers);
}

static void	sort_chooser(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sort(*stack_a))
	{
		if (ft_lstsize(*stack_a) <= 3)
			sort_three(stack_a);
		else if (ft_lstsize(*stack_a) <= 4)
			sort_four(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) <= 5)
			sort_five(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) <= 100)
			sort_stack(stack_a, stack_b, 10);
		else
			sort_stack(stack_a, stack_b, 30);
	}
}

int	main(int ac, char *av[])
{
	char	**split_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		split_numbers = check_args(ac, av);
		if (!split_numbers)
			return (0);
		add_numbers_into_linkedlist(split_numbers, &stack_a);
		index_list(&stack_a, ft_lstsize(stack_a));
		sort_chooser(&stack_a, &stack_b);
		ft_free(split_numbers);
		ft_lstclear(&stack_a, NULL);
		ft_lstclear(&stack_b, NULL);
	}
	return (0);
}
