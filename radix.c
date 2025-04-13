/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:56:52 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/04/03 20:58:23 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_stack2(t_node *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d ", stack->pos);
		stack = stack->next;
	}
	printf("\n");
}*/

int	is_sorted_a(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->pos > stack->next->pos)
			return (0); 
		stack = stack->next;
	}
	return (1); 
}

int	get_max_bits(t_node *a)
{
	int	max_num;
	int	max_bits;

	max_num = 0;
	max_bits = 0;
	while (a)
	{
		if (a->pos > max_num)
			max_num = a->pos;
		a = a->next;
	}
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	process_stack_a(t_node **a, t_node **b, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = stack_len(*a);
	while (i < size)
	{
		if (is_sorted_a(*a))
			break;
		if (((*a)->pos >> bit) & 1)
			ra(a, 0); // Bit 1 → rota
		else
			pb(b, a, 0); // Bit 0 → mueve a B
		i++;
	}
	return;
}

void	process_stack_b(t_node **a, t_node **b, int bit, int max_bits)
{
	int	j;
	int	size;

	j = 0;
	size = stack_len(*b);
	while (j < size)
	{	
		if (bit < max_bits - 1)
		{
			if (((*b)->pos >> (bit + 1)) & 1)
				pa(a, b, 0);
			else
				rb(b, 0);
		}
		else
			pa(a, b, 0);
		j++;
	}
	return;
}

void	radix_sort(t_node **a)
{
	t_node	*b;
	int		max_bits;
	int		bit_index;

	bit_index = 0;
	b = NULL;
	if (is_sorted_a(*a))
		return ;
	max_bits = get_max_bits(*a);
	while (bit_index < max_bits)
	{
		process_stack_a(a, &b, bit_index);
		process_stack_b(a, &b, bit_index, max_bits);
		bit_index++;
	}
	// Asegurar que B esté vacío (por si acaso)
	while (b)
		pa(a, &b, 0);
	// printf("%d\n", max_bits);
	return;
}
