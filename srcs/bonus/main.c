/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 05:54:14 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/26 01:11:48 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	t_pile	pile_a;
	t_pile	pile_b;

	i = 1;
	if (argc < 2)
		return (1);
	pile_a.tab = malloc(sizeof(int) * 1);
	if (!pile_a.tab)
		return (ft_error(1), 1);
	pile_a.size = 0;
	if (parsing(--argc, ++argv, &pile_a))
		return (free(pile_a.tab), 1);
	pile_b.tab = malloc(sizeof(int) * pile_a.size);
	if (!pile_b.tab)
		return (ft_error(1), free(pile_a.tab), 1);
	ft_bzero(pile_b.tab, sizeof(int) * pile_a.size);
	pile_b.size = 0;
	checker(&pile_a, &pile_b);
	free(pile_a.tab);
	free(pile_b.tab);
	return (0);
}
