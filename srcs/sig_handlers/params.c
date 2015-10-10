/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 21:06:10 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/14 17:53:08 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void max_hp(GtkSpinButton *spin_button, gpointer user_data)
{
	M_MAX_LIFE = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
}

void eat_t(GtkSpinButton *spin_button, gpointer user_data)
{
	M_EAT_T = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
}

void rest_t(GtkSpinButton *spin_button, gpointer user_data)
{
	M_REST_T = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
}

void think_t(GtkSpinButton *spin_button, gpointer user_data)
{
	M_THINK_T = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
}

void timeout(GtkSpinButton *spin_button, gpointer user_data)
{
	M_TIMEOUT = (int)gtk_spin_button_get_value_as_int(spin_button);
	user_data = user_data;
}
