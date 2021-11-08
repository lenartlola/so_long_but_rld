/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:32:56 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/08 10:32:56 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_new_img(char *filename, t_vars *vars)
{
	t_img	*im;

	im = malloc(sizeof(t_img));
	if (!im)
		return (NULL);
	im->s = ft_init_size();
	if (!im->s)
		return (NULL);
	im->i = mlx_xpm_file_to_image(vars->mlx, filename, &im->s->w, &im->s->h);
	return (im);
}

void	ft_map_imgs(t_map *map, t_vars *vars)
{
	if (map->s->w < 15 && map->s->h < 8)
	{
		ft_map_imgs_larges(map, vars);
	}
	else
	{
		map->bak = ft_new_img("./assets/ground.xpm", vars);
		map->wall = ft_new_img("./assets/wall.xpm", vars);
		map->exit = ft_new_img("./assets/portal.xpm", vars);
		map->enemy = ft_new_img("./assets/enemy.xpm", vars);
		map->perso_l = ft_new_img("./assets/pac_l.xpm", vars);
		map->perso_r = ft_new_img("./assets/pac_r.xpm", vars);
		map->perso_u = ft_new_img("./assets/pac_u.xpm", vars);
		map->perso_d = ft_new_img("./assets/pac_d.xpm", vars);
		map->coin_f = ft_new_img("./assets/coin_f.xpm", vars);
		map->coin_d = ft_new_img("./assets/coin_d.xpm", vars);
		map->coin_p = ft_new_img("./assets/coin_p.xpm", vars);
	}
	map->chunk = map->bak->s->w;
}

void	ft_map_imgs_larges(t_map *map, t_vars *vars)
{
	map->bak = ft_new_img("./assets/ground_large.xpm", vars);
	map->wall = ft_new_img("./assets/wall_large.xpm", vars);
	map->exit = ft_new_img("./assets/portal_large.xpm", vars);
	map->enemy = ft_new_img("./assets/enemy_large.xpm", vars);
	map->perso_l = ft_new_img("./assets/pac_l_large.xpm", vars);
	map->perso_r = ft_new_img("./assets/pac_r_large.xpm", vars);
	map->perso_u = ft_new_img("./assets/pac_u_large.xpm", vars);
	map->perso_d = ft_new_img("./assets/pac_d_large.xpm", vars);
	map->coin_f = ft_new_img("./assets/coin_f_large.xpm", vars);
	map->coin_d = ft_new_img("./assets/coin_d_large.xpm", vars);
	map->coin_p = ft_new_img("./assets/coin_p_large.xpm", vars);
}

void	ft_putimage(t_vars *vars, void *img, int i)
{
	int	x;
	int	y;

	x = i % vars->map->s->w;
	y = i / vars->map->s->w;
	x *= vars->map->chunk;
	y *= vars->map->chunk;
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}
