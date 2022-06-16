/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:05:32 by steh              #+#    #+#             */
/*   Updated: 2022/06/16 16:33:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

int	main(int ac, char **av)
{
	t_info	info;
	sem_t	*fork;

	if (ft_parse(--ac, ++av, &info) == -1)
		return (1);
	ft_crt_sem(&info);
	ft_crt_pids(&info);
	ft_del_pid(&info);
	ft_del_sem(&info);
	return (0);
}
