#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					value;
	int					index;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

int		is_valid_number(char *str);
int		has_duplicates(char **args);
void	check_args(char *argv[]);

void	ft_error(char* msg);
long	ft_atol(const char *str);

t_stack	*new_stack_node(int value);
void	stack_node_add_back(t_stack **stack, t_stack *new_node);
void	init_stack_a(t_stack **a, char **args);
void	assign_index(t_stack *a);
int     stack_size(t_stack *stack);

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int     is_sorted(t_stack *stack);
void    sort_2(t_stack **a);
void    sort_3(t_stack **a);
void	sort_4_5(t_stack **a, t_stack **b);

void	radix_sort(t_stack **a, t_stack **b);

#endif