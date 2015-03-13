/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 21:20:54 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:22:44 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		exit_simulation(t_env *env)
{
	int		i;

	i = 0;
	while (i < N_PHILO)
	{
		pthread_cancel(env->thread_addr[i]);
		i++;
	}
	i = 0;
	while (i < N_PHILO)
	{
		pthread_mutex_destroy(env->philosophers[i].left);
		i++;
	}
}
