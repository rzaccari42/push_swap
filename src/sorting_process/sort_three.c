/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:52:38 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/27 23:51:49 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sorts a stack of three nodes in ascending order.
 *
 * This function sorts a stack of exactly three nodes. It first finds 
 * the node with the maximum value. Depending on the position of the 
 * maximum node, it performs one of the rotate operations (`ra` or `rra`)
 * to move the maximum node to the appropriate position. Then, it checks 
 * the first two nodes and swaps them if they are in the wrong order.
 *
 * @param a Pointer to the stack to be sorted.
 */
void	sort_three(t_stack_node **a)
{
	t_stack_node	*max;

	max = stack_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
