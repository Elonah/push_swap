/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:29:24 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 04:31:50 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct t_pile
{
	int				*tab;
	int				size;
}					t_pile;

typedef struct t_all
{
	t_pile			*pile_a;
	t_pile			*pile_b;
}					t_all;

typedef struct t_rotations_needed
{
	int				price_b;
	int				price_a;
	int				total_of_rotations;
}					t_rotations_needed;

// parsing.c
void				ft_error(int valeur);
int					check_digit(char *str);
int					*ft_tab_of_int_realloc(int *tab, int actual_size_of_tab);
int					check_double(t_pile *pile_a);
int					parsing(int argc, char **argv, t_pile *pile_a);

// parsing2.c
long long int		ft_atoll(const char *str, char **tab, t_pile *pile_a);
void				free_atoll(char **tab1, int *tab2);

// movement_swap.c
void				ft_swap(t_pile *pile);
void				ft_sa(t_pile *pile_a);
void				ft_sb(t_pile *pile_b);
void				ft_ss(t_pile *pile_a, t_pile *pile_b);

// movement_rotate.c
void				ft_rotate(t_pile *pile);
void				ft_ra(t_pile *pile_a);
void				ft_rb(t_pile *pile_b);
void				ft_rr(t_pile *pile_a, t_pile *pile_b);

// movement_reverse_rotate.c
void				ft_reverse_rotate(t_pile *pile);
void				ft_rra(t_pile *pile_a);
void				ft_rrb(t_pile *pile_b);
void				ft_rrr(t_pile *pile_a, t_pile *pile_b);

// movement_push.c
void				ft_push(t_pile *pile_a, t_pile *pile_b);
void				ft_pa(t_pile *pile_a, t_pile *pile_b);
void				ft_pb(t_pile *pile_a, t_pile *pile_b);

//void				ft_rotatedown(t_pile *pile);
//int				pushswap_push(t_pile *dest, t_pile *src, char c, int *tab);

// algo.c
void				algo_five(t_pile *pile_a, t_pile *pile_b);
void				algo_three(t_pile *pile_a);
void				algo_two(t_pile *pile_a);
int					ft_algo(t_pile *pile_a, t_pile *pile_b);

// utils.c
int					find_index_of_min(t_pile *pile);
int					find_index_of_max(t_pile *pile);
void				best_rotation_to_put_min_on(t_pile *pile);
int					find_sup(t_pile *pile_a, t_pile *pile_b,
						int index_of_nb_in_b);
int					valeur_absolue(int x);

// median.c
int					*copie_tableau(t_pile *pile);
void				swap_int(int *a, int *b);
void				ft_sort_int_tab(int *tab, int size);
int					find_median(t_pile *pile);

//big_algo.c
void				push_all_in_b_and_pre_sort(t_pile *pile_a, t_pile *pile_b);
t_rotations_needed	best_price(t_pile *pile_a, t_pile *pile_b);
void				do_rotations2(t_pile *pile_a, t_pile *pile_b,
						t_rotations_needed best);
void				do_rotations(t_pile *pile_a, t_pile *pile_b,
						t_rotations_needed best);
void				algo_all(t_pile *pile_a, t_pile *pile_b);

//big_algo2.c
int					nb_rotation(t_pile *pile, int index_of_the_nb);
int					total_rotation(int price_a, int price_b);

// main.c
int					checksort(t_pile *pile_a);
int					main(int argc, char **argv);

//void				ft_printab(t_pile *pile_a, t_pile *pile_b);

#endif
