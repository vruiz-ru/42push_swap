/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:07:25 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/01/23 20:07:32 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct s_node {
    int value;
    int pos;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

int	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len); 
char	**ft_split(char const *s, char c);

#endif