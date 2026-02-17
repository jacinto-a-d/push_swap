/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:43:33 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 19:22:09 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				pos;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*push_swap_init_bonus(char **argv);
t_stack	*create_nodo_bonus(int value);

void	process_validation_create_bonus(t_stack **stack, char **tmp);
void	free_stack_bonus(t_stack **stack);
void	rra_check(t_stack **a, int print);
void	rrb_check(t_stack **b, int print);
void	rrr_check(t_stack **a, t_stack **b, int print);
void	ra_check(t_stack **a, int print);
void	rb_check(t_stack **b, int print);
void	rr_check(t_stack **a, t_stack **b, int print);
void	pa_check(t_stack **a, t_stack **b, int print);
void	pb_check(t_stack **b, t_stack **a, int print);
void	sa_check(t_stack **a, int print);
void	sb_check(t_stack **b, int print);
void	ss_check(t_stack **a, t_stack **b, int print);
void	apply_basic_bonus(t_stack **a, t_stack **b, char *op);
void	error_and_clean_bonus(char **tmp, t_stack **stack, int n);
void	add_nodo_end_bonus(t_stack **stack, t_stack *new_nodo);
void	index_list_bonus(t_stack **a);

char	*get_next_line(int fd);
char	*ft_extract_line(char *stash);
char	*ft_stash_clean(char *stash);
char	*ft_strchr(const char *str, int c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_read_and_strchr(int fd, char *stash);
char	*ft_str_malloc_concat(char *s1, char *s2);
char	*ft_init_buffer(char *stash);
char	*ft_clean_exit(char *stash, char *tmp);
char	**ft_split_bonus(char const *s, char c);

size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);

int		check_int_bonus(long num);
int		check_number_bonus(char *str);
int		ft_strcmp_bonus(char *s1, char *s2);
int		atoi_long_bonus(const char *str);
int		is_sorted_bonus(t_stack *stack);
int		check_duplicate_bonus(t_stack **stack_a, int num);
int		list_size_circular_bonus(t_stack *stack);

#endif