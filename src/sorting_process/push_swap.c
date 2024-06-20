/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:19:46 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/31 16:20:20 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Frees the memory allocated to split argv string.
 *
 * This function releases the memory allocated for the array of strings 
 * created by `ft_split`. It iterates through each string in the array, 
 * frees it, and then frees the array itself.
 *
 * @param args The array of strings to be freed. This is typically the result 
 * of `ft_split`.
 */
static void	free_args(char **args)
{
	char	**current;

	current = args;
	if (args)
	{
		while (*current)
		{
			free(*current);
			current++;
		}
		free(args);
	}
}

/**
 * @brief Executes sorting operations on stacks a and b.
 *
 * This function checks if the stack `a` is already sorted. If it is not,
 * it applies the appropriate sorting operations based on the size of 
 * the stack. 
 * If the stack `a` contains 2 elements, it applies the `sa` operation. 
 * If it contains 3 elements, it calls `sort_three`. For larger sizes, 
 * it calls `sort_stacks`.
 *
 * @param a Pointer to the stack `a`.
 * @param b Pointer to the stack `b`.
 */
static void	push_swap(t_stack_node **a, t_stack_node **b)
{
	if (is_sorted(*a) == false)
	{
		if (stack_size(*a) == 2)
			sa(a);
		else if (stack_size(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
	else
	{
		ft_printf("List sorted\n");
		return ;
	}
}

/**
 * @brief Main entry point of the sorting program.
 *
 * This function initializes the stacks `a` and `b` based on the provided 
 * command-line arguments. If a single argument is provided, it is split 
 * into multiple parts using `ft_split`.
 * The stacks are then initialized and the `push_swap` function is called to 
 * perform the sorting.
 * Finally, the allocated memory is freed before exiting.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Returns 0 if the program runs successfully, otherwise 1.
 */
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_argv;

	a = NULL;
	b = NULL;
	split_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv[0])
			return (1);
		argv = split_argv;
		init_stack(&a, argv);
	}
	else
		init_stack(&a, argv + 1);
	push_swap(&a, &b);
	free_stack(&a);
	if (split_argv)
		free_args(split_argv);
	return (0);
}
