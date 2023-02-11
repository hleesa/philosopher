/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:25:19 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:25:20 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

long long	toll(const char *str, size_t i)
{
	long long		acc;
	const long long	llmax = LONG_LONG_MAX;

	acc = 0LL;
	while (str[i])
	{
		if (acc > llmax / 10LL || (acc == llmax / 10LL && str[i] - '0' \
					> (llmax % 10LL)) || !ft_isdigit(str[i]))
			return (-1LL);
		acc = acc * 10LL + (str[i] - '0');
		++i;
	}
	return (acc);
}

long long	ft_atoll(const char *str)
{
	size_t		i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	if (str[i] == 0 || str[i] == '-')
		return (-1LL);
	return (toll(str, i));
}
