/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:23:34 by steh              #+#    #+#             */
/*   Updated: 2022/06/15 15:50:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos_b.h"

// int gettimeofday (struct timeval *tp , struct timezone *tz)
// On success, the gettimeofday() return 0, 
// for failure the function returns -1.
// long long	ft_cur_time(void)
long long	ft_cur_time(void)
{
	struct timeval		tv;
	time_t				sec;
	time_t				u_sec;
	long long			msec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec;
	u_sec = tv.tv_usec;
	msec = (sec * 1000000) + (u_sec);
	msec = ft_t_stamp(msec);
	return (msec);
}

long long	ft_t_stamp(long long msec)
{
	static long long	t_start = -1;

	if (t_start == -1)
	{	
		t_start = msec;
		return (0);
	}
	else
		return (msec - t_start);
}
