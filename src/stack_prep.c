/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrael <azrael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:32:55 by awooden           #+#    #+#             */
/*   Updated: 2022/10/12 16:31:50 by azrael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_non_numeric(char *argv)
{
	if (*argv != '-' && *argv != '+' && ft_isdigit(*argv) == 0)
		return (1);
	if ((*argv == '-' || *argv == '+') && ft_isdigit(*(argv + 1)) == 0)
		return (1);
	argv++;
	while (*argv)
	{
		if (ft_isdigit(*argv) == 0)
			return (1);
		argv++;
	}
	return (0);
}

char	check_input(char **str_arr)
{
	while (*str_arr)
	{
		if (check_non_numeric(*str_arr))
			return (1);
		if (**str_arr == '-')
		{
			if (ft_strlen(*str_arr) > 11)
				return (1);
			if (ft_strlen(*str_arr) == 11 && \
			ft_strcmp(*str_arr, "-2147483648") > 0)
				return (1);
		}
		else
		{
			if (ft_strlen(*str_arr) > 10)
				return (1);
			if (ft_strlen(*str_arr) == 10 && \
			ft_strcmp(*str_arr, "2147483647") > 0)
				return (1);
		}
		if (ft_strfind(*str_arr, str_arr + 1))
			return (1);
		str_arr++;
	}
	return (0);
}

int	lst_indexate(t_list *astack, int val)
{
	int		res;

	res = 0;
	if (astack == NULL)
		return (-1);
	while (astack != NULL)
	{
		if (astack->content < val)
			res++;
		astack = astack->next;
	}
	return (res);
}

t_list	*parse_to_stack(char **str_arr)
{
	t_list	*astack;
	t_list	*tmp;
	int		new_val;

	astack = NULL;
	while (*str_arr)
	{
		new_val = ft_atoi(*str_arr);
		ft_lstadd_back(&astack, ft_lstnew(new_val));
		str_arr++;
	}
	tmp = astack;
	while (tmp != NULL)
	{
		tmp->index = lst_indexate(astack, tmp->content);
		tmp = tmp->next;
	}
	return (astack);
}

void	cut_syms(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '+')
		{
			while (argv[i][j + 1])
			{
				argv[i][j] = argv[i][j + 1];
				j++;
			}
			argv[i][j] = '\0';
		}
		if ((argv[i][0] == '-' || argv[i][0] == '0') && argv[i][1] == '0')
		{
			argv[i][j] = argv[i][j + 1];
			argv[i][1] = '\0';
		}
		i++;
	}
}
