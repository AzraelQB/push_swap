/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awooden <awooden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:27:09 by awooden           #+#    #+#             */
/*   Updated: 2022/03/14 16:32:43 by awooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned long long	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || \
	*str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (sum > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (sign * sum);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned long int	i;
	unsigned char		c1;
	unsigned char		c2;

	i = 0;
	while (s1[i] || s2[i])
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

int	ft_strfind(char *str, char **str_arr)
{
	if (!str || !str_arr)
		return (0);
	while (*str_arr)
	{
		if (ft_strcmp(str, *str_arr) == 0)
			return (1);
		str_arr++;
	}
	return (0);
}
