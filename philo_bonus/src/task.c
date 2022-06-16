/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/16 21:39:52 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

// get fork by pthread mutex lock
void	ft_log_fork(t_phil *phil, long long time)
{
	printf(CYN "%lld %d has taken a fork\n" RST, time / 1000, phil->id);
}

void	ft_eat(t_phil *phil, long long time)
{
	t_info	*info;

	info = phil->info;
	if (info->n_phi == 1)
		return ;
	if (phil->id % 2 == 1 && time < info->t_eat)
		return ;
	if (phil->l_eat != 0)
	{
		if (info->n_phi % 2 == 0
			&& time <= phil->l_eat + 2 * info->t_eat)
			return ;
		else if (info->n_phi % 2 == 1
			&& time <= phil->l_eat + 3 * info->t_eat)
			return ;
	}
	ft_get_fork(phil);
	printf(GRN "%lld %d is eating\n" RST, time / 1000, phil->id);
	phil->stat = EAT;
	phil->l_eat = ft_cur_time();
	ft_rel_fork(phil);
}

void	ft_slp(t_phil *phil, long long time)
{
	if (phil->c_eat > 0)
		phil->c_eat--;
	phil->stat = SLP;
	printf(BLU "%lld %d is sleeping\n" RST, time / 1000, phil->id);
	phil->l_slp = time;
}

void	ft_thk(t_phil *phil, long long time)
{
	phil->stat = THK;
	printf(YEL "%lld %d is thinking\n" RST, time / 1000, phil->id);
}

void	ft_die(t_phil *phil, long long time)
{
	phil->stat = DIE;
	phil->info->stat = DIE;
	printf(RED "%lld %d die\n" RST, time / 1000, phil->id);
	sem_close(phil->sem);
	exit(EXIT_FAILURE);
}
