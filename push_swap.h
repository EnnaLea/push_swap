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




#endif