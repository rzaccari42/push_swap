/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:41:18 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/30 17:28:23 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Get the size of a linked list.
 * 
 * This function calculates and returns the size of a linked list.
 * It counts the number of nodes in the list starting 
 * from the given node.
 * 
 * @param stack Pointer to the head of the linked list.
 * @return The number of nodes in the linked list.
 */
int	stack_size(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
 * @brief Get the last node of a linked list.
 * 
 * This function returns a pointer to the last node of a linked list.
 * 
 * @param node Pointer to the head of the linked list.
 * @return Pointer to the last node of the linked list, 
 * or NULL if the list is empty.
 */
t_stack_node	*stack_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Frees all nodes in the stack.
 *
 * This function iterates through the stack, freeing each node's memory.
 * It sets the stack pointer to NULL after all nodes are freed.
 *
 * @param stack Pointer to the stack to be freed.
 */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

/**
 * @brief Appends a new node with the given value to the end of the stack.
 *
 * This function creates a new node with the specified value and appends it 
 * to the end of the stack. If the stack is empty, the new node becomes 
 * the first node. The function handles memory allocation for the new node
 * and updates the previous and next pointers accordingly.
 *
 * @param stack Pointer to the stack to which the new node will be appended.
 * @param nbr The integer value to be stored in the new node.
 */
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = stack_last(*stack);
		last->next = node;
		node->prev = last;
	}
}
