/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:12:51 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/15 13:17:45 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_safe(char *str, int *error)
{
	long	num;
	int		sign;

	if (!str)
		return (0);
	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(num * sign));
}

int	has_duplicates(t_stack *s)
{
	t_node	*curr_node;
	t_node	*check_node;

	if (!s)
		return (0);
	curr_node = s->top;
	while (curr_node)
	{
		check_node = curr_node->next;
		while (check_node)
		{
			if (curr_node->value == check_node->value)
				return (1);
			check_node = check_node->next;
		}
		curr_node = curr_node->next;
	}
	return (0);
}
