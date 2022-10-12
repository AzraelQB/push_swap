/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:27:03 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 20:41:28 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a_stack)
{
	int		first;
	int		second;
	int		third;

	first = (*a_stack)->index;
	second = (*a_stack)->next->index;
	third = (*a_stack)->next->next->index;
	if (second < third && third < first)
		exec_ra(a_stack);
	else if (second < first && first < third)
		exec_sa(a_stack);
	else if (third < first && first < second)
		exec_rra(a_stack);
	else if (first < third && third < second)
	{
		exec_rra(a_stack);
		exec_sa(a_stack);
	}
	else if (third < second && second < first)
	{
		exec_ra(a_stack);
		exec_sa(a_stack);
	}
}

void	sort_five(t_list **a_stack, int freedom_ind)
{
	t_list	*b_stack;
	int		elem_pos;
	int		counter;
	int		stack_size;

	b_stack = NULL;
	counter = 0;
	stack_size = ft_lstsize(*a_stack);
	while (stack_size > 3)
	{
		elem_pos = get_elem_pos_a(*a_stack, freedom_ind, stack_size);
		get_elem(a_stack, elem_pos, stack_size, 'a');
		exec_pb(a_stack, &b_stack);
		counter++;
		stack_size = ft_lstsize(*a_stack);
	}
	sort_three(a_stack);
	exec_pa(a_stack, &b_stack);
	exec_pa(a_stack, &b_stack);
}

void	sort_b(t_list **a_stack, t_list **b_stack)
{
	int		stack_size;
	int		elem_pos;

	stack_size = ft_lstsize(*b_stack);
	while (stack_size)
	{
		elem_pos = get_elem_pos_b(*b_stack, stack_size);
		get_elem(b_stack, elem_pos, stack_size, 'b');
		exec_pa(a_stack, b_stack);
		stack_size = ft_lstsize(*b_stack);
	}
}

void	butt_sort(t_list **a_stack, int freedom_ind)
{
	t_list	*b_stack;
	int		i;

	b_stack = NULL;
	i = 0;
	while (*a_stack)
	{
		if ((*a_stack)->index <= i && i > 1)
		{
			exec_pb(a_stack, &b_stack);
			exec_rb(&b_stack);
			i++;
		}
		else if ((*a_stack)->index <= i + freedom_ind)
		{
			exec_pb(a_stack, &b_stack);
			i++;
		}
		else if ((*a_stack)->index >= i)
			exec_ra(a_stack);
	}
	sort_b(a_stack, &b_stack);
}

int	main(int argc, char **argv)
{
	t_list	*astack;

	if (argc <= 2)
		return (0);
	cut_syms(++argv);
	if (check_input(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_chars_sorted(argv))
		return (0);
	astack = parse_to_stack(argv);
	if (ft_lstsize(astack) == 2)
		exec_sa(&astack);
	else if (ft_lstsize(astack) <= 3)
		sort_three(&astack);
	else if (ft_lstsize(astack) <= 5)
		sort_five(&astack, 0);
	else if (ft_lstsize(astack) <= 100)
		butt_sort(&astack, 15);
	else
		butt_sort(&astack, 30);
	ft_lstfree(&astack);
	return (0);
}

	// while (b_stack)
	// {
	// 	printf(" c: %d i: %d \n", b_stack->content, b_stack->index);
	// 	b_stack = b_stack->next;
	// }
	// while (*a_stack)
	// {
	// 	printf(" c: %d i: %d \n", (*a_stack)->content, (*a_stack)->index);
	// 	(*a_stack) = (*a_stack)->next;
	// }

	// ar[0] = "214";
	// ar[1] = "21";
	// ar[2] = "14";
	// ar[3] = "2142";
	// ar[4] = "1";
	// ar[5] = "2141";
	// ar[6] = "3";
	// ar[7] = "4";
	// ar[8] = "21424";
	// ar[9] = "45581";
	// ar[10] = "275614";
	// ar[11] = "2651";
	// ar[12] = "144";
	// ar[13] = "21472";
	// ar[14] = "1576";

	// stack_size = ft_lstsize(*a_stack);
	// while (stack_size)
	// {
	// 	elem_pos = get_elem_pos_a(*a_stack, freedom_ind, stack_size);
	// 	get_elem(a_stack, elem_pos, stack_size, 'a');
	// 	exec_pb(a_stack, &b_stack);
	// 	if ((b_stack)->index <= i++)
	// 		exec_rb(&b_stack);
	// 	stack_size = ft_lstsize(*a_stack);
	// }
// 	int	get_back_pos_a(t_list *astack, int freedom_ind)
// {
// 	t_list	*cur;
// 	int		res;

// 	res = 1;
// 	cur = ft_lstlast(astack);
// 	while (cur->index > freedom_ind)
// 	{
// 		res++;
// 		cur = astack;
// 		while (cur->next->next)
// 			cur = cur->next;
// 		free(cur->next);
// 		cur->next = NULL;
// 		cur = ft_lstlast(astack);
// 	}
// 	return (res);
// }

// int	get_elem_pos_a(t_list *astack, int freedom_ind, int stack_size)
// {
// 	t_list	*cur;
// 	int		forw_pos;
// 	int		back_pos;

// 	forw_pos = 0;
// 	astack = ft_lstcopy(astack);
// 	cur = astack;
// 	while (cur->index > freedom_ind)
// 	{
// 		forw_pos++;
// 		cur = cur->next;
// 	}
// 	back_pos = get_back_pos_a(astack, freedom_ind);
// 	lstfree(&astack);
// 	//back_pos == forw_pos
// 	if (forw_pos <= back_pos)
// 		return (forw_pos);
// 	return (stack_size - back_pos);
// }

	// 	while (*a_stack)
	// {
	// 	printf(" c: %d i: %d \n", (*a_stack)->content, (*a_stack)->index);
	// 	(*a_stack) = (*a_stack)->next;
	// }

	// 	while (*a_stack)
	// {
	// 	printf(" c: %d i: %d \n", (*a_stack)->content, (*a_stack)->index);
	// 	(*a_stack) = (*a_stack)->next;
	// }