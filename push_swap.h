/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:03:54 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 10:20:36 by ealiman          ###   ########.fr       */
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

# define DISORDER_LOW       0.2f
# define DISORDER_MED       0.5f

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

/*operations_swap.c functions*/
void	op_sa(t_stack *a, t_bench *bench);
void	op_sb(t_stack *b, t_bench *bench);
void	op_ss(t_stack *a, t_stack *b,t_bench *bench);

/*operations_push.c*/
void	op_pa(t_stack *a, t_stack *b, t_bench *bench);
void	op_pb(t_stack *a, t_stack *b, t_bench *bench);

/*operations_rotate.c*/
void	op_ra(t_stack *a, t_bench *bench);
void	op_rb(t_stack *b, t_bench *bench);
void	op_rr(t_stack *a, t_stack *b, t_bench *bench);

/*operations_rev_rotate.c*/
void	op_rra(t_stack *a, t_bench *bench);
void	op_rrb(t_stack *b, t_bench *bench);
void	op_rrr(t_stack *a, t_stack *b, t_bench *bench);

/*normalize.c functions*/
void	normalize(t_stack *s);

/*disorder.c functions*/
float	compute_disorder(t_stack *s);

/*sort_simple.c functions*/
void	sort_three(t_stack *s, t_bench *bench);
void	sort_simple(t_stack *a, t_stack *b, t_bench *bench);

/*sort_medium.c functions*/
void	sort_medium(t_stack *a, t_stack *b, t_bench *bench);

/*sort_complex.c functions*/
void	sort_complex(t_stack *a, t_stack *b, t_bench *bench);

/*sort_adaptive.c functions*/
void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench);

/*cost.c functions*/
// int		cost_to_top(t_stack *s, t_node *node);
// int		best_move_cost(t_stack *a, t_stack *b);

/*bench.c*/
void	init_bench(t_bench *bench);
void	print_bench(t_bench *bench);

/*push_swap.c*/
void	error_exit(t_stack *a, t_stack *b, t_bench *bench);
int		parse_flags(int argc, char **argv, t_bench *bench);
void	run_sort(t_stack *a, t_stack *b, t_bench *bench);
int		push_swap(int argc, char **argv);

/*utils_find.c functions*/
t_node	*find_min(t_stack *s);
t_node	*find_max(t_stack *s);

/*utils.c functions*/
int		position_of(t_stack *s, t_node *target);
int		cost_to_top(t_stack *s, t_node *node);
int		direction(t_stack *s, t_node *node);
void	rotate_to_top(t_stack *s, t_node *node, t_bench *bench, char stack);
int		stack_is_sorted(t_stack *s);

/*utils_write.c*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_float_percent_fd(float n, int fd);
int		ft_strcmp(const char *s1, const char *s2);

/*utils_parsing.c*/
int		is_number(char *str);
int		ft_atoi_safe(char *str, int *error);
int		has_duplicates(t_stack *s);

/*utils_push_swap.c*/
void	free_and_return(t_stack *a, t_stack *b);
void	parse_and_fill_stack(int argc, char **argv, t_stack *a, t_bench *bench);
void	validate_and_prepare(t_stack *a, t_bench *bench);
void	execute_sort(t_stack *a, t_stack *b, t_bench *bench);


/*error.c functions*/


/*
L'errore più comune è iniziare dall'algoritmo più complesso. L'ordine corretto è:

1. Prima `push_swap.h` con la struttura dati
2. Poi `stack.c` con le operazioni primitive — testale subito stampando la pila
3. Poi `operations.c` — testa ogni operazione manualmente
4. Poi `normalize.c` — verifica che i ranghi siano corretti
5. Poi `disorder.c`
6. Poi `sort_simple.c` — il più facile, ti dà subito un programma funzionante
7. Poi `cost.c` — ottimizza il semplice
8. Poi `sort_medium.c`
9. Poi `sort_complex.c`
10. Infine `sort_adaptive.c` che collega tutto

Ogni passo ha qualcosa che funziona e che puoi testare. Non andare avanti finché il passo corrente non è solido.
*/


#endif