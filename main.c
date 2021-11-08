/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:30:40 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/05 18:10:57 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(vars->map->c))
	{
		ft_putimage(vars, vars->map->bak->i, i);
		if (vars->map->c[i] == '1')
			ft_putimage(vars, vars->map->wall->i, i);
		else if (vars->map->c[i] == 'C')
			ft_putimage(vars, vars->map->coin_f->i, i);
		else if (vars->map->c[i] == 'M')
			ft_putimage(vars, vars->map->enemy->i, i);
		else if (vars->map->c[i] == 'E')
			ft_putimage(vars, vars->map->exit->i, i);
		else if (vars->map->c[i] == 'P')
			ft_putperso(vars, 'r', i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || ft_strlen(argv[1]) <= 0)
		return (printf("Error\nInput error\n"));
	vars.steps = 0;
	vars.collect_turn = 0;
	vars.enemy_turn = 0;
	vars.mlx = mlx_init();
	vars.map = ft_create_map(argv[1], &vars);
	if (!vars.map)
		return (printf("Error\nMap error\n"));
	vars.s = ft_new_size(vars.map->s->w * vars.map->bak->s->w,
			vars.map->s->h * vars.map->bak->s->h);
	vars.win = mlx_new_window(vars.mlx, vars.s->w, vars.s->h, "mlx 42");
	ft_draw_map(&vars);
	mlx_key_hook(vars.win, ft_mlx_key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, ft_mlx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
