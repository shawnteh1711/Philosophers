/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:04:35 by steh              #+#    #+#             */
/*   Updated: 2022/06/02 17:03:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	ft_crt_ths(t_info *info)
{
	int		i;

	i = -1;
	info->phil = malloc(sizeof(t_phil) * info->n_phi);
	if (!info->phil)
		return ;
	while (++i < info->n_phi)
		ft_crt_th(i, info);
}

void	ft_crt_th(int i, t_info *info)
{
	t_phil	*phil;

	phil = info->phil;
	phil[i].id = i;
	phil[i].stat = THK;
	phil[i].l_eat = 0;
	phil[i].c_eat = info->c_eat;
	phil[i].l_fork = info->fork[i];
	phil[i].r_fork = info->fork[(i + 1) % info->n_phi];
	// printf("philo: %d\n l_fork: %p\t r_fork: %p\n", i, &phil[i].l_fork, &phil[i].r_fork);
	if (pthread_create(&(phil[i].thd), NULL, ft_routine, &info->phil[i]) != 0)
	{
		printf("thread create error\n");
	}
}

void	*ft_routine(void *arg)
{
	long long	time;
	t_phil		*phil;

	phil = (t_phil *) arg;
	if (phil->id % 2 == 0)
		usleep(phil->info.t_eat);
	while (phil->stat != DIE)
	{
		time = ft_cur_time();
		ft_take_fork(phil, time);
		ft_eat(phil, time);
		ft_slp(phil, time);
		ft_thk(phil, time);
		ft_die(phil, time);
	}
	return (NULL);
}
