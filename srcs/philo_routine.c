/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 17:12:20 by rcargou           #+#    #+#             */
/*   Updated: 2015/03/16 01:35:46 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			think(t_philo *philo, int n)
{
	int t;

	t = philo->env->think_t;
	philo->state = THINK;
	if (n == 2)
		pthread_mutex_unlock((philo->left));
	else
		pthread_mutex_unlock((philo->right));
	while (t && philo->quit != 1)
	{
		if (philo->sec)
		{
			philo->sec = 0;
			philo->hp--;
			philo->dead = (philo->hp <= 0);
			t--;
		}
	}
}

static void			rest(t_philo *philo)
{
	int t;

	t = philo->env->rest_t;
	philo->state = REST;
	while (t && philo->quit != 1)
	{
		if (philo->sec)
		{
			t--;
			philo->hp--;
			philo->dead = (philo->hp <= 0);
			philo->sec = 0;
		}
	}
}

static void			eat(t_philo *philo)
{
	int t;

	t = philo->env->eat_t;
	philo->state = EAT;
	while (t && philo->quit != 1)
	{
		if (philo->sec)
		{
			t--;
			philo->sec = 0;
		}
	}
	philo->hp = philo->env->max_life;
	pthread_mutex_unlock((philo->right));
	pthread_mutex_unlock((philo->left));
	rest(philo);
}

static int			lock_bag(int *n, t_philo *philo)
{
	int n_baguettes;

	n_baguettes = 0;
	if ((pthread_mutex_trylock((philo->right))) == 0)
	{
		n_baguettes++;
		*n = 1;
	}
	if ((pthread_mutex_trylock((philo->left))) == 0)
	{
		n_baguettes++;
		*n = 2;
	}
	return (n_baguettes);
}

void				*philo_routine(void *data)
{
	int			n_baguettes;
	t_philo		*philo;
	int			n;

	philo = (t_philo*)data;
	while (42)
	{
		if (philo->quit == 1)
			return (NULL);
		n_baguettes = lock_bag(&n, philo);
		if (n_baguettes == 2)
			eat(philo);
		else if (n_baguettes == 1)
			think(philo, n);
		else
			philo->state = WAIT;
		if (philo->sec && philo->state == WAIT)
		{
			philo->hp--;
			philo->dead = (philo->hp <= 0);
			philo->sec = 0;
		}
	}
	return (NULL);
}
