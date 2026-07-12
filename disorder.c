/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:01:55 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 23:40:33 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*array(t_stack *s)
{
	t_node	*node;
	int		*ranks;
	int		i;

	if (!s || s->size < 2)
		return (NULL);
	node = s->top;
	ranks = malloc((s->size + 1) * sizeof(int));
	if (!ranks)
		return (NULL);
	i = 0;
	while (node)
	{
		ranks[i] = node->rank;
		node = node->next;
		i++;
	}
	return (ranks);
}

static float	count_inversions(int *ranks, int size)
{
	int	mistakes;
	int	tot_pairs;
	int	i;
	int	j;

	mistakes = 0;
	tot_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			tot_pairs++;
			if (ranks[i] > ranks[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (tot_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)tot_pairs);
}

float	compute_disorder(t_stack *s)
{
	int		*ranks;
	float	result;

	if (!s || s->size < 2)
		return (0.0f);
	ranks = array(s);
	result = count_inversions(ranks, s->size);
	free(ranks);
	return (result);
}

// float	compute_disorder(t_stack *s)
// {
// 	int	*ranks;
// 	int	mistakes;
// 	int	tot_pairs;
// 	int	i;
// 	int	j;

// 	if (!s || s->size < 2)
// 		return (0.0f);
// 	ranks = array(s);
// 	mistakes = 0;
// 	tot_pairs = 0;
// 	i = 0;
// 	while (i < (s->size - 1))
// 	{
// 		j = i + 1;
// 		while (j < s->size)
// 		{
// 			tot_pairs++;
// 			if (ranks[i] > ranks[j])
// 				mistakes++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	free(ranks);
// 	if (tot_pairs == 0)
// 		return (0.0f);
// 	return ((float)mistakes / (float)tot_pairs);
// }
