/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:35:23 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/04 09:40:44 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_is_number_no_dup(char	**numbers)
{
	int		i;
	int		j;
	long long	num;

	i = 0;
	check_dup(numbers);
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j = 0;
		while (numbers[i] && numbers[i][j])
		{
			if ((numbers[i][j] == '-' || numbers[i][j] == '+') && numbers[i][j + 1])
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
	int	i;
	int	j;
	char **split_numbers;

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
	if (ft_lstsize(*stack_a) <= 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) <= 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 100)
		sort_stack(stack_a, stack_b, 15);
	else if (ft_lstsize(*stack_a) <= 500)
		sort_stack(stack_a, stack_b, 30);
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
