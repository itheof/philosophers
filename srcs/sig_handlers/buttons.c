/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 00:19:11 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:29:16 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	play(GtkButton *widget, gpointer user_data)
{
	GtkWidget	*pbar;
	GObject		*window;

	if (RUNNING_STATE == STOPPED)
	{
		window = gtk_builder_get_object()
		pbar = GTK_WIDGET(gtk_builder_get_object(get_env(NULL)->gtkbuilder,
					"progressbar1"));
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar), (gdouble)0);
		init_baguettes(get_env(NULL)->baguettes);
		init_philo(get_env(NULL));
		init_thread(get_env(NULL));
		g_timeout_add_sec(0.1, (GSourceFunc)pbar_timeout, window);
		g_timeout_add_sec(1, (GSourceFunc)step_timeout, window);
		set_sec(get_env(NULL));
	}
	else if (RUNNING_STATE = PAUSED)
		RUNNING_STATE = RUNNING;
}

void	p_pause(GtkButton *widget, gpointer user_data)
{
	RUNNING_STATE = (RUNNING) ? PAUSED : RUNNING_STATE;
	widget = widget;
	user_data = user_data;
}

void	stop(GtkButton *widget, gpointer user_data)
{
	if (RUNNING_STATE == RUNNING)
	{
		draw();
		ft_putendl("Simulation cancelled");
		exit_simulation(get_env(NULL));
	}
	else if (RUNNING_STATE == PAUSED)
	{
		ft_putendl("Simulation cancelled");
		exit_simulation(get_env(NULL));
	}
	RUNNING_STATE = STOPPED;
}
