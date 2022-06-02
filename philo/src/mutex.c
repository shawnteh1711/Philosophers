/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:52 by steh              #+#    #+#             */
/*   Updated: 2022/06/02 17:28:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	ft_crt_mts(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(t_fork) * (info->n_phi));
	i = -1;
	while (++i < info->n_phi)
	{
		if (pthread_mutex_init(&(info->fork[i].mtx), NULL) != 0)
			printf("Mutex error\n");
	}
}

void	ft_get_fork(t_phil *phil)
{
	// printf("get fork: phil: %d\n l_fork: %p\t r_fork: %p\n", phil->id, &phil->l_fork, &phil->r_fork);
	pthread_mutex_lock(&phil->l_fork.mtx);
	// printf("%d philosopher %d has taken a fork\n", 123444 , phil->id);
	pthread_mutex_lock(&phil->r_fork.mtx);
	// printf("%d philosopher %d has taken a fork\n", 123444 , phil->id);
	ft_log_fork(phil, ft_cur_time());
	ft_log_fork(phil, ft_cur_time());
}

void	ft_rel_fork(t_phil *phil)
{
	pthread_mutex_unlock(&phil->l_fork.mtx);
	pthread_mutex_unlock(&phil->r_fork.mtx);
}
