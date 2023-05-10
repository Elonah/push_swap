/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:24:48 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 04:33:39 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_printab(t_pile *pile_a, t_pile *pile_b)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (i < pile_a->size - pile_b->size)
//	{
//		ft_printf("\033[0;31m%i\033[0m\t\033[0;32m%i\033
//[0m\t\t\t\n", i, pile_a->tab[i]);
//		i++;
//	}
//	while (j < pile_b->size - pile_a->size)
//	{
//		ft_printf("\t\t\033[0m\033[0;34m%i\t\033[0;31m%i\033[0m\t\n",
//				pile_b->tab[j], j);
//		j++;
//	}
//	while (i < pile_a->size && j < pile_b->size)
//	{
//		ft_printf("\033[0;31m%i\033[0m\t\033[0;32m%i\033
//[0m\t\033[0;34m%i\033[0m\t\033[0;31m%i\033[0m\t\n",
//				i, pile_a->tab[i],
//			pile_b->tab[j], j);
//		i++;
//		j++;
//	}
//	ft_printf("%i\tPILE A\tPILE B\t%i\n", pile_a->size, pile_b->size);
//}

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
	if (checksort(&pile_a))
		return (free(pile_a.tab), 0);
	pile_b.tab = malloc(sizeof(int) * pile_a.size);
	if (!pile_b.tab)
		return (ft_error(1), free(pile_a.tab), 1);
	ft_bzero(pile_b.tab, sizeof(int) * pile_a.size);
	pile_b.size = 0;
	ft_algo(&pile_a, &pile_b);
	free(pile_a.tab);
	free(pile_b.tab);
	return (0);
}
