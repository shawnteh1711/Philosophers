/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:11:02 by steh              #+#    #+#             */
/*   Updated: 2022/06/12 18:56:42 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

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

void	my_slp(t_phil *phil, long duration, char *s)
{
	long long	start;

	start = ft_cur_time();
	while (start <= duration)
	{
		usleep(50);
		start = ft_cur_time();
	}
	printf("%llu %d %s\n", start, phil->id, s);
}
