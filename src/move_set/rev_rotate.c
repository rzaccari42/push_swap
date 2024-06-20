/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:34:04 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 03:46:50 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Performs a reverse rotation on the stack.
 *
 * This function moves the last node of the stack to the top, effectively 
 * performing a reverse rotation.
 * If the stack is empty or contains only one node, the function does nothing.
 *
 * @param stack Pointer to the stack to be reverse rotated.
 */
static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

/**
 * @brief Performs a reverse rotation on stack `a`.
 *
 * This function calls `rev_rotate` to perform a reverse rotation 
 * on stack `a`. After the reverse rotation, it prints "rra" to indicate 
 * the action performed.
 *
 * @param a Pointer to stack `a`.
 */
void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

/**
 * @brief Performs a reverse rotation on stack `b`.
 *
 * This function calls `rev_rotate` to perform a reverse rotation 
 * on stack `b`. After the reverse rotation, it prints "rrb" to indicate 
 * the action performed.
 *
 * @param b Pointer to stack `b`.
 */
void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

/**
 * @brief Performs a reverse rotation on both stacks `a` and `b`.
 *
 * This function calls `rev_rotate` to perform a reverse rotation 
 * on both stacks `a` and `b`. After the reverse rotations, 
 * it prints "rrr" to indicate the actions performed.
 *
 * @param a Pointer to stack `a`.
 * @param b Pointer to stack `b`.
 */
void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
