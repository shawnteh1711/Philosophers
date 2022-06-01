/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:11:02 by steh              #+#    #+#             */
/*   Updated: 2022/06/01 21:21:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

long	ft_get_time(void)
{
	struct timeval	tv;
	long			ret_t;

	ret_t = gettimeofday(&tv, NULL);
	printf("t: %ld\n", tv.tv_sec * 1000000 + tv.tv_sec);
	return (ret_t);
}