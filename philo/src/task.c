/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/04 21:08:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// get fork by pthread mutex lock
void	ft_take_fork(t_phil *phil, long long time)
{
	ft_get_fork(phil);
}

void	ft_eat(t_phil *phil, long long time)
{
	ft_take_fork(phil, time);
	phil->l_eat = time;
	phil->c_eat--;
	phil->stat = EAT;
	printf("%lld %d is eating\n", time, phil->id);
	// printf("eat: phil->id: %d ,phil->l_fork: %p, phil->t_for: %p\n", phil->id, &phil->l_fork.mtx, &phil->r_fork.mtx);
	ft_rel_fork(phil);
}

void	ft_slp(t_phil *phil, long long time)
{
	phil->stat = SLP;
	phil->l_slp = time;
	printf("%lld %d is sleeping\n", time, phil->id);
}

void	ft_thk(t_phil *phil, long long time)
{
	phil->stat = THK;
	printf("%lld %d is thinking\n", time, phil->id);
}

void	ft_die(t_phil *phil, long long time)
{
	phil->stat = DIE;
	printf("%lld %d die\n", time, phil->id);
}
