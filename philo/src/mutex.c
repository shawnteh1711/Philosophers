/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:52 by steh              #+#    #+#             */
/*   Updated: 2022/06/05 16:38:34 by steh             ###   ########.fr       */
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
	pthread_mutex_lock(&phil->l_fork.mtx);
	pthread_mutex_lock(&phil->r_fork.mtx);
	// printf("get: phil->id: %d ,phil->l_fork: %p, phil->t_for: %p\n", phil->id, &phil->l_fork.mtx, &phil->r_fork.mtx);
	ft_log_fork(phil, ft_cur_time());
	ft_log_fork(phil, ft_cur_time());
}

void	ft_rel_fork(t_phil *phil)
{
	pthread_mutex_unlock(&phil->l_fork.mtx);
	pthread_mutex_unlock(&phil->r_fork.mtx);
	// printf("rel: phil->id: %d ,phil->l_fork: %p, phil->t_for: %p\n", phil->id, &phil->l_fork.mtx, &phil->r_fork.mtx);
}

void	ft_del_mtx(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_phi)
	{
		if (info->fork != NULL)
			pthread_mutex_destroy(&info->fork[i].mtx);
		i++;
	}
}
