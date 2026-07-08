/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:03:54 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/08 12:43:49 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define STRATEGY_SIMPLE	0
# define STRATEGY_MEDIUM	1
# define STRATEGY_COMPLEX	2
# define STRATEGY_ADAPTIVE	3

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
} t_stack;

typedef struct s_bench
{
	int	enabled;
	int	strategy;
	float	disorder;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
} t_bench;

/*stack.c functions*/
t_stack	*stack_init(void);
t_node	*create_node(int value, int rank);
int		stack_is_empty(t_stack *s);
t_node	*stack_get_at(t_stack *s, int i);
void	stack_free(t_stack *s);

/*stack_operations.c*/
void	stack_push(t_stack *s, int value, int rank);
int		stack_pop(t_stack *s, int *value, int *rank);
int		stack_pop_rank(t_stack *s);
int		stack_peek_value(t_stack *s);
int		stack_peek_rank(t_stack *s);

/*operations.c functions*/

/*normalize.c functions*/
void	normalize(t_stack *s);

/*disorder.c functions*/

/*sort_simple.c functions*/

/*sort_medium.c functions*/

/*sort_complex.c functions*/

/*sort_adaptive.c functions*/

/*cost.c functions*/

/*utils.c functions*/

/*bench.c functions*/

/*error.c functions*/





#endif