/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:57:14 by tvallee           #+#    #+#             */
/*   Updated: 2015/04/03 10:51:11 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

gint			pbar_timeout(void)
{
	GtkWidget	*pbar;
	gdouble		state;

	pbar = GTK_WIDGET(gtk_builder_get_object(BUILDER,
				"progressbar1"));
	if (M_RUNNING_STATE == RUNNING)
	{
		state = (double)(get_env(NULL)->niter) / (double)M_TIMEOUT;
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar),
				(gdouble)state);
	}
	else if (M_RUNNING_STATE == STOPPED)
		return (0);
	return (1);
}

static gint		quit_step(void)
{
	ft_putstr_v("He's dead, Jim. (Philosophe n: ");
	if (get_env(NULL)->options[DEBUG])
		ft_putnbr(check_death(get_env(NULL)->philosophers));
	ft_putendl_v(")");
	M_RUNNING_STATE = STOPPED;
	exit_simulation(get_env(NULL));
	return (0);
}

gint			step_timeout(void)
{
	if (!check_death(get_env(NULL)->philosophers))
	{
		if (M_RUNNING_STATE == RUNNING)
		{
			if (get_env(NULL)->options[DEBUG])
				display_console(get_env(NULL));
			gtk_widget_queue_draw(get_env(NULL)->widget);
			if (get_env(NULL)->niter > M_TIMEOUT)
			{
				get_env(NULL)->danse = 1;
				ft_putendl_v("Now, it is time... To DAAAAAAAANCE!!!");
				M_RUNNING_STATE = STOPPED;
				exit_simulation(get_env(NULL));
				return (0);
			}
			get_env(NULL)->niter = get_env(NULL)->niter + 1;
			set_sec(get_env(NULL));
		}
		else if (M_RUNNING_STATE == STOPPED)
			return (0);
		return (1);
	}
	return (quit_step());
}
