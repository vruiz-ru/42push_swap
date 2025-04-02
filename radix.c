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

int find_max(t_node *stack)
{
    if (!stack) 
        return 0; // Si la pila está vacía, retornamos 0

    int max = stack->value; // Inicializamos con el primer valor de la pila
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

int find_min(t_node *b)
{
    if (b == NULL)  // Si la pila está vacía, no hay un mínimo.
        return -1;  // Valor que indica que la pila está vacía.

    int min = b->value;  // Asumimos que el primer elemento es el mínimo.
    t_node *temp = b->next;  // Empezamos desde el segundo nodo.

    // Recorremos la pila para encontrar el mínimo.
    while (temp != NULL)
    {
        if (temp->value < min)
        {
            min = temp->value;  // Actualizamos el mínimo si encontramos un valor menor.
        }
        temp = temp->next;  // Avanzamos al siguiente nodo.
    }

    return min;  // Retornamos el valor mínimo encontrado.
}


// Función para obtener el valor del tope del stack
int top(t_node *stack) 
{
    if (stack == NULL) 
        return -1;
    return stack->pos;
}

void print_stack2(t_node *stack, char name)
{
    printf("Stack %c: ", name);
    while (stack)
    {
        printf("%d ", stack->pos);
        stack = stack->next;
    }
    printf("\n");
}

void radix_sort(t_node **a)
{
    
    t_node *b;
    t_node *temp;
    int  size;
    int  max_num;
    int max_bits;
    int i;
    int j;
    int pushed;
    int num;
    
    if (is_sorted(*a))  // 🔥 Verifica si ya está ordenado
        return;

    b = NULL;
    size = stack_len(*a);
    max_num = 0;
    temp = *a;

    // ✅ Encontrar el valor máximo
    while (temp)
    {
        if (temp->pos > max_num)
            max_num = temp->pos;
        temp = temp->next;
    }

    // ✅ Calcular bits necesarios
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        pushed = 0;
        j = 0;
        printf("Iteration %d:\n", i);
         print_stack2(*a, 'A');
        print_stack2(b, 'B');
        // 🔄 No mover elementos ya ordenados en la parte inferior
        while (j < size)
        {
            if (((*a)->pos >> i) & 1)
                ra(a, 0);  // Rotar si el bit es 1
            else
            {
                pb(&b, a, 0);  // Pasar a 'b' si el bit es 0
                pushed++;
            }
            j++;
        }

         //🔄 No mover elementos ya ordenados en la parte superior de b
         while (pushed > 0)
         {
            pa(a, &b, 0);
            pushed--;
         }
       
       

        // 🔄 No mover elementos ya ordenados en la parte superior de `b`
        /*while (pushed > 0)
        {
            if ((((b->pos >> (i + 1)) & 1) == 1)) // Si el siguiente bit es 1, mover a `a`
                pa(a, &b, 0);
            else
                rb(&b, 0);  // Si el siguiente bit es 0, solo rotar dentro de `b`
            
            pushed--;
        }*/

        i++;
    }

    // 🔥 Ajuste final con `rra` si es necesario
    //int min_pos = find_min(*a);
    //while ((*a)->pos != min_pos)
     //   rra(a, 0);
}

