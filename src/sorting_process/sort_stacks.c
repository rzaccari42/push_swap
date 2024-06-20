/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:43:42 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/30 17:40:45 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Rotates both stacks `a` and `b` simultaneously until `cheapest` 
 * or its target are at the top.
 *
 * This function checks if `cheapest` and its target node in stack `b` 
 * are above the median. If both are above the median, it performs 
 * simultaneous rotations (`rr`) until one of them is at the top.
 * If both are below the median, it performs reverse simultaneous 
 * rotations (`rrr`) until one of them is at the top.
 * After rotations, it updates the current index of both stacks.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 * @param cheapest Pointer to the node in stack `a` that needs to be moved.
 */
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	if (cheapest->is_above_median && cheapest->target_node->is_above_median)
	{
		while (*b != cheapest->target_node && *a != cheapest)
			rr(a, b);
	}
	else if (cheapest->is_above_median == false
		&& cheapest->target_node->is_above_median == false)
	{
		while (*b != cheapest->target_node && *a != cheapest)
			rrr(a, b);
	}
	set_current_index(*a);
	set_current_index(*b);
}

/**
 * @brief Rotates the specified stack until `new_top` is at the top.
 *
 * This function rotates the given stack until the specified node 
 * `new_top` is at the top. It uses the `stack_id` to determine whether 
 * to rotate  stack `a` or stack `b` and whether to perform a regular or 
 * reverse rotation based on the position of `new_top` relative to the median.
 *
 * @param stack Pointer to the stack to be rotated.
 * @param new_top Pointer to the node that needs to be moved to the top.
 * @param stack_id Character indicating which stack to rotate ('a' or 'b').
 */
void	rotate_to_top(t_stack_node **stack, t_stack_node *new_top,
		char stack_id)
{
	while (*stack != new_top)
	{
		if (stack_id == 'a')
		{
			if (new_top->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_id == 'b')
		{
			if (new_top->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/**
 * @brief Moves the cheapest node from stack `a` to stack `b`.
 *
 * This function identifies the cheapest node in stack `a` to be moved 
 * to stack `b`. It performs the necessary rotations on both stacks to bring 
 * the cheapest node and its target to the top, then pushes the node 
 * from `a` to `b`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
static void	move_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	rotate_both(a, b, cheapest);
	rotate_to_top(a, cheapest, 'a');
	rotate_to_top(b, cheapest->target_node, 'b');
	pb(b, a);
}

/**
 * @brief Moves the top node from stack `b` to stack `a`.
 *
 * This function rotates stack `a` to position the target node at the top, 
 * then pushes the top node from stack `b` to stack `a`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
static void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	rotate_to_top(a, (*b)->target_node, 'a');
	pa(a, b);
}

/**
 * @brief Sorts the elements in stack `a` using stack `b` as an 
 * auxiliary stack.
 *
 * This function implements a sorting algorithm for stack `a` with the help 
 * of an auxiliary stack `b`.
 * The algorithm works as follows:
 * 1. Pushes elements from `a` to `b` until `a` contains only 3 elements or 
 * is sorted.
 * 2. Sorts the remaining 3 elements in `a` using the `sort_three` function.
 * 3. Moves elements back from `b` to `a` in sorted order.
 * 4. Rotates `a` to position the smallest element at the top.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if (size_a-- > 3 && is_sorted(*a) == false)
		pb(b, a);
	if (size_a-- > 3 && is_sorted(*a) == false)
		pb(b, a);
	while (size_a-- > 3 && is_sorted(*a) == false)
	{
		set_nodes_a(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_nodes_b(*a, *b);
		move_to_a(a, b);
	}
	set_current_index(*a);
	rotate_to_top(a, stack_min(*a), 'a');
}
