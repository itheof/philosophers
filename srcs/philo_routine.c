/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 17:12:20 by rcargou           #+#    #+#             */
/*   Updated: 2015/03/13 21:23:53 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			think(t_philo *philo)
{
	int t;

	t = philo->env->think_t;
	philo->state = THINK;
	pthread_mutex_unlock((philo->left));
	pthread_mutex_unlock((philo->right));
	while (t)
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
	while (t)
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
	philo->hp = philo->env->max_life;
	philo->state = EAT;
	while (t)
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

void			*philo_routine(void *data)
{
	int			n_baguettes;
	t_philo		*philo;
	int			result;

	philo = (t_philo*)data;
	while (42)
	{
		n_baguettes = 0;
		if ((result = pthread_mutex_trylock((philo->right))) == 0)
			n_baguettes++;
		if ((result = pthread_mutex_trylock((philo->left))) == 0)
			n_baguettes++;
		if (n_baguettes == 2)
			eat(philo);
		else if (n_baguettes == 1)
			think(philo);
		else
			philo->state = WAIT;
		if (philo->sec && philo->state == WAIT)
		{
			philo->hp--;
			philo->dead = (philo->hp <= 0);
			philo->sec = 0;
		}
		usleep(10000);
	}
	return (NULL);
}
