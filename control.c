/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:32:56 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/08 10:32:56 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sizes	*ft_init_size(void)
{
	t_sizes	*s;

	s = malloc(sizeof(t_sizes));
	return (s);
}

t_sizes	*ft_new_size(int width, int height)
{
	t_sizes	*s;

	s = ft_init_size();
	if (!s)
		return (NULL);
	s->w = width;
	s->h = height;
	return (s);
}

size_t	ft_strchr_bool(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}
