/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:01:55 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/10 12:06:44 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *s)
{
	int	mistakes;
	int	tot_pairs;
	int	i;
	int	j;

	if (!s || s->size < 2)
		return (0.0f);
	mistakes = 0;
	tot_pairs = 0;
	i = 0;
	while (i < (s->size - 1))
	{
		j = i + 1;
		while (j < (s->size))
		{
			tot_pairs++;
			if (stack_get_at(s, i)->value > stack_get_at(s, j)->value)
				mistakes++;
			j++;
		}
		i++;
		if (tot_pairs == 0)
			return (0.0f);
	}
	return ((float)mistakes / (float)tot_pairs);
}