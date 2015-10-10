/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 20:07:33 by tvallee           #+#    #+#             */
/*   Updated: 2015/04/03 13:52:45 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static cairo_surface_t		*state_to_img(int state, int side, int death)
{
	if (get_env(NULL)->danse)
		return (get_env(NULL)->image[7]);
	if (death)
		return (((get_env(NULL)->image)[6]));
	if (state == THINK)
		return ((get_env(NULL)->image[3]));
	if (state == WAIT)
		return ((get_env(NULL)->image[4]));
	if (state == REST)
		return ((get_env(NULL)->image[2]));
	if (state == EAT)
	{
		if (side == 0)
			return ((get_env(NULL)->image[5]));
		else
			return ((get_env(NULL)->image[1]));
	}
	return (get_env(NULL)->image[4]);
}

static void					load_png(cairo_surface_t **image)
{
	image[0] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Table.png"));
	image[1] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Eating_r.png"));
	image[2] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Sleeping.png"));
	image[3] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Thinking.png"));
	image[4] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Waiting.png"));
	image[5] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Eating_l.png"));
	image[6] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Death.png"));
	image[7] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/Dancing.png"));
	image[8] = cairo_image_surface_create_from_png(ft_find_file(get_env(NULL)->
				command, "gui/End_table.png"));
}

static void					print_life(double x, double y, int i)
{
	char *text;

	if (get_env(NULL)->danse)
		return ;
	text = ft_itoa(get_env(NULL)->philosophers[i].hp);
	text = ft_strjoin(text, " <3", 1);
	cairo_set_source_rgb(get_env(NULL)->cr, 255, 0, 0);
	cairo_select_font_face(get_env(NULL)->cr, "Purisa",
			CAIRO_FONT_SLANT_NORMAL,
			CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(get_env(NULL)->cr, 13);
	cairo_move_to(get_env(NULL)->cr, x, y);
	cairo_show_text(get_env(NULL)->cr, text);
	free(text);
}

static void					print_scene(guint widht, guint height)
{
	int i;
	int x;
	int y;

	i = -1;
	x = 0;
	y = 0;
	cairo_set_source_surface(get_env(NULL)->cr,
	get_env(NULL)->image[0 + 8 * get_env(NULL)->danse],
	(widht / 2 - 1500 / 2) * (get_env(NULL)->danse == 0),
	(height / 2 - 500 / 2) * (get_env(NULL)->danse == 0));
	cairo_paint(get_env(NULL)->cr);
	while (++i < N_PHILO && i < 9)
	{
		print_life(((!y) ? 255 : 400) + 250 * x,
			height / 2 - ((y) ? -50 : 240), mirror(i));
		cairo_set_source_surface(get_env(NULL)->cr,
		state_to_img(get_env(NULL)->philosophers[mirror(i)].state, x >= 2,
		get_env(NULL)->philosophers[mirror(i)].dead), ((!y) ? 255 : 400) + 250 *
		x, height / 2 - ((y) ? -50 : 240));
		y += ((x + 2) > 4);
		x = (x + 1) % 4;
		cairo_paint(get_env(NULL)->cr);
	}
}

void						draw(void)
{
	guint		width;
	guint		height;
	GdkRGBA		color;

	load_png(get_env(NULL)->image);
	width = gtk_widget_get_allocated_width (get_env(NULL)->widget);
	height = gtk_widget_get_allocated_height (get_env(NULL)->widget);
	gtk_style_context_get_color(gtk_widget_get_style_context
		(get_env(NULL)->widget), 0, &color);
	gdk_cairo_set_source_rgba (get_env(NULL)->cr, &color);
	print_scene(width, height);
}
