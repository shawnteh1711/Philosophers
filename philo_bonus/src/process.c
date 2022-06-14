/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:16:57 by steh              #+#    #+#             */
/*   Updated: 2022/06/14 21:52:24 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

void	ft_crt_pids(t_info *info)
{
	int	i;
	pid_t	pid;

	i = -1;
	info->phil = malloc(sizeof(t_phil) * info->n_phi);
	info->p_id = malloc(sizeof(pid_t) * info->n_phi);
	while (++i < info->n_phi)
	{
		pid = fork();
		if (pid == 0)
			info->p_id[i] = pid;
		ft_crt_phil(i, info);
	}
}

void	ft_crt_phil(int i, t_info *info)
{
	t_phil	*phil;
	
	phil = info->phil;
	phil[i].stat = THK;
	phil[i].p_id = info->p_id[i];
	phil[i].l_eat = 0;
	phil[i].l_slp = 0;
	phil[i].c_eat = info->c_eat;
	phil[i].info = info;
	phil[i].info->stat = THK;
	ft_routine(&phil[i]);
	exit(EXIT_SUCCESS);
}

void	ft_routine(void *arg)
{
	long long	time;
	t_phil		*phil;

	phil = (t_phil *) arg;
	while (phil->info->stat != DIE && phil->c_eat != 0)
	{
		time = ft_cur_time();
		if (time > phil->l_eat + phil->info->t_die)
			ft_die(phil, time);
		else if (phil->stat == EAT
			&& time > phil->l_eat + phil->info->t_eat)
			ft_slp(phil, time);
		else if (phil->stat == SLP
			&& time > phil->l_slp + phil->info->t_slp)
			ft_thk(phil, time);
		else if (phil->stat == THK)
			ft_eat(phil, time);
		else
			usleep(50);
	}
	return ;
}

void	ft_del_pid(t_info *info)
{
	int	i;
	// int	status;

	i = -1;
	while (++i < info->n_phi)
	{
		waitpid(info->p_id[i], NULL, 0);
		// printf("status: %d\n", status);
		if (kill(info->p_id[i], SIGKILL) != 0)
			printf("Error eliminate pid");
	// 	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
	// 	{
	// 		ft_philo_kill_all(phil_no, pid);
	// 		return ;
	// 	}
	}
}