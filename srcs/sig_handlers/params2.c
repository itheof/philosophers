/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:52:20 by tvallee           #+#    #+#             */
/*   Updated: 2015/04/03 10:48:30 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ss(GtkSpinButton *spin_button, gpointer user_data)
{
	if (M_RUNNING_STATE)
		gtk_spin_button_set_value(spin_button, (gdouble)M_STEP_TIME);
	else
	{
		M_STEP_TIME = gtk_spin_button_get_value(spin_button);
		user_data = user_data;
	}
}

gboolean	switch_verbose(GtkSwitch *widget, gboolean state, gpointer thg)
{
	get_env(NULL)->options[DEBUG] = state;
	gtk_switch_set_state(widget, state);
	widget = widget;
	thg = thg;
	return (state);
}
