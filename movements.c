/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:32:57 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/08 10:32:57 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_key_hook(int keycode, t_vars *vars)
{
	if (keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_UP || keycode == K_DOWN)
		ft_update(vars);
	if (vars->map->c[vars->map->player] == 'M' || keycode == K_ESCAPE)
		ft_clean_exit(vars);
	else if (keycode == K_LEFT)
		vars->steps += ft_move(vars, 'l');
	else if (keycode == K_RIGHT)
		vars->steps += ft_move(vars, 'r');
	else if (keycode == K_UP)
		vars->steps += ft_move(vars, 'u');
	else if (keycode == K_DOWN)
		vars->steps += ft_move(vars, 'd');
	ft_graphic_itoa(vars->steps, vars, 75);
	if (vars->map->c[vars->map->player] == 'C')
	{
		vars->map->nb_collect--;
		vars->map->c[vars->map->player] = '0';
	}
	if ((vars->map->c[vars->map->player] == 'E' && vars->map->nb_collect == 0)
		|| vars->map->c[vars->map->player] == 'M')
		ft_clean_exit(vars);
	return (0);
}

int	ft_move(t_vars *vars, char d)
{
	int	currenti;
	int	gotoi;

	currenti = vars->map->player;
	if (d == 'u')
		gotoi = currenti - vars->map->s->w;
	else if (d == 'd')
		gotoi = currenti + vars->map->s->w;
	else if (d == 'l')
		gotoi = currenti - 1;
	else if (d == 'r')
		gotoi = currenti + 1;
	else
		return (0);
	if (vars->map->c[gotoi] == '1')
		return (0);
	ft_putimage(vars, vars->map->bak->i, currenti);
	if (vars->map->c[currenti] == 'E')
		ft_putimage(vars, vars->map->exit->i, currenti);
	ft_putperso(vars, d, gotoi);
	vars->map->player = gotoi;
	return (1);
}

void	ft_putperso(t_vars *vars, char d, int i)
{
	if (d == 'u')
		ft_putimage(vars, vars->map->perso_u->i, i);
	else if (d == 'd')
		ft_putimage(vars, vars->map->perso_d->i, i);
	else if (d == 'l')
		ft_putimage(vars, vars->map->perso_l->i, i);
	else if (d == 'r')
		ft_putimage(vars, vars->map->perso_r->i, i);
}

static int	ft_itoa_nb_length(int n, int sign)
{
	int	pow;

	pow = 9;
	while (pow > 0)
	{
		if (sign == 1 && n >= ft_pow(10, pow))
		{
			return (pow + 1);
		}
		else if (sign == -1 && n <= ft_pow(10, pow) * -1)
		{
			return (pow + 2);
		}
		pow--;
	}
	if (sign == 1)
		return (1);
	else
		return (2);
}

void	ft_graphic_itoa(int n, t_vars *vars, int x)
{
	int		nblen;
	int		i;
	char	c[2];

	nblen = ft_itoa_nb_length(n, 1);
	x += nblen * 7;
	i = nblen;
	c[1] = '\0';
	ft_putimage(vars, vars->map->wall->i, 0);
	ft_putimage(vars, vars->map->wall->i, 2);
	ft_putimage(vars, vars->map->wall->i, 3);
	mlx_string_put(vars->mlx, vars->win, 30, 20, ft_trgb(M_GREEN), "Steps :");
	while (i > 0)
	{
		i--;
		c[0] = (n % 10) * 1 + '0';
		mlx_string_put(vars->mlx, vars->win, x, 20, ft_trgb(M_GREEN), c);
		x -= 7;
		n /= 10;
	}
}
