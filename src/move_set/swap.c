/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:31:06 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 04:55:43 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Swaps the first two nodes of the stack.
 *
 * This function swaps the first two nodes of the stack. If the stack is 
 * empty or contains only one node, the function does nothing.
 *
 * @param head Pointer to the stack to be swapped.
 */
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

/**
 * @brief Swaps the first two nodes of stack `a`.
 *
 * This function calls `swap` to swap the first two nodes of stack `a`.
 * After the swap operation, it prints "sa" to indicate the action performed.
 *
 * @param a Pointer to stack `a`.
 */
void	sa(t_stack_node	**a)
{
	swap(a);
	ft_printf("sa\n");
}

/**
 * @brief Swaps the first two nodes of stack `b`.
 *
 * This function calls `swap` to swap the first two nodes of stack `b`.
 * After the swap operation, it prints "sb" to indicate the action performed.
 *
 * @param b Pointer to stack `b`.
 */
void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

/**
 * @brief Swaps the first two nodes of both stacks `a` and `b`.
 *
 * This function calls `swap` to swap the first two nodes of both 
 * stacks `a` and `b`. After the swap operations, it prints "ss" to indicate 
 * the actions performed.
 *
 * @param a Pointer to stack `a`.
 * @param b Pointer to stack `b`.
 */
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
