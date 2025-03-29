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

/*
void radix_sort(t_node **a)
{
    if (is_sorted(*a))  // 🔥 Verifica si ya está ordenado
        return;

    t_node *b = NULL;
    int size = stack_len(*a);
    int max_num = 0;
    t_node *temp = *a;

    // ✅ Encontrar el valor absoluto máximo
    while (temp)
    {
        if (abs(temp->pos) > max_num)
            max_num = abs(temp->pos);
        temp = temp->next;
    }

    // ✅ Calcular bits necesarios
    int max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    int i = 0;
    while (i < max_bits)
    {
        int pushed = 0;
        int j = 0;
        int size_copy = size;

        // 🔄 No mover elementos ya ordenados en la parte inferior
        while (j < size_copy)
        {
            int num = top(*a);
            if ((num >> i) & 1)
                ra(a, 0);  // Rotar si el bit es 1
            else
            {
                pb(&b, a, 0);  // Pasar a 'b' si el bit es 0
                pushed++;
            }
            j++;
        }

        // 🔄 No mover elementos ya ordenados en la parte superior de `b`
        while (pushed > 0)
        {
            pa(a, &b, 0);
            pushed--;
        }

        i++;
    }

    // 🔥 Ajuste final con `rra` si es necesario
    int min_pos = find_min(*a);
    while ((*a)->pos != min_pos)
        rra(a, 0);
}
*/
//option2
/*
void radix_sort(t_node **a)
{
    if (is_sorted(*a))  // Verifica si ya está ordenado
        return;

    t_node *b = NULL;
    int size = stack_len(*a);
    int max_num = 0;
    t_node *temp = *a;

    // Encontrar el valor absoluto máximo
    while (temp)
    {
        if (abs(temp->pos) > max_num)
            max_num = abs(temp->pos);
        temp = temp->next;
    }

    // Calcular bits necesarios
    int max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    int i = 0;
    while (i < max_bits)
    {
        int pushed = 0;
        int j = 0;
        int size_copy = size;

        while (j < size_copy)
        {
            int num = top(*a);
            if ((num >> i) & 1)
                ra(a, 0);  // Rotar si el bit es 1
            else
            {
                pb(&b, a, 0);  // Pasar a 'b' si el bit es 0
                pushed++;
            }
            j++;
        }

        int pushed_b = pushed;
        while (pushed_b > 0)
        {
            if (b && ((top(b) >> (i + 1)) & 1) == 0)  // Si el siguiente bit también es 0
                rb(&b, 0);  // Mantener en B
            else
                pa(a, &b, 0);  // Devolver a A
            pushed_b--;
        }

        i++;
    }

    // Ajuste final con `rra` si es necesario
    int min_pos = find_min(*a);
    while ((*a)->pos != min_pos)
        rra(a, 0);
}
*/
//option 3
void radix_sort(t_node **a)
{
    if (is_sorted(*a))  // Verifica si ya está ordenado
        return;

    t_node *b = NULL;
    int size = stack_len(*a);
    int max_num = 0;
    t_node *temp = *a;

    // Encontrar el valor absoluto máximo
    while (temp)
    {
        if (abs(temp->pos) > max_num)
            max_num = abs(temp->pos);
        temp = temp->next;
    }

    // Calcular bits necesarios
    int max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    int i = 0;
    while (i < max_bits)
    {
        int pushed = 0;
        int j = 0;
        int size_copy = size;

        while (j < size_copy)
        {
            int num = top(*a);
            if ((num >> i) & 1)
                ra(a, 0);  // Rotar si el bit es 1
            else
            {
                pb(&b, a, 0);  // Pasar a 'b' si el bit es 0
                pushed++;
            }
            j++;
        }

        int pushed_b = pushed;
        while (pushed_b > 0)
        {
            if (b && ((top(b) >> (i + 1)) & 1) == 0)  // Si el siguiente bit también es 0
                rb(&b, 0);  // Mantener en B
            else
                pa(a, &b, 0);  // Devolver a A
            pushed_b--;
        }

        i++;
    }

    // Ajuste final con `rra` si es necesario
    int min_pos = find_min(*a);
    while ((*a)->pos != min_pos)
        rra(a, 0);
}
