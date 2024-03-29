/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:22:59 by pauladelpin       #+#    #+#             */
/*   Updated: 2022/03/28 17:10:53 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//ignores spaces, + , -
static int	ft_atoi_long_spaces(const char *str, int *r)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45)
		*r = -1;
	while (str[i] == 45 || str[i] == 43)
		i++;
	return (i);
}

//version of atoi that allows translation of max_int and min_int
long	ft_atoi_long(const char *str)
{
	int		i;
	int		r;
	long	sol;

	r = 1;
	sol = 0;
	i = ft_atoi_long_spaces(str, &r);
	if (i >= 2)
	{
		print_error();
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (sol > 2147483647 && r == 1)
			return ((long)MAX_INT + 1);
		if (sol > 2147483648 && r == -1)
			return ((long)MIN_INT - 1);
		else
			sol = (sol * 10) + (str[i] - 48);
		i++;
	}
	return (sol * r);
}
