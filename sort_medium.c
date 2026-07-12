/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:45:45 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 18:04:27 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_medium(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b)
		return ;
	if (stack_is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a, bench);
		return ;
	}
	push_chunks_to_b(a, b, bench);
	push_sorted_to_a(a, b, bench);
}