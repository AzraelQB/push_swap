/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:50:00 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 20:18:48 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strfind(char *str, char **str_arr);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstfree(t_list **alist);
int		ft_chars_sorted(char	**argv);
t_list	*ft_lstcopy(t_list *alist);
void	exec_pa(t_list **a_stack, t_list **b_stack);
void	exec_pb(t_list **a_stack, t_list **b_stack);
void	exec_sa(t_list **a_stack);
void	exec_sb(t_list **b_stack);
void	exec_ra(t_list **a_stack);
void	exec_rb(t_list **b_stack);
void	exec_rra(t_list **a_stack);
void	exec_rrb(t_list **b_stack);
int		check_non_numeric(char *argv);
void	cut_syms(char **argv);
char	check_input(char **str_arr);
int		lst_indexate(t_list *astack, int val);
t_list	*parse_to_stack(char **str_arr);
void	get_elem(t_list **astack, int elem_pos, int stack_size, char st);
int		get_back_pos_b(t_list *astack, int stack_size);
int		get_elem_pos_b(t_list *astack, int stack_size);
int		get_back_pos_a(t_list *astack, int freedom_ind);
int		get_elem_pos_a(t_list *astack, int freedom_ind, int stack_size);
void	sort_three(t_list **a_stack);
void	sort_five(t_list **a_stack, int freedom_ind);
void	butt_sort(t_list **a_stack, int freedom_ind);

#endif