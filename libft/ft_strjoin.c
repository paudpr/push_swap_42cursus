/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:37:41 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/03/28 14:23:56 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	j = (ft_strlen(s1) + ft_strlen(s2));
	t = malloc((j + 1) * sizeof(char));
	if (t == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		t[i++] = s2[j];
		j++;
	}
	t[i++] = '\0';
	return (t);
}
