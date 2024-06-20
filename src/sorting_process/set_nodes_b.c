/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:46:32 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/29 15:35:48 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sets the target node in stack `a` for each node in stack `b`.
 *
 * This function iterates through each node in stack `b` and finds the 
 * appropriate target node in stack `a`. The target node is the node in 
 * stack `a` with the smallest value that is greater than the value 
 * of the current node in stack `b`. If no such node exists, the target node 
 * is set to the node with the minimum value in stack `a`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	long			closest_bigger;

	while (b)
	{
		current = a;
		closest_bigger = LONG_MAX;
		while (current)
		{
			if (current->nbr > b->nbr && current->nbr < closest_bigger)
			{
				target = current;
				closest_bigger = current->nbr;
			}
			current = current->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target_node = stack_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

/**
 * @brief Sets the current index and target node for each node in 
 * stacks `a` and `b`.
 *
 * This function updates the current index for each node in
 * stacks `a` and `b`, and then sets the target node in stack `a` 
 * for each node in stack `b` by calling `set_target_b`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
void	set_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_b(a, b);
}
