/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:16:57 by steh              #+#    #+#             */
/*   Updated: 2022/06/13 22:29:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

void	ft_crt_pids(t_info *info)
{
	int	i;

	i = -1;
	info->phil = malloc(sizeof(t_phil) * info->n_phi);
	info->p_id = malloc(sizeof(pid_t) * info->n_phi);
	while (++i < info->n_phi)
	{
		ft_crt_pid(i, info);
	}
}

void	ft_crt_pid(int i, t_info *info)
{
	t_phil	*phil;
	pid_t	pid;

	pid = fork();
	printf("id: %d\n", pid);

	info->p_id[i] = fork();
	printf("p_id: %d\n", info->p_id[i]);
	// phil = info->phil;
	// if (info->p_id[i] != 0)
	// 	return ;
	// else
	// 	phil[i].p_id = info->p_id[i];
	// printf("id: %d\n", phil[i].p_id);
	// phil[i].stat = THK;
	// phil[i].l_eat = 0;
	// phil[i].l_slp = 0;
	// phil[i].c_eat = info->c_eat;
	// phil[i].info = info;
	// phil[i].info->stat = THK;
}