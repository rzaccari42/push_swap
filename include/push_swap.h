/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:07:01 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/30 17:28:25 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/include/libft.h"

/**
 * @brief Structure representing a linked list of integers
 * 
 * This structure represents a node of a linked list containing integers.
 * Each node contains an integer value and a pointer to the next node 
 * in the list. The sort_val field is used to store a simplyfied version of 
 * the integer value (val), making the list more efficient for the push_swap 
 * sorting algorithms. 
 */
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				is_above_median;
	bool				is_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

/* s_stack functions */
void			init_stack(t_stack_node **stack, char **argv);
void			append_node(t_stack_node **stack, int nbr);
void			free_stack(t_stack_node **stack);
t_stack_node	*stack_last(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
t_stack_node	*stack_min(t_stack_node *stack);
t_stack_node	*stack_max(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
void			set_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_nodes_b(t_stack_node *a, t_stack_node *b);
void			set_current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

/* Instruction set functions */
void			sa(t_stack_node **first);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/* push_swap functions */
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			print_stack(t_stack_node *stack);
#endif
