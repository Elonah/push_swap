/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:13:16 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/29 05:11:50 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct t_pile
{
	int				*tab;
	int				size;
}					t_pile;

//get_next_line_utils.c
size_t			ft_strlen(char *s);
char			*ft_strchr(char *s, char c);
char			*ft_strcat(char *dest, char *src);
size_t			calcul_taille_grande_chaine(char *big_str, char *buffer);
char			*ft_strjoin(char *big_str, char *buffer);

//get_next_line.c
char			*debut_nouvelle_ligne(char *big_str);
char			*extirpation_ligne(char *big_str);
char			*lecture_du_fd(int fd, char *big_str);
char			*get_next_line(int fd);

//parsing.c
void			ft_error(int valeur);
int				check_digit(char *str);
int				*ft_tab_of_int_realloc(int *tab, int actual_size_of_tab);
int				check_double(t_pile *pile_a);
int				parsing(int argc, char **argv, t_pile *pile_a);

//parsing2.c
void			free_atoll(char **tab1, int *tab2);
long long int	ft_atoll(const char *str, char	**tab, t_pile *pile_a);

//movement_swap.c
void			ft_swap(t_pile *pile);
void			ft_sa(t_pile *pile_a);
void			ft_sb(t_pile *pile_b);
void			ft_ss(t_pile *pile_a, t_pile *pile_b);

//movement_rotate.c
void			ft_rotate(t_pile *pile);
void			ft_ra(t_pile *pile_a);
void			ft_rb(t_pile *pile_b);
void			ft_rr(t_pile *pile_a, t_pile *pile_b);

//movement_reverse_rotate.c
void			ft_reverse_rotate(t_pile *pile);
void			ft_rra(t_pile *pile_a);
void			ft_rrb(t_pile *pile_b);
void			ft_rrr(t_pile *pile_a, t_pile *pile_b);

//movement_push.c
void			ft_push(t_pile *pile_agrandie, t_pile *pile_retrecie);
void			ft_pa(t_pile *pile_a, t_pile *pile_b);
void			ft_pb(t_pile *pile_a, t_pile *pile_b);

//checker.c
int				ft_strcmp(char *s1, char *s2);
void			do_movement(t_pile *pile_a, t_pile *pile_b, char *movement);
void			bad_instruction(t_pile *pile_a, t_pile *pile_b, char *movement);
int				checksort(t_pile *pile_a);
void			checker(t_pile *pile_a, t_pile *pile_b);

//main.c
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
int				main(int argc, char **argv);

//fonctions_libft

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
void			ft_freetab(char **tab);

//split.c
static int		ft_strlen2(char const *src, char c);
static int		nb_mots(char const *s, char c);
static char		*ft_strdup2(char const *src, char c);
void			ft_free_split(char **tab, int j);
char			**ft_split(char const *s, char c);

#endif
