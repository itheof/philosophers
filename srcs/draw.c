/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 20:07:33 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:04:04 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	draw(void)
{
	guint width, height;
	GdkRGBA color;

	width = gtk_widget_get_allocated_width (widget);
	height = gtk_widget_get_allocated_height (widget);
	cairo_arc (cr,
			width / 2.0, height / 2.0,
			MIN (width, height) / 2.0,
			0, 2 * G_PI);

	gtk_style_context_get_color (gtk_widget_get_style_context (widget),
			0,
			&color);
	gdk_cairo_set_source_rgba (cr, &color);
	cairo_fill (cr);
}
