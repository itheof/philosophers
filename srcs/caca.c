/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:30:30 by rcargou           #+#    #+#             */
/*   Updated: 2015/03/12 17:42:03 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_env		*get_env(t_env *env)
{
	static t_env *e = NULL;

	if (env != NULL)
		e = env;
	else
		return (e);
}

void		exit_simulation(t_env *env)
{
	int i;

	i = 0;
	while (i < N_PHILO)
	{
		pthread_cancel(env->thread_addr[i]);
		i++;
	}
	i = 0;
	while (i < N_PHILO)
	{
		pthread_mutex_destroy(&(env->philosophers[i].left));
		i++;
	}
}

int			check_death(t_philo *philo)
{
	int i;

	i = 0;
	while (i < N_PHILO)
	{
		if (philo[i].dead)
			return (1);
		i++;
	}
	return (0);
}
