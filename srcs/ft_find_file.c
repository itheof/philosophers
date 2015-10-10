/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:33:27 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/15 20:59:59 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char		*ft_lsttoasc(t_list *list)
{
	t_list	*current;
	int		i;
	char	*str;

	i = 0;
	current = list;
	while (current)
	{
		i += ft_strlen(current->content) + 1;
		current = current->next;
	}
	str = malloc(sizeof(*str) * (i + 1));
	*str = 0;
	current = list;
	while (current)
	{
		ft_strcat(str, "/");
		ft_strcat(str, current->content);
		current = current->next;
	}
	if (!*str)
		ft_strcat(str, "/");
	return (str);
}

static char		*ft_merge_paths(char *path1, char *path2, char *str)
{
	t_list		*list;
	t_list		*current;

	list = ft_tabtolst((void **)ft_strsplit(path1, '/'));
	ft_lstpushback(&list, ft_tabtolst((void **)ft_strsplit(path2, '/')));
	current = list;
	while (current->next)
		current = current->next;
	free(current->content);
	current->content = ft_strdup(str);
	return (ft_lsttoasc(list));
}

char			*ft_find_file(char *command, char *str)
{
	char	*path;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		path = ft_merge_paths(cwd, command, str);
		free(cwd);
	}
	return (path);
}
