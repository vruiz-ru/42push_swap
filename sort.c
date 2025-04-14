/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:50:26 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/04/13 14:50:30 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

static t_node	*find_highest(t_node *stack)
{
	int		highest;
	t_node	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->pos > highest)
		{
			highest = stack->pos;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_node **a)
{
	t_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->pos > (*a)->next->pos)
		sa(a);
}

void	push_to_b(t_node **b, t_node **a)
{
	int	quantity;

	quantity = stack_len(*a);
	while (quantity > 3)
	{
		if ((*a)->pos == 0 || (*a)->pos == 1)
		{
			pb(b, a);
			quantity--;
		}
		else
			ra(a);
	}
	return ;
}

void	sort_five(t_node **a)
{
	t_node	*b;

	b = NULL;
	push_to_b(&b, a);
	sort_three(a);
	if (stack_len(b) == 2)
	{
		if ((b)->pos < (b)->next->pos)
			sb(&b);
	}
	while (stack_len(b) > 0)
		pa(a, &b);
	if ((*a)->pos > (*a)->next->pos)
		sa(a);
	return ;
}
