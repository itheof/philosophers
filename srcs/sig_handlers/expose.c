/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 17:41:30 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:03:19 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
	data = data;
	get_env(NULL)->widget = widget;
	get_env(NULL)->cr = cr;
	draw(widget, cr);
	return (0);
}
