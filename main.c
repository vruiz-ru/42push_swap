/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:07:25 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/04/03 18:03:35 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *node)
{
	if (NULL == node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	create_index(t_node *head)
{
	t_node	*pnt;
	t_node	*cmp;
	int		count;

	pnt = head;
	while (pnt)
	{
		count = 0;
		cmp = head;
		while (cmp)
		{
			if (cmp->value < pnt->value)
				count++;
			cmp = cmp->next;
		}
		pnt->pos = count;
		pnt = pnt->next;
	}
}

void	stack_init(t_node **a, char **av, bool flag_ac)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag_ac);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_ac)
		free_matrix(av);
}

int	main(int ac, char **av)
{
	t_node	*a;

	a = NULL;
	if ((ac == 1) || (ac == 2 && !(*av[1])))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	create_index(a);
	if (!is_sorted_a(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) <= 5)
			sort_five(&a);
		else
			radix_sort(&a);
	}
	free_stack(&a);
	return (0);
}
