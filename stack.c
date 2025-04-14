/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:23:06 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/03/15 21:23:11 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_node **a, char **av, bool flag_ac)
{
	free_stack(a);
	if (flag_ac)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_node *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
