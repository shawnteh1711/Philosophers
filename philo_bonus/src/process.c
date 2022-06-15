/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:16:57 by steh              #+#    #+#             */
/*   Updated: 2022/06/15 22:38:57 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

// void	ft_crt_pids(t_info *info, sem_t *fork)
void	ft_crt_pids(t_info *info)
{
	int		i;

	i = -1;
	info->p_id = malloc(sizeof(pid_t) * info->n_phi);
	while (++i < info->n_phi)
	{
		info->p_id[i] = ft_crt_phil(i, info);
		if (info->p_id[i] < 0)
		{
			while (--i >= 0)
			{
				kill(info->p_id[i], SIGKILL);
				printf("Error create process\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

// pid_t	ft_crt_phil(int i, t_info *info, sem_t *sem)
pid_t	ft_crt_phil(int i, t_info *info)
{
	t_phil	phil;
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return (pid);
	else
		phil.p_id = pid;
	phil.id = i;
	phil.stat = THK;
	phil.l_eat = 0;
	phil.l_slp = 0;
	phil.c_eat = info->c_eat;
	phil.info = info;
	phil.sem = info->sem;
	// phil.sem = sem;
	phil.info->stat = THK;
	ft_routine(&phil);
	exit(EXIT_SUCCESS);
}

void	ft_routine(void *arg)
{
	long long	time;
	t_phil		*phil;

	phil = (t_phil *) arg;
	while (phil->c_eat != 0)
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
	sem_close(phil->sem);
	return ;
}

void	ft_kill_pid(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_phi)
	{
		kill(info->p_id[i], SIGKILL);
	}
}

void	ft_del_pid(t_info *info)
{
	int	i;
	int	stat;

	i = -1;
	while (++i < info->n_phi)
	{
		waitpid(-1, &stat, 0);
		if (WIFEXITED(stat) && WEXITSTATUS(stat))
		{
			ft_kill_pid(info);
			return ;
		}
	}
}
