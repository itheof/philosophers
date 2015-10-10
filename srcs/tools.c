/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:30:30 by rcargou           #+#    #+#             */
/*   Updated: 2015/04/03 10:45:28 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	nbr_len(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			align_nbr(int n1, int n2)
{
	int i;

	i = nbr_len(n2) - nbr_len(n1);
	if (i < 0)
		ft_putchar(' ');
	else
	{
		while (i--)
			ft_putchar(' ');
	}
	return (0);
}

t_env		*get_env(t_env *env)
{
	static t_env *e = NULL;

	if (env != NULL)
		e = env;
	else
		return (e);
	return (NULL);
}

int			mirror(int i)
{
	if (i == 4)
		return (6);
	else if (i == 6)
		return (4);
	else
		return (i);
}

int			check_death(t_philo *philo)
{
	int i;

	i = 0;
	while (i < N_PHILO)
	{
		if (philo[i].dead)
			return (i + 1);
		i++;
	}
	return (0);
}
