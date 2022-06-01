/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:07:31 by steh              #+#    #+#             */
/*   Updated: 2022/06/01 19:11:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

// parse argument into info
int	ft_parse(int ac, char **av, t_info *info)
{
	if (ft_n_arg(ac) == -1)
		return (-1);
	info->n_phi = ft_atoi(av[0]);
	info->t_die = ft_atoi(av[1]);
	info->t_eat = ft_atoi(av[2]);
	info->t_slp = ft_atoi(av[3]);
	if (ac == 5)
		info->c_eat = ft_atoi(av[4]);
	else
		info->c_eat = -1;
	if (ft_c_arg(ac, info) == -1)
		return (-1);
	return (0);
}

int	ft_n_arg(int ac)
{
	if (ac < 4 || ac > 5)
	{
		printf("4 or 5 input\n");
		return (-1);
	}
	return (0);
}

int	ft_c_arg(int ac, t_info *info)
{
	if (info->n_phi < 1
		|| info->t_die < 1
		|| info->t_eat < 1
		|| info->t_slp < 1
		|| (ac == 5 && info->c_eat < 1))
	{
		printf("Positive integer input");
		return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * sign);
}
