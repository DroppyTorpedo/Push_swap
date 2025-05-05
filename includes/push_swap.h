/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:03:06 by rnorvene          #+#    #+#             */
/*   Updated: 2025/05/02 15:03:10 by rnorvene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h" // Vérifiez que ce chemin est correct
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// Parsing
long				ft_atol(const char *str);
int					validate_and_push(t_stack **a, char *token);
int					process_arg(t_stack **a, char *arg);
t_stack				*parse_args(int argc, char **argv);
int					ft_isdigit_str(const char *str);
int					is_valid_number(const char *str);
int					has_duplicate(t_stack *a);
void				free_split(char **arr);

// Instructions
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// Tri
int					get_chunk_size(int size);
void				push_chunk_to_b(t_stack **a, t_stack **b, int chunk_start,
						int chunk_end);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				push_back_to_a(t_stack **a, t_stack **b);
int					partition(int *array, int low, int high);
void				quick_sort(int *array, int low, int high);
void				assign_indexes(t_stack *stack);
int					binary_search(int *arr, int size, int value);
void				sort_stack_b(t_stack **a, t_stack **b);
void				turk_sort(t_stack **a, t_stack **b);

// Utilitaires
int					stack_size(t_stack *stack);
void				stack_add_back(t_stack **stack, t_stack *new);
t_stack				*stack_new(int value);
void				free_stack(t_stack **stack);
int					is_sorted(t_stack *stack);
void				print_stack(t_stack *stack);
int					stack_contains(t_stack *stack, int value);
void				quick_sort_median(int *array, int low, int high);
int					*get_sorted_indexes(t_stack *stack, int size);
int					get_max_index(t_stack *stack);
void				move_top_to_b(t_stack **b, int index);
int					find_pos(t_stack *stack, int index);
void				ft_sort_int_tab(int *tab, int size);
int					error_and_free(t_stack **a, t_stack **b, int exit_code);
int					get_max_position(t_stack *stack);
int					get_min_position(t_stack *stack);
int					get_index_position(t_stack *stack, int index);
int					stack_has_chunk(t_stack *a, int chunk_start, int chunk_end);
int					find_closest_direction(t_stack *a, int chunk_start,
						int chunk_end);

#endif