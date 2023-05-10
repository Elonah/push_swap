/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:47:52 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/29 06:25:13 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int valeur)
{
	if (valeur == 1)
		write(2, "Error\nMalloc a echoue\n", 23);
	if (valeur == 2)
		write(2, "Error\nCertains paramètres ne sont pas des nombres\n", 52);
	if (valeur == 3)
		write(2, "Error\nCertains paramètres ne tiennent pas dans un int\n", 56);
	if (valeur == 4)
		write(2, "Error\nIl y a des doublons\n", 27);
	if (valeur == 5)
		write(2, "Error\nLes nombres ne sont pas triés\n", 38);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	*ft_tab_of_int_realloc(int *tab, int actual_size_of_tab)
{
	int		*new;
	int		i;

	i = -1;
	new = malloc(sizeof(int) * (actual_size_of_tab + 1));
	if (!new)
		return (new);
	while (++i < actual_size_of_tab)
		new[i] = tab[i];
	free(tab);
	return (new);
}

int	check_double(t_pile *pile_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile_a->size)
	{
		j = i + 1;
		while (j < pile_a->size)
		{
			if (pile_a->tab[i] == pile_a->tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv, t_pile *pile_a)
{
	int		i[2];
	char	**tab;

	i[0] = -1;
	while (++(i[0]) < argc)
	{
		tab = ft_split(argv[i[0]], ' ');
		if (!tab || !tab[0])
			return (ft_freetab(tab), ft_error(!tab), 1);
		i[1] = -1;
		while (tab && tab[++i[1]])
		{
			if (check_digit(tab[i[1]]))
				return (ft_error(2), ft_freetab(tab), 1);
			pile_a->tab[pile_a->size++] = (int)ft_atoll(tab[i[1]], tab, pile_a);
			pile_a->tab = ft_tab_of_int_realloc(pile_a->tab, pile_a->size);
			if (!pile_a->tab)
				return (ft_error(1), ft_freetab(tab), 1);
		}
		ft_freetab(tab);
	}
	if (check_double(pile_a))
		return (ft_error(4), 1);
	return (0);
}

//int	parsing(int argc, char **argv, t_pile *pile_a)
//{
//	int		i;
//	int		j;
//	char	**tab;

//	i = -1;
//	while (++i < argc)
//	{
//		tab = ft_split(argv[i], ' ');
//		if (!tab)
//			return (ft_error(1), 1);
//		if (!tab[0])
//			return (ft_freetab(tab), 1);
//		j = -1;
//		while (tab && tab[++j])
//		{
//			if (check_digit(tab[j]))
//				return (ft_error(2), ft_freetab(tab), 1);
//			pile_a->tab[pile_a->size++] = (int)ft_atoll(tab[j], tab, pile_a);
//			pile_a->tab = ft_tab_of_int_realloc(pile_a->tab, pile_a->size);
//			if (!pile_a->tab)
//				return (ft_error(1), ft_freetab(tab), 1);
//		}
//		ft_freetab(tab);
//	}
//	if (check_double(pile_a))
//		return (ft_error(4), 1);
//	return (0);
//}
