/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/08 15:49:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// get fork by pthread mutex lock
void	ft_log_fork(t_phil *phil, long long time)
{
	printf(CYN "%lld %d has taken a fork\n" RST, time, phil->id);
}

void	ft_eat(t_phil *phil, long long time)
{
	t_info	*info;

	info = phil->info;
	// printf("phil->id: %d phil->l_fork: %p, phil->r_fork: %p\n", phil->id, phil->l_fork.mtx, phil->r_fork.mtx);
	if (phil->l_fork.mtx == phil->r_fork.mtx)
	{
		// printf("same fork");
		return ;
	}
	// ft_get_fork(phil);
	ft_get_fork2(phil, info);
	printf(GRN "%lld %d is eating\n" RST, time, phil->id);
	// ft_ms_slp(phil->info.t_eat);
	ft_ms_slp(phil->info->t_eat);
	phil->stat = EAT;
	phil->l_eat = time;
	if (phil->c_eat > 0)
		phil->c_eat--;
	ft_rel_fork(phil);

}

void	ft_slp(t_phil *phil, long long time)
{
	phil->stat = SLP;
	printf(BLU "%lld %d is sleeping\n" RST, ft_cur_time(), phil->id);
	// ft_ms_slp(phil->info.t_slp);
	ft_ms_slp(phil->info->t_slp);
	phil->l_slp = ft_cur_time();
	printf("c_eat: %d\n", phil->c_eat);
}

void	ft_thk(t_phil *phil, long long time)
{
	phil->stat = THK;
	printf(YEL "%lld %d is thinking\n" RST, ft_cur_time(), phil->id);
	ft_ms_slp(200);
}

void	ft_die(t_phil *phil, long long time)
{
	phil->stat = DIE;
	printf(RED "%lld %d die\n" RST, time, phil->id);
}
