/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:50:24 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 18:05:03 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static void	check_sort(t_stack *stack_a, t_stack *stack_b)
{
    int flag;

    flag = 1;
	if (stack_b)
		flag = 0;
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
        {
			flag = 0;
            break ;
        }
		stack_a = stack_a->next;
	}
	if (flag == 1)
        write(1, "OK\n", 3);
    else
        write(0, "KO\n", 3);
}

void    get_do_op(t_stack **stack_a, t_stack **stack_b)
{
    char    *buff;
	t_stack *a;
	t_stack *b;

    buff = NULL;
    while (1)
    {
        buff = get_next_line(0);
        if (!buff)
            break ;
        if (ft_strcmp(buff, "sa\n") == 0)
            swap(stack_a, 'k');
        else if (ft_strcmp(buff, "sb\n") == 0)
            swap(stack_b, 'k');
        else if (ft_strcmp(buff, "ss\n") == 0)
            swap_s(stack_a, stack_b, 'k');
        else if (ft_strcmp(buff, "pa\n") == 0)
            push_stack(stack_b, stack_a, 'k');
        else if (ft_strcmp(buff, "pb\n") == 0)
            push_stack(stack_a, stack_b, 'k');
        else if (ft_strcmp(buff, "ra\n") == 0)
            rotate(stack_a, 'k');
        else if (ft_strcmp(buff, "rb\n") == 0)
            rotate(stack_b, 'k');
        else if (ft_strcmp(buff, "rr\n") == 0)
            rotate_r(stack_a, stack_b, 'k');
        else if (ft_strcmp(buff, "rra\n") == 0)
            r_rotate(stack_a, 'k');
        else if (ft_strcmp(buff, "rrb\n") == 0)
            r_rotate(stack_b, 'k');
        else if (ft_strcmp(buff, "rrr\n") == 0)
            r_rotate_r(stack_a, stack_b, 'k');
        else
        {
            write(2, "Error\n", 6);
            ft_lstclear(stack_a, NULL);
            ft_lstclear(stack_b, NULL);
            exit(1);
        }
		a = *stack_a;
		b = *stack_b;
    	free(buff);
    	buff = NULL;
    }
	check_sort(*stack_a, *stack_b);
}

int main(int ac, char *av[])
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
		ft_free(split_numbers);
        get_do_op(&stack_a, &stack_b);
		ft_lstclear(&stack_a, NULL);
		ft_lstclear(&stack_b, NULL);
	}
	return (0);
}