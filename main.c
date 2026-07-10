/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 14:48:24 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/10 11:54:43 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->enabled = 0;
	bench->strategy = STRATEGY_ADAPTIVE;
	bench->disorder = 0.0f;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

/*
Nel main, la sequenza corretta è:

```
1. costruisci la lista leggendo argv
2. valida (duplicati, overflow, caratteri invalidi)
3. controlla se già ordinata → se sì, esci senza stampare nulla
4. chiama normalize(a)          ← solo qui
5. calcola il disordine
6. esegui l'algoritmo scelto
```
*/