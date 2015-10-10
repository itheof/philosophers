/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 00:19:11 by tvallee           #+#    #+#             */
/*   Updated: 2015/04/03 15:36:54 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static double	cheat(void)
{
	return (get_env(NULL)->step_time);
}

void			play(GtkButton *widget, gpointer user_data)
{
	GtkWidget	*pbar;
	GObject		*window;

	if (M_RUNNING_STATE == 0)
	{
		window = gtk_builder_get_object(BUILDER, "window");
		pbar = GTK_WIDGET(gtk_builder_get_object(get_env(NULL)->gtkbuilder,
					"progressbar1"));
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar), 0);
		init_baguettes(get_env(NULL)->baguettes);
		init_philo(get_env(NULL));
		init_thread(get_env(NULL));
		M_RUNNING_STATE = 1;
		ft_putendl_v("Starting simulation");
		get_env(NULL)->niter = 1;
		get_env(NULL)->danse = 0;
		gtk_widget_queue_draw(get_env(NULL)->widget);
		g_timeout_add(cheat() * 1000, (t_norm)pbar_timeout, window);
		g_timeout_add(cheat() * 1000, (t_norm)step_timeout, window);
	}
	else if (M_RUNNING_STATE == -1)
		M_RUNNING_STATE = 1;
	widget = widget;
	user_data = user_data;
}

void			p_pause(GtkButton *widget, gpointer user_data)
{
	if (M_RUNNING_STATE == RUNNING)
	{
		if (get_env(NULL)->options[DEBUG])
			display_console(get_env(NULL));
		ft_putendl_v("Simulation paused");
		M_RUNNING_STATE = PAUSED;
	}
	widget = widget;
	user_data = user_data;
}

void			stop(GtkButton *widget, gpointer user_data)
{
	if (M_RUNNING_STATE == RUNNING)
	{
		ft_putendl_v("Simulation cancelled");
		exit_simulation(get_env(NULL));
	}
	else if (M_RUNNING_STATE == PAUSED)
	{
		ft_putendl_v("Simulation cancelled");
		exit_simulation(get_env(NULL));
	}
	M_RUNNING_STATE = STOPPED;
	widget = widget;
	user_data = user_data;
}

void			reset(GtkButton *widget, gpointer user_data)
{
	init_env(get_env(NULL), 0);
	widget = widget;
	user_data = user_data;
}
