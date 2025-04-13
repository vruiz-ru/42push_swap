/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:07:25 by vruiz-ru          #+#    #+#             */
/*   Updated: 2025/04/03 18:55:06 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

long				ft_atol(const char *str);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
void				free_matrix(char **argv);
void				free_stack(t_node **stack);
void				error_free(t_node **a, char **argv, bool flag_argc_2);
int					error_syntax(char *str_nbr);
int					error_repetition(t_node *a, int nbr);
void				append_node(t_node **stack, int nbr);
t_node				*find_last_node(t_node *head);
void				pa(t_node **a, t_node **b, bool checker);
void				pb(t_node **b, t_node **a, bool checker);
void				ra(t_node **a, bool checker);
void				rb(t_node **b, bool checker);
int					stack_len(t_node *stack);
void				radix_sort(t_node **a);
void				sort_three(t_node **a);
int					is_sorted_a(t_node *stack);
void				sort_five(t_node **a);
void				sa(t_node **a, bool checker);
void				sb(t_node **b, bool checker);
void				rra(t_node **a, bool checker);

#endif