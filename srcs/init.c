/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:44:14 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 20:19:52 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			connect_top_bar_signals(GtkBuilder *builder)
{
	GtkWidget	*button;

	button = GTK_WIDGET(gtk_builder_get_object(builder, "play"));
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(play), NULL);
	button = GTK_WIDGET(gtk_builder_get_object(builder, "pause"));
	g_signal_connect(G_OBJECT(butten), "clicked", G_CALLBACK(p_pause), NULL);
	button = GTK_WIDGET(gtk_builder_get_object(builder, "stop"));
	g_signal_connect(G_OBJECT(butten), "clicked", G_CALLBACK(stop), NULL);
	return ;
}

void			connect_params_spinbut(GtkBuilder *builder)
{
	GtkWidget	*spinbut;
	GtkWidget	*test;

	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_maxhp"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(max_hp),
			NULL);
	test = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_eat_t"));
	g_signal_connect(G_OBJECT(test), "value-changed", G_CALLBACK(eat_t), NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_rest_t"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(rest_t),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_think_t"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(think_t),
			NULL);
	spinbut = GTK_WIDGET(gtk_builder_get_object(builder, "spinbut_timeout"));
	g_signal_connect(G_OBJECT(spinbut), "value-changed", G_CALLBACK(timeout),
			NULL);
	return ;
}

GtkBuilder		*init_gtk_env(char *command)
{
	GtkBuilder	*builder;
	GtkWidget	*drawing_area;
	GObject		*window;
	char		*path;

	builder = gtk_builder_new();
	path = ft_find_builder(command);
	gtk_builder_add_from_file(builder, path, NULL);
	free(path);
	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	drawing_area = GTK_WIDGET(gtk_builder_get_object(builder, "drawingarea1"));
	g_signal_connect(G_OBJECT(drawing_area), "draw",
			G_CALLBACK(draw_callback), NULL);
	connect_top_bar_signals(builder);
	connect_params_spinbut(builder);
	return (builder);
}
