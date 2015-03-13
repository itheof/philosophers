/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:50:14 by rcargou           #+#    #+#             */
/*   Updated: 2015/03/13 20:47:51 by tvallee          ###   ########.fr       */
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
		else if ((*str) == '-');
		else
		{
			ft_putstr("Unknown option: ");
			ft_putchar(*str);
			ft_putchar('\n');
		}
		str++;
	}
}

void			free_split(char **s)
{
	int i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void			get_options(int ac, char **av, char opt[])
{
	int		i;
	char	**split;

	i = 0;
	while (i < ac - 1)
	{
		split = ft_strsplit(av[1 + i], ' ');
		while (*split)
		{
			if (**split != '-')
				break ;
			cross_opt(*split, opt);
			split++;
		}
		i++;
	}
}
