/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:04:35 by steh              #+#    #+#             */
/*   Updated: 2022/06/06 14:37:40 by steh             ###   ########.fr       */
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
	phil[i].info.t_die = info->t_die;
	phil[i].info.t_eat = info->t_eat;
	phil[i].info.t_slp = info->t_slp;
	phil[i].info.c_eat = info->c_eat;
	phil[i].c_eat = info->c_eat;
	phil[i].l_fork.mtx = info->fork[i].mtx;
	phil[i].r_fork.mtx = info->fork[(i + 1) % info->n_phi].mtx;
	if (pthread_create(&(phil[i].thd), NULL, ft_routine, &info->phil[i]) != 0)
	{
		printf("thread create error\n");
	}
}

void	*ft_routine(void *arg)
{
	long long	time;
	t_phil		*phil;
	int			i;

	i = 0;
	phil = (t_phil *) arg;
	if (phil->id % 2 == 0)
		usleep(phil->info.t_eat);
	while (i < 1)
	{
		time = ft_cur_time();
		ft_thk(phil, time);
		ft_get_fork(phil);
		ft_eat(phil, time);
		ft_rel_fork(phil);
		ft_slp(phil, time);
		// if (time > phil->l_eat + phil->info.t_die)
		// 	ft_die(phil, time);
		i++;
	}
	return (NULL);
}

void	ft_del_th(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_phi)
	{
		if (info->phil != NULL || info->phil->stat == DIE)
			pthread_join(info->phil[i].thd, NULL);
		i++;
	}
}
