/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:10:44 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/29 05:11:13 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
	}
	return ((*s1 > *s2) * 2 -1);
}

void	bad_instruction(t_pile *pile_a, t_pile *pile_b, char *movement)
{
	free(movement);
	ft_error(5);
	free(pile_a->tab);
	free(pile_b->tab);
	exit(1);
}

void	do_movement(t_pile *pile_a, t_pile *pile_b, char *movement)
{
	if (ft_strcmp(movement, "sa\n") == 0)
		ft_sa(pile_a);
	else if (ft_strcmp(movement, "sb\n") == 0)
		ft_sb(pile_b);
	else if (ft_strcmp(movement, "ss\n") == 0)
		ft_ss(pile_a, pile_b);
	else if (ft_strcmp(movement, "ra\n") == 0)
		ft_ra(pile_a);
	else if (ft_strcmp(movement, "rb\n") == 0)
		ft_rb(pile_b);
	else if (ft_strcmp(movement, "rr\n") == 0)
		ft_rr(pile_a, pile_b);
	else if (ft_strcmp(movement, "rra\n") == 0)
		ft_rra(pile_a);
	else if (ft_strcmp(movement, "rrb\n") == 0)
		ft_rrb(pile_b);
	else if (ft_strcmp(movement, "rrr\n") == 0)
		ft_rrr(pile_a, pile_b);
	else if (ft_strcmp(movement, "pa\n") == 0)
		ft_pa(pile_a, pile_b);
	else if (ft_strcmp(movement, "pb\n") == 0)
		ft_pb(pile_a, pile_b);
	else
		bad_instruction(pile_a, pile_b, movement);
}

int	checksort(t_pile *pile_a)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < pile_a->size)
	{
		if (pile_a->tab[i] > pile_a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	checker(t_pile *pile_a, t_pile *pile_b)
{
	char	*movement;

	while (1)
	{
		movement = get_next_line(0);
		if (!movement)
			break ;
		do_movement(pile_a, pile_b, movement);
		free (movement);
	}
	if (checksort(pile_a) && pile_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
