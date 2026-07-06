/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:33 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/06 20:03:19 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*arr_temp(t_stack *s)
{
	int	*temp;
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

static int	*sort_temp(int *arr, int size)
{
	int	i;
	int j;
	int	*ord_arr;
	int	temp;

	if (!arr)
		return (NULL);
	ord_arr = malloc((size + 1) * sizeof(int));
	if (!ord_arr)
		return (NULL);
	i = -1;
	while (++i < size)
		ord_arr[i] = arr[i];
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
	return (ord_arr);
}

static int	find_rank(int *sorted, int size, int value)
{

}

void	normalize(t_stack *a)
{}


