/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:32:56 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/08 10:32:56 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pow(int base, int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res = res * base;
		pow--;
	}
	return (res);
}

int	ft_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_mlx_close(t_vars *vars)
{
	ft_clean_exit(vars);
	return (0);
}

void	ft_free_image(t_img *img)
{
	free(img->s);
	free(img);
}

void	ft_clean_exit(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_image(vars->map->perso_l);
	ft_free_image(vars->map->perso_r);
	ft_free_image(vars->map->perso_u);
	ft_free_image(vars->map->perso_d);
	ft_free_image(vars->map->coin_f);
	ft_free_image(vars->map->coin_d);
	ft_free_image(vars->map->coin_p);
	ft_free_image(vars->map->bak);
	ft_free_image(vars->map->wall);
	ft_free_image(vars->map->exit);
	free(vars->map->c);
	free(vars->map->s);
	free(vars->map);
	free(vars->s);
	exit(0);
}
