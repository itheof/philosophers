/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:59:25 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:07:52 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_env(t_env *e)
{
	e->max_life = 20;
	e->eat_t = 6;
	e->rest_t = 6;
	e->think_t = 6;
	e->step_time = 1;
}

int main (int ac, char **av)
{
	t_env	e;

	gtk_init(&ac, &av);
	init_env(&e);
	get_options(ac, av, e.options);
	if (e.options[TIME])
		e.step_time = e.options[TIME];
	if (e.options[DEBUG])
		ft_putstr("Initializing GUI...");
	e.gtkbuilder = init_gtk_env(*av);
	if (e.options[DEBUG])
		ft_putendl(" Done !");
	get_env(&e);

	e.running_state = STOPPED;
	gtk_main();
	if (e.options[DEBUG])
		ft_putendl("Tchibidibye !");
	return 0;
}
