/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:07:25 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/01/23 20:07:32 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_node	*find_last_node(t_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
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

void create_index(t_node *head) {
    t_node *pnt;
	t_node	*cmp;
    int count;
    
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




void	stack_init(t_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}

int main(int ac, char **av)
{
    t_node *a;
    t_node *b;

    t_node *print;

    a = NULL;
    b = NULL;
    if((ac == 1) || (ac == 2 && !(*av[1])))
        return(1);
    else if(ac == 2)
        av = ft_split(av[1], ' ');
    
    int i;
    i = 0;
    while (av[i])
    {
        printf("\"%s\"\n", av[i]);
        i++;
     }
	 printf("\n");
    stack_init(&a, av + 1, ac == 2);//crear stack a
	create_index(a);
    print = a;
    while (print)
    {
        printf("Value: %d // Pos:%d\n", print->value, print->pos);
        print = print->next;
    }
	printf("\n");

	radix_sort(&a);

    // Mostrar pila ordenada
    printf("\nSorted stack:\n");
    print = a;
    while (print != NULL) 
	{
        printf("%d\n", print->value);
        print = print->next;
    }


   /*
    if(!stack_sorted(a))
    {
        //radix

    }
        */
    free_stack(&a);
    
    return(0);
}