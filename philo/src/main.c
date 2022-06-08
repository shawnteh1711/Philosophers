/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:05:32 by steh              #+#    #+#             */
/*   Updated: 2022/06/07 16:11:28 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// algo: parse, create thread & mutex, dextroy thread & mutex
int	main(int ac, char **av)
{
	t_info	info;
	t_fork	fork;

	if (ft_parse(--ac, ++av, &info) == -1)
		return (1);
	ft_crt_mts(&info);
	ft_crt_ths(&info);
	ft_del_mtx(&info);
	ft_del_th(&info);
	// system("leaks philo");
	return (0);
}
