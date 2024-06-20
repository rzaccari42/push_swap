/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:35:28 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/30 17:29:00 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Pushes the top node from the source stack to the destination stack.
 *
 * This function removes the top node from the source stack `src` and pushes 
 * it onto the top of the destination stack `dst`. If the source stack 
 * is empty, the function does nothing.
 *
 * @param dst Pointer to the destination stack.
 * @param src Pointer to the source stack.
 */
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		(*dst)->prev = push_node;
		*dst = push_node;
	}
}

/**
 * @brief Pushes the top node from stack `b` to stack `a`.
 *
 * This function calls `push` to move the top node from stack `b` 
 * to stack `a`. After the push operation, it prints "pa" to indicate 
 * the action performed.
 *
 * @param a Pointer to stack `a`.
 * @param b Pointer to stack `b`.
 */
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

/**
 * @brief Pushes the top node from stack `a` to stack `b`.
 *
 * This function calls `push` to move the top node from stack `a` 
 * to stack `b`. After the push operation, it prints "pb" to indicate 
 * the action performed.
 *
 * @param b Pointer to stack `b`.
 * @param a Pointer to stack `a`.
 */
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
