/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:27:13 by steh              #+#    #+#             */
/*   Updated: 2022/06/01 21:16:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef enum s_stat
{
	EAT = 0,
	SLP = 1,
	THK = 2,
	DIE = 3
}	t_stat;

typedef struct s_info
{
	int				n_phi;
	int				t_die;
	int				t_eat;
	int				t_slp;
	int				c_eat;
	struct s_phil	*phil;
}	t_info;

typedef struct s_fork
{
	pthread_mutex_t	*mtx;
}	t_fork;

typedef	struct s_phil
{
	/* data */
	int			id;
	pthread_t	thd;
	t_stat		stat;
	t_info		info;
	t_fork		l_fork;
	t_fork		r_fork;
	int			c_eat;
	long		l_eat;
	// pthread_mutex_t		*n_fork;
	// pthread_mutex_t		fork;
}	t_phil;

// parse and checking
int		ft_parse(int ac, char **av, t_info *info);
int		ft_n_arg(int ac);
int		ft_c_arg(int ac, t_info *info);
int		ft_atoi(const char *str);

// thread
void	ft_crt_th(t_info *info);
void	ft_new_philo(int i, t_info *info);
void	*ft_routine(void *arg);

// time
long	ft_get_time(void);
void	philo(void);

# endif