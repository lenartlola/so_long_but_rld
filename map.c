/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:32:56 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/08 10:32:56 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_create_map(char *filename, t_vars *vars)
{
	t_map	*map;

	map = ft_init_map();
	if (!map)
		return (NULL);
	ft_readmap(filename, map);
	ft_map_imgs(map, vars);
	if (!ft_check_map(map))
		return (NULL);
	return (map);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->c = malloc(1);
	return (map);
}

void	ft_readmap(char *filename, t_map *map)
{
	char	*str;
	int		fd;
	int		h;

	map->s = ft_init_size();
	if (!map->s)
		return ;
	fd = open(filename, O_RDONLY);
	h = 0;
	str = get_next_line(fd);
	map->s->w = ft_strlen(str) - 1;
	while (str != NULL)
	{
		str[ft_strlen(str) - 1] = '\0';
		if ((int)ft_strlen(str) != map->s->w)
			return ;
		map->c = ft_strconcat(map->c, str);
		str = get_next_line(fd);
		h++;
	}
	map->s->h = h;
}

static int	ft_is_border(int i, int width, int height)
{
	if (i < width)
		return (1);
	else if (i > (height - 1 ) * width)
		return (1);
	else if (i % width == 0)
		return (1);
	else if (i % width == width - 1)
		return (1);
	return (0);
}

int	ft_check_map(t_map *map)
{
	int	i;

	i = 0;
	map->player = -1;
	map->nb_collect = 0;
	map->nb_exit = 0;
	while (i < (int)ft_strlen(map->c))
	{
		if (ft_strchr_bool("01CEPM", map->c[i]) == 0)
			return (0);
		if (ft_is_border(i, map->s->w, map->s->h) && map->c[i] != '1')
			return (0);
		if (map->c[i] == 'E')
			map->nb_exit++;
		else if (map->c[i] == 'C')
			map->nb_collect++;
		else if (map->c[i] == 'P' && map->player == -1)
			map->player = i;
		else if (map->c[i] == 'P')
			return (0);
		i++;
	}
	if (map->nb_collect == 0 || map->nb_exit == 0 || map->player == -1)
		return (0);
	return (1);
}
