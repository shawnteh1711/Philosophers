/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:52 by steh              #+#    #+#             */
/*   Updated: 2022/06/08 20:18:16 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	ft_crt_mts(t_info *info)
{
	int			i;

	info->fork = malloc(sizeof(t_fork) * (info->n_phi));
	i = -1;
	while (++i < info->n_phi)
	{
		info->fork[i].mtx = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(info->fork[i].mtx, NULL) != 0)
			printf("Mutex error\n");
	}
}

void	ft_get_fork(t_phil *phil)
{
	if (pthread_mutex_lock(phil->l_fork->mtx) == 0)
		ft_log_fork(phil, ft_cur_time());
	if (pthread_mutex_lock(phil->r_fork->mtx) == 0)
		ft_log_fork(phil, ft_cur_time());
	// printf("phil->id: %d phil->l_fork: %p, phil->r_fork: %p\n", phil->id, &phil->l_fork.mtx, &phil->r_fork.mtx);
}

void	ft_rel_fork(t_phil *phil)
{
	pthread_mutex_unlock(phil->l_fork->mtx);
	pthread_mutex_unlock(phil->r_fork->mtx);
	// printf("rel: phil->id: %d ,phil->l_fork: %p, phil->t_for: %p\n", phil->id, &phil->l_fork.mtx, &phil->r_fork.mtx);
}

void	ft_del_mtx(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_phi)
	{
		if (info->fork != NULL)
		{
			pthread_mutex_destroy(info->fork[i].mtx);
		}
		i++;
	}
}
