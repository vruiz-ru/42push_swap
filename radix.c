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
    return stack->value;
}

void radix_sort(t_node **a) 
{
    t_node *b = NULL;  // Pila b
    int size = 0;
    t_node *temp = *a;
    // Calcular el tamaño de la pila 'a'
    while (temp != NULL) 
    {
        size++;
        temp = temp->next;
    }
    // Encontrar el valor máximo en la pila 'a'
    int max_num = 0;
    temp = *a;
    while (temp != NULL) 
    {
        if (temp->value > max_num) 
            max_num = temp->value;
        temp = temp->next;
    }

    // Calcular el número de bits necesarios para representar max_num
    int max_bits = 0;
    while ((max_num >> max_bits) != 0) 
        max_bits++;

    // Recorrer cada bit
    int i = 0;
    while (i < max_bits) 
    {
        int j = 0;
        while (j < size) 
        {
            int num = top(*a);
            if ((num >> i) & 1) 
                // Si el bit en la posición i es 1, dejarlo en 'a'
                pa(a, &b, 0);  // ra() equivale a dejarlo en 'a'
            else 
                // Si el bit en la posición i es 0, moverlo a 'b'
                pb(&b, a, 0);  // pb() equivale a mover de 'a' a 'b'
            j++;
        }
        // Mover los elementos de 'b' de vuelta a 'a' en el orden correcto
        while (!is_empty(b)) 
            pa(a, &b, 0);  // pa() equivale a mover de 'b' a 'a'
        i++;
    }
}
