/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 01:19:13 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/30 15:29:47 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Finds the node with the minimum value in the stack.
 *
 * This function iterates through the stack and returns a pointer to the node
 * with the minimum value. If the stack is empty, it returns NULL.
 *
 * @param stack Pointer to the stack.
 * @return Pointer to the node with the minimum value, or NULL if the stack
 * is empty.
 */
t_stack_node	*stack_min(t_stack_node *stack)
{
	t_stack_node	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Finds the node with the maximum value in the stack.
 *
 * This function iterates through the stack and returns a pointer to the node
 * with the maximum value. If the stack is empty, it returns NULL.
 *
 * @param stack Pointer to the stack.
 * @return Pointer to the node with the maximum value, or NULL if the stack 
 * is empty.
 */
t_stack_node	*stack_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 *
 * This function iterates through the stack and checks if each node's value
 * is less than or equal to the value of the next node. If the stack 
 * is sorted in ascending order, it returns true. Otherwise, it returns false.
 * An empty stack or a stack with a single node is considered sorted.
 *
 * @param stack Pointer to the stack.
 * @return true if the stack is sorted in ascending order, false otherwise.
 */
bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * @brief Finds the node marked as the cheapest in the stack.
 *
 * This function iterates through the stack and returns a pointer to the node
 * marked as the cheapest. If no such node is found or the stack is empty,
 * it returns NULL.
 *
 * @param stack Pointer to the stack.
 * @return Pointer to the cheapest node, or NULL if no such node is found or
 * the stack is empty.
 */
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
