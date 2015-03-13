/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:57:14 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:25:54 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

gint		pbar_timeout(void)
{
	GtkWidget	*pbar;
	gdouble		state;

	pbar = GTK_WIDGET(gtk_builder_get_object(get_env(NULL)->gtkbuilder,
				"progressbar1"));
	state = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(pbar));
	if (state < 1)
	{
		if (RUNNING_STATE == RUNNING)
		{
			state = state + 0.05;
			gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar),
					(gdouble)state);
		}
		else if (RUNNING_STATE == STOPPED)
			return (0);
		return (1);
	}
	return (0);
}

gint		step_timeout(void)
{
	if (!check_death(get_env(NULL)->philosophers))
	{
		if (RUNNING_STATE == RUNNING)
		{
			display_console(t_env *e);
			draw();
			set_sec(get_env(NULL));
		}
		else if (RUNNING_STATE == STOPPED)
		{
			return (0);
		}
		return (1);
	}
	draw();
	ft_putstr("He's dead, Jim. (Philosophe n: ");
	ft_putnbr(check_death(get_env(NULL)->philosophers));
	ft_putendl(")");
	exit_simulation(get_env(NULL));
	RUNNING_STATE = STOPPED;
	return (0);
}
