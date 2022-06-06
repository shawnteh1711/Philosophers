/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/06 19:22:16 by steh             ###   ########.fr       */
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
	ft_get_fork(phil);
	printf(GRN "%lld %d is eating\n" RST, time, phil->id);
	ft_ms_slp(phil->info.t_eat);
	phil->stat = EAT;
	phil->c_eat--;
	phil->l_eat = time;
	ft_rel_fork(phil);

}

void	ft_slp(t_phil *phil, long long time)
{
	t_info	*info;

	info = &phil->info;
	phil->stat = SLP;
	printf(BLU "%lld %d is sleeping\n" RST, ft_cur_time(), phil->id);
	ft_ms_slp(phil->info.t_slp);
	phil->l_slp = ft_cur_time();
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
