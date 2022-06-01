/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:05:32 by steh              #+#    #+#             */
/*   Updated: 2022/06/01 21:05:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// algo: parse, create thread & mutex, dextroy thread & mutex
int	main(int ac, char **av)
{
	t_info	info;

	if (ft_parse(--ac, ++av, &info) == -1)
		return (1);
	ft_crt_th(&info);
	// ft_crt_mtx();
	// ft_del_th();
	// ft_del_mtx();
	return (0);
}
