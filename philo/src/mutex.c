/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:52 by steh              #+#    #+#             */
/*   Updated: 2022/06/08 15:57:22 by steh             ###   ########.fr       */
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
		// if (pthread_mutex_init(info->fork[i].mtx, NULL) != 0)
		if (pthread_mutex_init(info->fork[i].mtx, NULL) != 0)
			printf("Mutex error\n");
	}
	// printf("phil->id: %d phil->l_fork: %p, phil->r_fork: %p\n", info->phil->id, info->phil->l_fork.mtx, info->phil->r_fork.mtx);
}

void	ft_get_fork(t_phil *phil)
{
	int d = pthread_mutex_lock(phil->l_fork.mtx);
	// printf("d = %d\n",d);
	// pthread_mutex_lock(phil->l_fork.mtx)
	if (pthread_mutex_lock(phil->l_fork.mtx) != 0)
	{
		// printf("Error lock left fork\n");
	}
	ft_log_fork(phil, ft_cur_time());
	// pthread_mutex_lock(phil->r_fork.mtx) 
	if (pthread_mutex_lock(phil->r_fork.mtx) != 0)
	{
		// printf("Error lock right fork\n");
	}
	ft_log_fork(phil, ft_cur_time());
	// printf("phil->id: %d phil->l_fork: %p, phil->r_fork: %p\n", phil->id, &phil->l_fork.mtx, &phil->r_fork.mtx);
}


void	ft_get_fork2(t_phil *phil, t_info *info)
{
	// int a;
	// = pthread_mutex_lock(info->phil->l_fork.mtx);
	// printf("a = %d\n",a);
	// a = pthread_mutex_lock(info->phil->l_fork.mtx);
	if (pthread_mutex_lock(phil->l_fork.mtx) != 0)
	{
		printf("Error lock left fork\n");
	}
	// printf("a = %d\n",a);
	ft_log_fork(phil, ft_cur_time());
	// pthread_mutex_lock(phil->r_fork.mtx) 
	if (pthread_mutex_lock(phil->r_fork.mtx) != 0)
	{
		printf("Error lock right fork\n");
	}
	ft_log_fork(phil, ft_cur_time());
	// printf("phil->id: %d phil->l_fork: %p, phil->r_fork: %p\n", phil->id, info->phil->l_fork.mtx, info->phil->r_fork.mtx);
	
}
void	ft_rel_fork(t_phil *phil)
{
	int u = pthread_mutex_unlock(phil->l_fork.mtx);
	printf("u = %d\n",u);
	// pthread_mutex_unlock(phil->l_fork.mtx) 
	if (pthread_mutex_unlock(phil->l_fork.mtx) != 0)
	{
		// printf("Error unlock left fork\n");
	}
	// pthread_mutex_unlock(phil->r_fork.mtx)
	if (pthread_mutex_unlock(phil->r_fork.mtx) != 0)
	{
		// printf("Error unlock right fork\n");
	}
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
