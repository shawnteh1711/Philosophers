/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:20:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/02 17:26:49 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// get fork by pthread mutex lock
void	ft_take_fork(t_phil *phil, long long time)
{
	ft_get_fork(phil);
}

void	ft_log_fork(t_phil *phil, long long time)
{
	printf("%lld philosopher %d has taken a fork\n", time, phil->id);
}

void	ft_eat(t_phil *phil, long long time)
{
	phil->l_eat = time;
	printf("%lld philosopher %d is eating\n", time, phil->id);
	ft_rel_fork(phil);
}

void	ft_slp(t_phil *phil, long long time)
{
	printf("%lld philosopher %d is sleeping\n", time, phil->id);
}

void	ft_thk(t_phil *phil, long long time)
{
	printf("%lld philosopher %d is thinking\n", time, phil->id);
}

void	ft_die(t_phil *phil, long long time)
{
	phil->stat = DIE;
	printf("%lld philosopher %d die\n", time, phil->id);
}
