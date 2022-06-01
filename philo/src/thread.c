/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:04:35 by steh              #+#    #+#             */
/*   Updated: 2022/06/01 21:09:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	ft_crt_th(t_info *info)
{
	int		i;

	i = 0;
	info->phil = malloc(sizeof(t_phil *) * info->n_phi);
	if (!info->phil)
		return ;
	while (i < info->n_phi)
	{
		ft_new_philo(i, info);
		i++;
	}
}

void	ft_new_philo(int i, t_info *info)
{
	t_phil	*phil;

	phil = info->phil;
	phil[i].id = i;
	phil[i].stat = THK;
	phil[i].l_eat = 0;
	phil[i].c_eat = info->c_eat;
	phil[i].l_fork = phil[i].l_fork;
	phil[i].r_fork = phil[(i + 1) % (info->n_phi)].l_fork;
	if (pthread_create(&(phil[i].thd), NULL, ft_routine, &info->phil[i]) != 0)
	{
		printf("thread create error\n");
	}
}

void	*ft_routine(void *arg)
{
	long	time;

	time = ft_get_time();
	
	printf("hi\n");
	usleep(10);
	printf("bye\n");
	return (NULL);
}
