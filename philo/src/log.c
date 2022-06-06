/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:43:09 by steh              #+#    #+#             */
/*   Updated: 2022/06/06 13:32:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	ft_log_fork(t_phil *phil, long long time)
{
	printf(CYN "%lld %d has taken a fork\n" RST, time, phil->id);
}

void	ft_mslp(t_phil *phil)
{
	usleep(phil->info.t_eat * 1000);
}
