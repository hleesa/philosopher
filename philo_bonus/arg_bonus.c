/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:24:48 by salee2            #+#    #+#             */
/*   Updated: 2023/01/07 18:24:49 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	is_right_argc(int argc)
{
	if (argc == MANDA || argc == OPTION)
		return (TRUE);
	return (FALSE);
}

t_bool	is_right_argv(int argc, char *argv[])
{
	int			i;
	const int	ofs = 1;

	i = -1;
	while (++i + ofs < argc)
	{
		if (ft_atoll(argv[i + ofs]) == ERROR)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	is_right_arg(int argc, char *argv[])
{
	if (!is_right_argc(argc) || !is_right_argv(argc, argv))
		return (FALSE);
	return (TRUE);
}

t_common_philo	input_args(int argc, char *argv[])
{
	t_common_philo	ret;
	t_ll			*pptr;
	int				i;
	const int		ofs = 1;

	memset(&ret, -1, sizeof(t_common_philo));
	pptr = (void *)&ret;
	i = 0;
	pptr[i] = ft_atoll(argv[i + ofs]);
	while (++i + ofs < MANDA)
		pptr[i] = ft_atoll(argv[i + ofs]) * 1000LL;
	if (argc == OPTION)
		pptr[i] = ft_atoll(argv[i + ofs]) + 1LL;
	else
		pptr[i] = -1LL;
	return (ret);
}
