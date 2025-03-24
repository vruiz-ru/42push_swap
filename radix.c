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
//version 2
  // Asegúrate de que este archivo contenga las declaraciones necesarias

// Obtiene el último nodo de la lista
t_node *get_last_node(t_node *list)
{
    while (list && list->next)
        list = list->next;
    return list;
}

// Función para elegir un pivote (usaremos el último elemento en la lista)
t_node *choose_pivot(t_node *stack)
{
    if (!stack || !stack->next)
        return stack;

    t_node *first = stack;
    t_node *last = get_last_node(stack);
    t_node *middle = stack;

    int len = 0;
    while (middle->next && len < stack_len(stack) / 2)
    {
        middle = middle->next;
        len++;
    }

    // Mediana de tres
    if ((first->value <= middle->value && middle->value <= last->value) ||
        (last->value <= middle->value && middle->value <= first->value))
        return middle;
    if ((middle->value <= first->value && first->value <= last->value) ||
        (last->value <= first->value && first->value <= middle->value))
        return first;
    return last;
}




// Función auxiliar para agregar un nodo a una lista
void add_to_list(t_node **list, t_node *node)
{
    if (!*list)
    {
        *list = node;
        node->prev = NULL;
        node->next = NULL;
        return;
    }

    t_node *tail = *list;
    while (tail->next)
        tail = tail->next;

    tail->next = node;
    node->prev = tail;
    node->next = NULL;
}


// Divide la lista en tres partes (menores, iguales y mayores al pivote)
void split_list(t_node *stack, t_node *pivot, t_node **less, t_node **equal, t_node **greater)
{
    while (stack)
    {
        t_node *next = stack->next; // Guardamos el siguiente nodo
        stack->next = NULL; // Desconectamos el nodo actual
        stack->prev = NULL; // Desconectamos el nodo actual

        if (stack->value < pivot->value)
            add_to_list(less, stack);
        else if (stack->value > pivot->value)
            add_to_list(greater, stack);
        else
            add_to_list(equal, stack);

        stack = next; // Pasamos al siguiente nodo
    }
}





// Fusiona las tres partes de la lista
t_node *merge_sorted_chunks(t_node *less, t_node *equal, t_node *greater)
{
    t_node *head = NULL, *tail = NULL;

    // Conectar `less`
    if (less)
    {
        head = less;
        tail = get_last_node(less);
    }

    // Conectar `equal`
    if (equal)
    {
        if (!head)
            head = equal;
        else
        {
            tail->next = equal;
            equal->prev = tail;
        }
        tail = get_last_node(equal);
    }

    // Conectar `greater`
    if (greater)
    {
        if (!head)
            head = greater;
        else
        {
            tail->next = greater;
            greater->prev = tail;
        }
    }

    return head;
}




void print_stack(t_node *stack)
{
    if (!stack)
    {
        printf("(empty stack)\n");
        return;
    }

    printf("Stack: ");
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}
void recursive_quick_sort(t_node **stack_a, t_node **stack_b) {
    // Caso base
    if (!stack_a || !(*stack_a) || !(*stack_a)->next) {
        return;
    }
    
    int pivot = (*stack_a)->value;
    printf("Pivot chosen: %d\n", pivot);
    
    // Partir la pila A
    t_node *temp_a = *stack_a;
    while (temp_a) {
        t_node *top = temp_a;
        temp_a = temp_a->next;
        
        if (top->value < pivot) {
            pb(stack_b, stack_a, false);
            printf("Moved %d to stack B\n", top->value);
        } else {
            // Cambio importante aquí:
            // Solo rotamos si el elemento es mayor que el pivote
            if (top->value > pivot) {
                ra(stack_a, false);
                printf("Rotated stack A\n");
            }
        }
    }
    
    // Continuar recursivamente
    recursive_quick_sort(stack_a, stack_b);
    recursive_quick_sort(stack_b, stack_a);
    
    // Fusionar resultados
    while (*stack_b) {
        pa(stack_a, stack_b, false);
        printf("Moved element from B to A\n");
    }
}