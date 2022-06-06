/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/06 13:46:32 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// get fork by pthread mutex lock
void	ft_eat(t_phil *phil, long long time)
{
	t_info	*info;
	// long long	t;

	info = &phil->info;
	// t = ft_cur_time();
	// printf("time: %llu\n", time);
	// printf("t: %llu\n", t);
	// ft_get_fork(phil);
	phil->l_eat = time;
	phil->info.t_eat = time;
	phil->c_eat--;
	phil->stat = EAT;
	printf(GRN "%lld %d is eating\n" RST, ft_cur_time(), phil->id);
	// ft_mslp(phil);
	sleep(1);
	// printf("after time: %llu\n", ft_cur_time());
	// ft_rel_fork(phil);

}

void	ft_slp(t_phil *phil, long long time)
{
	phil->stat = SLP;
	phil->l_slp = time;
	printf(BLU "%lld %d is sleeping\n" RST, ft_cur_time(), phil->id);
	sleep(1);
}

void	ft_thk(t_phil *phil, long long time)
{
	phil->stat = THK;
	printf(YEL "%lld %d is thinking\n" RST, ft_cur_time(), phil->id);
}

void	ft_die(t_phil *phil, long long time)
{
	phil->stat = DIE;
	printf(RED "%lld %d die\n" RST, time, phil->id);
}
