/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:18:21 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/30 17:28:28 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sets the index and median status for each node in the stack.
 *
 * This function iterates through the stack and assigns an index to each node.
 * It also determines whether each node is above or below the median index.
 *
 * @param stack Pointer to the stack.
 */
void	set_current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		i++;
	}
}

/**
 * @brief Sets the target node in stack `b` for each node in stack `a`.
 *
 * This function iterates through each node in stack `a` and finds the 
 * appropriate target node in stack `b`. The target node is the node in 
 * stack `b` with the largest value that is smaller than the value of 
 * the current node in stack `a`. If no such node exists, the target node 
 * is set to the node with the maximum value in stack `b`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			closest_smaller;

	while (a)
	{
		current = b;
		closest_smaller = LONG_MIN;
		while (current)
		{
			if (current->nbr < a->nbr && current->nbr > closest_smaller)
			{
				target = current;
				closest_smaller = current->nbr;
			}
			current = current->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target_node = stack_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

/**
 * @brief Sets the push cost for each node in stack `a`.
 *
 * This function calculates the push cost for each node in stack `a` based 
 * on its index and the index of its target node in stack `b`. 
 * The cost is determined by the number of operations required to move 
 * the node to the top of stack `a` and its target node to the top 
 * of stack `b`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
static void	set_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->is_above_median == false)
			a->push_cost = size_a - (a->index);
		if (a->target_node->is_above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += size_b - (a->target_node->index);
		a = a->next;
	}
}

/**
 * @brief Marks the node with the lowest push cost as the cheapest.
 *
 * This function iterates through the stack and finds the node with 
 * the lowest push cost. It then marks this node as the cheapest by setting 
 * its `is_cheapest` flag to true.
 *
 * @param stack Pointer to the stack.
 */
void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	long			min;

	if (!stack)
		return ;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < min)
		{
			cheapest = stack;
			min = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest->is_cheapest = true;
}

/**
 * @brief Sets the index, target node, push cost, and cheapest node for 
 * stack `a`.
 *
 * This function updates various attributes for the nodes in stack `a`:
 * - Sets the current index and median status for each node in `a` and `b`.
 * - Sets the target node in `b` for each node in `a`.
 * - Calculates the push cost for each node in `a`.
 * - Identifies and marks the cheapest node in `a`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
void	set_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}
