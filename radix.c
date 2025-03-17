/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:56:52 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/03/16 17:56:56 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_empty(t_node *stack) 
{
    return stack == NULL;
}

// Función para obtener el valor del tope del stack
int top(t_node *stack) 
{
    if (stack == NULL) 
        return -1;
    return stack->pos;
}


void radix_sort(t_node **a)
{
    t_node *b = NULL;
    int size = 0;
    t_node *temp = *a;

    // Calcular el tamaño de la pila 'a'
    while (temp)
    {
        size++;
        temp = temp->next;
    }

    // Encontrar el valor máximo en 'a'
    int max_num = 0;
    temp = *a;
    while (temp)
    {
        if (temp->pos > max_num)
            max_num = temp->pos;
        temp = temp->next;
    }

    // Calcular el número de bits necesarios
    int max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    int i = 0;
    while (i < max_bits)
    {
        int count = size;  // Controlar el número de elementos a procesar
        int pushed = 0;    // Contador de elementos movidos a 'b'

        while (count > 0)
        {
            int num = top(*a);
            if ((num >> i) & 1)
                ra(a, 0);  // ✅ Rotamos SOLO si el bit es 1
            else
            {
                pb(&b, a, 0);  // ✅ Movemos a 'b' si el bit es 0
                pushed++;
            }
            count--;
        }

        // Regresar elementos de 'b' a 'a'
        while (pushed > 0)
        {
            pa(a, &b, 0);
            pushed--;
        }

        i++;
    }
}
