
#include "push_swap.h"

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

void recursive_quick_sort(t_node **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
    {
        printf("Base case reached. Returning...\n");
        return; // Caso base, ya está ordenado
    }

    printf("Sorting stack:\n");
    print_stack(*stack);

    t_node *pivot = choose_pivot(*stack);
    printf("Pivot chosen: %d\n", pivot->value);

    t_node *less = NULL, *greater = NULL, *equal = NULL;
    split_list(*stack, pivot, &less, &equal, &greater);

    printf("Less than pivot:\n");
    print_stack(less);
    printf("Equal to pivot:\n");
    print_stack(equal);
    printf("Greater than pivot:\n");
    print_stack(greater);

    recursive_quick_sort(&less);
    recursive_quick_sort(&greater);

    *stack = merge_sorted_chunks(less, equal, greater);

    printf("Merged stack:\n");
    print_stack(*stack);
}
