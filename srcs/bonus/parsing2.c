/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:39:38 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 04:39:52 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_atoll(char **tab1, int *tab2)
{
	ft_error(3);
	ft_freetab(tab1);
	free(tab2);
	exit(1);
}

long long int	ft_atoll(const char *str, char	**tab, t_pile *pile_a)
{
	int				i;
	long long int	n;
	int				signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n *= signe;
	if (n > INT_MAX || n < INT_MIN)
		free_atoll(tab, pile_a->tab);
	return (n);
}
