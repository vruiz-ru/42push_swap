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

void print_stack2(t_node *stack, char name)
{
    printf("Stack %c: ", name);
    while (stack)
    {
        //printf("%d ", stack->value);
		printf("%d ", stack->pos);
        stack = stack->next;
    }
    printf("\n");
}


int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->pos > stack->next->pos)
            return (0);  // No está ordenado
        stack = stack->next;
    }
    return (1);  // Está ordenado
}

void radix_sort(t_node **a)
{
    t_node *b = NULL;
    int size, max_num, max_bits, i, j, pushed;

    if (is_sorted(*a))
        return;

   
    max_num = 0;
    t_node *temp = *a;
    
    while (temp) // Encontrar el valor máximo en 'pos'
    {
        if (temp->pos > max_num)
            max_num = temp->pos;
        temp = temp->next;
    }

    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        pushed = 0;
        j = 0;
        
        //printf("Iteration %d:\n", i);
        //print_stack2(*a, 'A');
       // print_stack2(b, 'B');
         size = stack_len(*a);
        // Procesar los elementos en A
        while (j < size)
        {
            if (((*a)->pos >> i) & 1)
                ra(a, 0);  // Si el bit i es 1, rota en A
            else
            {
                pb(&b, a, 0); // Si bit i es 0, mueve a B
                pushed++;
            }
            j++;
        }

        // Procesar elementos en B de forma optimizada
        int b_size = stack_len(b);
        int k = 0;
        while (k < b_size)
        {
            if (i < max_bits - 1) // Si no es la última iteración
            {
                if (((b->pos >> (i + 1)) & 1) == 1)
                    pa(a, &b, 0); // Mueve a A si el siguiente bit es 1
                else
                    rb(&b, 0); // Mantiene en B rotándolo si el bit siguiente es 0
            }
            else
            {
                pa(a, &b, 0); // En las últimas iteraciones, vacía B sin optimización
            }
            k++;
        }
        i++;
    }

    while (b)
        pa(a, &b, 0); // Asegurar que B esté vacío al final

    //printf("\nFinal Result:\n");
   // print_stack2(*a, 'A');
    //print_stack2(b, 'B');
}