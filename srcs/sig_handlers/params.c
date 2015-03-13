/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:06:10 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/12 21:43:49 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void max_hp(GtkSpinButton *spin_button, gpointer user_data)
{
	if (IS_RUNNING)
		gtk_spin_button_set_value(spin_button, (gdouble)MAX_LIFE);
	else
		MAX_LIFE = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
	printf("%d\n", gtk_spin_button_get_value_as_int(spin_button));
}

void eat_t(GtkSpinButton *spin_button, gpointer user_data)
{
	if (IS_RUNNING)
		gtk_spin_button_set_value(spin_button, (gdouble)EAT_T);
	else
		EAT_T = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
	printf("%d\n", gtk_spin_button_get_value_as_int(spin_button));
}

void rest_t(GtkSpinButton *spin_button, gpointer user_data)
{
	if (IS_RUNNING)
		gtk_spin_button_set_value(spin_button, (gdouble)REST_T);
	else
		REST_T = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
	printf("%d\n", gtk_spin_button_get_value_as_int(spin_button));
}

void think_t(GtkSpinButton *spin_button, gpointer user_data)
{
	if (IS_RUNNING)
		gtk_spin_button_set_value(spin_button, (gdouble)THINK_T);
	else
		THINK_T = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
	printf("%d\n", gtk_spin_button_get_value_as_int(spin_button));
}

void timeout(GtkSpinButton *spin_button, gpointer user_data)
{
	if (IS_RUNNING)
		gtk_spin_button_set_value(spin_button, (gdouble)TIMEOUT);
	else
		TIMEOUT = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
	printf("%d\n", gtk_spin_button_get_value_as_int(spin_button));
}
