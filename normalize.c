/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:33 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 22:23:59 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*arr_temp(t_stack *s)
{
	int		*temp;
	t_node	*curr_node;
	int		i;

	i = 0;
	if (!s || s->size == 0)
		return (NULL);
	curr_node = s->top;
	temp = malloc((s->size + 1) * sizeof(int));
	if (!temp)
		return (NULL);
	while (curr_node)
	{
		temp[i++] = curr_node->value;
		curr_node = curr_node->next;
	}
	return (temp);
}

static void	sort_array(int *ord_arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (ord_arr[j] < ord_arr[i])
			{
				temp = ord_arr[i];
				ord_arr[i] = ord_arr[j];
				ord_arr[j] = temp;
			}
		}
	}
}

static int	*sort_temp(int *arr, int size)
{
	int	*ord_arr;
	int	i;

	if (!arr)
		return (NULL);
	ord_arr = malloc((size + 1) * sizeof(int));
	if (!ord_arr)
		return (NULL);
	i = -1;
	while (++i < size)
		ord_arr[i] = arr[i];
	sort_array(ord_arr, size);
	return (ord_arr);
}

static int	find_rank(int *sorted, int size, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sorted[mid] == value)
			return (mid);
		else if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	normalize(t_stack *s)
{
	t_node	*curr_node;
	int		*sorted;
	int		*temp;

	if (!s || s->size == 0)
		return ;
	curr_node = s->top;
	temp = arr_temp(s);
	sorted = sort_temp(temp, s->size);
	free(temp);
	while (curr_node)
	{
		curr_node->rank = find_rank(sorted, s->size, curr_node->value);
		curr_node = curr_node->next;
	}
	free(sorted);
}
