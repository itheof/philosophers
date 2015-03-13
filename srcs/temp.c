START TIMEOUT


static void init_philo(t_env *env)
{
	int i;
	i = 0;
	while (i < N_PHILO)
	{
		env->philosophers[i].state = WAIT;
		env->philosophers[i].hp = MAX_LIFE;
		env->philosophers[i].left = &env->baguettes[i];
		if (i != N_PHILO - 1)
			env->philosophers[i].right = &env->baguettes[i + 1];
		else
			(env->philosophers[i]).right = &env->baguettes[0];
		env->philosophers[i].env = env;
		env->philosophers[i].dead = 0;
		env->philosophers[i].sec = 0;
		env->philosophers[i].num_philo = i;
		i++;
	}
}

static void init_baguettes(pthread_mutex_t (baguettes)[])
{
	int i;
	i = 0;
	while (i < N_PHILO)
	{
		pthread_mutex_init((&baguettes[i]), NULL);
		i++;
	}
}

static void init_thread(t_env *env)
{
	int             i;
	t_philo *data;

	i = 0;
	while (i < N_PHILO)
	{
		data = (&((env->philosophers)[i]));
		pthread_create(&(env->thread_addr)[i],
				NULL, philo_routine, data);
		i++;
	}
}
