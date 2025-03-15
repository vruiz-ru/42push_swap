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

int main(int ac, char **av)
{
    t_node *a;
    t_node *b;

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
    /*    stack_init(  );//crear stack a
    if(!stack_sorted(a))
    {
        //radix

    }
    free_stack(&a);
    */
    return(0);
}