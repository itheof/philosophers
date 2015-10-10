/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:59:25 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/15 21:01:41 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		init_philo_before_expose(t_env *env)
{
	int i;

	i = 0;
	while (i < N_PHILO)
	{
		env->philosophers[i].dead = 0;
		env->philosophers[i].state = WAIT;
		env->philosophers[i].hp = MAX_LIFE;
		i++;
	}
	env->danse = 0;
}

void			init_env(t_env *e, int fcall)
{
	GtkWidget	*sbutton;

	e->max_life = MAX_LIFE;
	e->eat_t = EAT_T;
	e->rest_t = REST_T;
	e->think_t = THINK_T;
	e->timeout = TIMEOUT;
	if (fcall)
		e->step_time = 1;
	sbutton = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spinbut_maxhp"));
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), MAX_LIFE);
	sbutton = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spinbut_eat_t"));
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), EAT_T);
	sbutton = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spinbut_rest_t"));
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), REST_T);
	sbutton = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spinbut_think_t"));
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), THINK_T);
	sbutton = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spinbut_timeout"));
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), TIMEOUT);
	if (fcall)
	{
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), TIMEOUT);
		sbutton = GTK_WIDGET(gtk_builder_get_object(BUILDER, "spinbut_ss"));
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(sbutton), 1);
	}
}

void			gtk_exit_properly(void)
{
	if (M_RUNNING_STATE)
		exit_simulation(get_env(NULL));
	ft_putendl_v("Tchibidibye !");
	gtk_main_quit();
	exit(0);
}

int				main(int ac, char **av)
{
	t_env		e;
	GtkSwitch	*switch_b;

	init_philo_before_expose(&e);
	gtk_init(&ac, &av);
	get_options(ac, av, e.options);
	e.command = av[0];
	if (e.options[TIME])
		e.step_time = e.options[TIME];
	if (e.options[DEBUG])
		ft_putstr("Initializing GUI...");
	e.gtkbuilder = init_gtk_env(*av);
	get_env(&e);
	switch_b = GTK_SWITCH(gtk_builder_get_object((BUILDER), "switch_verbose"));
	gtk_switch_set_active(switch_b, e.options[DEBUG]);
	init_env(get_env(NULL), 1);
	ft_putendl_v(" Done !");
	M_RUNNING_STATE = STOPPED;
	gtk_main();
	return (0);
}
