  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:27:13 by steh              #+#    #+#             */
/*   Updated: 2022/06/02 13:47:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define RED "\033[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define RST "\033[0m"
# define CYN "\033[0;36m"

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
	struct s_fork	*fork;
}	t_info;

typedef struct s_fork
{
	pthread_mutex_t	mtx;
}	t_fork;

typedef	struct s_phil
{
	int			id;
	pthread_t	thd;
	t_stat		stat;
	t_info		info;
	t_fork		l_fork;
	t_fork		r_fork;
	int			c_eat;
	long long	l_eat;
	long long	l_slp;
	// pthread_mutex_t		*n_fork;
	// pthread_mutex_t		fork;
}	t_phil;

// parse and checking
int			ft_parse(int ac, char **av, t_info *info);
int			ft_n_arg(int ac);
int			ft_c_arg(int ac, t_info *info);
int			ft_atoi(const char *str);

// thread
void		ft_crt_ths(t_info *info);
void		ft_crt_th(int i, t_info *info);
void		*ft_routine(void *arg);
void		ft_del_th(t_info *info);

// mutex
void		ft_crt_mts(t_info *info);
void		ft_get_fork(t_phil *phil);
void		ft_rel_fork(t_phil *phil);
void		ft_del_mtx(t_info *info);

// time
long long	ft_cur_time(void);
long long	ft_t_stamp(long long msec);

// task
void		ft_eat(t_phil *phil, long long time);
void		ft_slp(t_phil *phil, long long time);
void		ft_thk(t_phil *phil, long long time);
void		ft_die(t_phil *phil, long long time);

// log
void		ft_log_fork(t_phil *phil, long long time);
void		ft_mslp(t_phil *phil);

# endif