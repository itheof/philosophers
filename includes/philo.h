/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 19:05:27 by tvallee           #+#    #+#             */
/*   Updated: 2015/03/13 22:06:07 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <gtk/gtk.h>
# include <pthread.h>
# include <time.h>
# include <cairo.h>
# include <stdlib.h>
# include "libft.h"

# define MAX_LIFE get_env(NULL)->max_life
# define EAT_T get_env(NULL)->eat_t
# define REST_T get_env(NULL)->rest_t
# define THINK_T get_env(NULL)->think_t
# define TIMEOUT get_env(NULL)->timeout
# define RUNNING_STATE get_env(NULL)->running_state

# define BUILDER get_env(NULL)->gtkbuilder

# define STOPPED 0
# define PAUSED -1
# define RUNNING 1

# define N_PHILO 7

enum
{
						EAT,
						REST,
						THINK,
						WAIT,
};

enum
{
						DEBUG,
                        TIME,
};

typedef struct			s_philosophe
{
	int					state;
	int					hp;
    int                 num_philo;
	pthread_mutex_t		left;
	pthread_mutex_t		right;
	struct s_env		*env;
	int					dead;
	int					sec;
}						t_philo;

typedef struct			s_env
{
	pthread_mutex_t		baguettes[N_PHILO];
	t_philo				philosophers[N_PHILO];
	pthread_t			thread_addr[N_PHILO];
    int                 running_state;
    int                 step_time;
	int					max_life;
	int					eat_t;
	int					rest_t;
	int					think_t;
    int                 timeout;
	char				options[2];
    GtkBuilder          *gtkbuilder;
    GtkWidget           *widget;
    cairo_t             *cr;
}						t_env;

void					*philo_routine(void *philo);
void					init_env(t_env *e);
void					get_options(int ac, char **av, char opt[]);
int						check_death(t_philo *philo);
void					exit_simulation(t_env *env);
t_env					*get_env(t_env *env);
void					term_display_loop(t_env *env);

GtkBuilder              *init_gtk_env(char *command);
char                    *ft_find_builder(char *command);

void                    connect_top_bar_signals(GtkBuilder *builder);
void                    connect_params_spinbut(GtkBuilder *builder);

gint                    pbar_timeout(void);


int                     draw_callback (GtkWidget *widget, cairo_t *cr,
                            gpointer data);

void                    draw(void);

void                    max_hp(GtkSpinButton *spin_button, gpointer user_data);
void                    eat_t(GtkSpinButton *spin_button, gpointer user_data);
void                    rest_t(GtkSpinButton *spin_button, gpointer user_data);
void                    think_t(GtkSpinButton *spin_button, gpointer user_data);
void                    timeout(GtkSpinButton *spin_button, gpointer user_data);

void                    play(GtkButton *widget, gpointer user_data);
void                    p_pause(GtkButton *widget, gpointer user_data);
void                    stop(GtkButton *widget, gpointer user_data);

#endif
