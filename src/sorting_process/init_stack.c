/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:33:07 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/29 15:35:54 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Check if a string represents a valid integer
 * 
 * This function checks if a given string represents a valid integer.
 * It examines each character of the string and verifies that it is a digit.
 * 
 * @param arg String to be checked
 * 
 * @return 1 if the string represents a valid integer, 0 otherwise
 */
static int	error_syntax(char *arg)
{
	if ((*arg == '-' && ft_isdigit(*(arg + 1))) ||
		(*arg == '+' && ft_isdigit(*(arg + 1))))
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (1);
		arg++;
	}
	return (0);
}

/**
 * @brief Check if a value exists in the stack
 * 
 * This function checks if a given value exists in the stack.
 * It iterates through each element of the stack and compares
 * the value of each element with the given value.
 * 
 * @param stack Pointer to the head of the stack
 * @param nbr Value to be checked in the stack
 * 
 * @return 1 if the value exists in the stack, 0 otherwise
 */
static int	error_duplicate(t_stack_node *stack, int nbr)
{
	int	val;

	while (stack)
	{
		val = stack->nbr;
		if (val == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * @brief Frees memory allocated for a stack and exits the program with 
 * an error message.
 *
 * This function frees the memory allocated for a stack and exits 
 * the program with an error message.
 * It iterates through the stack, freeing each node until the stack is empty.
 * Additionally, it prints an error message to the standard error 
 * output stream.
 *
 * @param stack Pointer to a pointer to the stack to be freed.
 */
static void	free_error(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error, invalid list.\n");
	exit(1);
}

/**
 * @brief Initializes the stack `a` with values from the `argv` array.
 *
 * This function iterates through the `argv` array, converts each string 
 * to a long integer, checks for syntax errors, range errors, and duplicate 
 * values. If any error is found, the function calls `free_error` to free 
 * the stack and handle the error. Otherwise, it appendsthe value 
 * to the stack `a`.
 *
 * @param stack Pointer to the stack `a`.
 * @param argv Array of string arguments to be converted and added to 
 * the stack.
 */
void	init_stack(t_stack_node **stack, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(stack);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(stack);
		if (error_duplicate(*stack, (int)nbr))
			free_error(stack);
		append_node(stack, (int)nbr);
		i++;
	}
}
