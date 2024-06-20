/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:28:53 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 03:58:38 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Performs a rotation on the stack.
 *
 * This function moves the first node of the stack to the end, 
 * effectively performing a rotation. If the stack is empty or contains 
 * only one node, the function does nothing.
 *
 * @param stack Pointer to the stack to be rotated.
 */
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = stack_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/**
 * @brief Performs a rotation on stack `a`.
 *
 * This function calls `rotate` to perform a rotation on stack `a`.
 * After the rotation, it prints "ra" to indicate the action performed.
 *
 * @param a Pointer to stack `a`.
 */
void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/**
 * @brief Performs a rotation on stack `b`.
 *
 * This function calls `rotate` to perform a rotation on stack `b`.
 * After the rotation, it prints "rb" to indicate the action performed.
 *
 * @param b Pointer to stack `b`.
 */
void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

/**
 * @brief Performs a rotation on both stacks `a` and `b`.
 *
 * This function calls `rotate` to perform a rotation on both stacks `a` and `b`.
 * After the rotations, it prints "rr" to indicate the actions performed.
 *
 * @param a Pointer to stack `a`.
 * @param b Pointer to stack `b`.
 */
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
