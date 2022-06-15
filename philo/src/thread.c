/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:04:35 by steh              #+#    #+#             */
/*   Updated: 2022/06/15 20:13:23 by steh             ###   ########.fr       */
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
	phil[i].l_slp = 0;
	phil[i].c_eat = info->c_eat;
	phil[i].info = info;
	phil[i].info->stat = THK;
	phil[i].l_fork = &info->fork[i];
	phil[i].r_fork = &info->fork[(i + 1) % info->n_phi];
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
	while (phil->c_eat != 0)
	{
		time = ft_cur_time();
		if (time > phil->l_eat + phil->info->t_die)
			ft_die(phil, time);
		else if (phil->stat == EAT
			&& time > phil->l_eat + phil->info->t_eat)
			ft_slp(phil, time);
		else if (phil->stat == SLP
			&& time > phil->l_slp + phil->info->t_slp)
			ft_thk(phil, time);
		else if (phil->stat == THK)
			ft_eat(phil, time);
		else
			usleep(50);
	}
	return (NULL);
}

void	ft_del_th(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_phi)
	{
		if (info->phil != NULL)
		{
			pthread_join(info->phil[i].thd, NULL);
		}
	}
}
