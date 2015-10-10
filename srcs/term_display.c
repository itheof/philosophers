/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 19:17:44 by rcargou           #+#    #+#             */
/*   Updated: 2015/03/15 21:05:29 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void				set_sec(t_env *env)
{
	int i;

	i = 0;
	while (i < N_PHILO)
	{
		env->philosophers[i].sec = 1;
		i++;
	}
}

static char			*state_to_str(int state)
{
	if (state == EAT)
		return ("  eat");
	else if (state == REST)
		return (" rest");
	else if (state == THINK)
		return ("think");
	else
		return (" wait");
}

void				display_console(t_env *env)
{
	int i;
	int e;

	e = 0;
	i = -1;
	while (++i < N_PHILO)
	{
		ft_putstr("Philo N");
		align_nbr(i + 1, N_PHILO);
		ft_putnbr(1 + i);
		ft_putstr(": ");
		ft_putstr(state_to_str(env->philosophers[i].state));
		ft_putstr(" Hp: ");
		align_nbr(100 * env->philosophers[i].hp / env->max_life, 100);
		ft_putnbr(100 * env->philosophers[i].hp / env->max_life);
		ft_putstr("%");
		if (++e > 3 && i != N_PHILO - 1)
		{
			e = 0;
			ft_putchar('\n');
		}
		else if (i != N_PHILO - 1)
			ft_putstr(" ||==|| ");
	}
	ft_putendl("\n");
}
