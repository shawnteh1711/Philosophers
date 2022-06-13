/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:30:57 by steh              #+#    #+#             */
/*   Updated: 2022/06/13 21:18:09 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

void	ft_crt_sem(t_info *info)
{
	info->sem = sem_open("fork", O_CREAT, 0644, info->n_phi);
	if (info->sem == SEM_FAILED)
	{
		printf("Semaphore error\n");
		exit(EXIT_FAILURE);
	}
}