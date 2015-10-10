/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:44:14 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/14 20:44:15 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			connect_top_bar_signals(GtkBuilder *builder)
{
	GtkWidget	*button;

	button = GTK_WIDGET(gtk_builder_get_object(builder, "play"));
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(play), NULL);
	button = GTK_WIDGET(gtk_builder_get_object(builder, "pause"));
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(p_pause), NULL);
	button = GTK_WIDGET(gtk_builder_get_object(builder, "stop"));
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(stop), NULL);
	button = GTK_WIDGET(gtk_builder_get_object(builder, "reset"));
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(reset), NULL);
}

void			connect_params_spinbut(GtkBuilder *builder)
{
	GtkWidget	*spinbut;
	GtkWidget	*switch_b;

	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_maxhp"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(max_hp),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_eat_t"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(eat_t),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_rest_t"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(rest_t),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_think_t"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(think_t),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_timeout"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(timeout),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_ss"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(ss),
			NULL);
	switch_b = GTK_WIDGET(gtk_builder_get_object(builder, "switch_verbose"));
	g_signal_connect(G_OBJECT(switch_b), "state-set", G_CALLBACK(switch_verbose)
			, NULL);
	return ;
}

GtkBuilder		*init_gtk_env(char *command)
{
	GtkBuilder	*builder;
	GtkWidget	*drawing_area;
	GObject		*window;
	char		*path;

	builder = gtk_builder_new();
	path = ft_find_file(command, "gui/philosophers.ui");
	gtk_builder_add_from_file(builder, path, NULL);
	free(path);
	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_exit_properly), NULL);
	drawing_area = GTK_WIDGET(gtk_builder_get_object(builder, "drawingarea1"));
	gtk_widget_set_size_request(drawing_area, 1400, 600);
	g_signal_connect(G_OBJECT(drawing_area), "draw",
			G_CALLBACK(draw_callback), NULL);
	connect_top_bar_signals(builder);
	connect_params_spinbut(builder);
	return (builder);
}
