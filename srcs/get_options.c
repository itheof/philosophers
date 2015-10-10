/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:50:14 by rcargou           #+#    #+#             */
/*   Updated: 2015/03/15 21:01:00 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		cross_opt(char *str, char opt[])
{
	while (*str && *str != ' ' && *str != '\t')
	{
		if ((*str) == 'v')
			opt[DEBUG] = 1;
		else if (ft_isdigit(*str))
			opt[TIME] = *str - '0';
		else if ((*str) == '-')
			;
		else
		{
			ft_putstr("Unknown option: ");
			ft_putchar(*str);
			ft_putchar('\n');
		}
		str++;
	}
}

void			get_options(int ac, char **av, char opt[])
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	bzero(opt, 2 * sizeof(char));
	while (i < ac - 1)
	{
		j = 0;
		split = ft_strsplit(av[1 + i], ' ');
		while (split[j])
		{
			if (split[j][0] != '-')
				break ;
			cross_opt(split[j], opt);
			j++;
		}
		ft_freetab((void **)split);
		i++;
	}
}
