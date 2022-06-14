/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:30:57 by steh              #+#    #+#             */
/*   Updated: 2022/06/14 21:32:07 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

void	ft_crt_sem(t_info *info)
{
	info->sem = sem_open("fork", O_CREAT, 0644, info->n_phi);
	if (info->sem == SEM_FAILED)
	{
		printf("Error open semaphore\n");
		exit(EXIT_FAILURE);
	}
}

// void	ft_get_fork(t_phil *phil)
void	ft_get_fork(t_phil *phil, t_info *info)
{
	if (sem_wait(info->sem) == 0)
	{
		ft_log_fork(phil, ft_cur_time());
		ft_log_fork(phil, ft_cur_time());
	}
}

void	ft_rel_fork(t_phil *phil, t_info *info)
{
	if (sem_post(info->sem) != 0)
		printf("Error sem post");
}

void	ft_del_sem(t_info *info)
{
	sem_close(info->sem);
	if (sem_unlink("fork") != 0)
	{
		printf("Error unlink fork\n");
	}
	
}