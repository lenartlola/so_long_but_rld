/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:32:55 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/08 10:32:55 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_update(t_vars *vars)
{
	int	i;

	vars->collect_turn++;
	i = 0;
	while (i < (int)ft_strlen(vars->map->c))
	{
		if (vars->map->c[i] == 'C')
		{
			ft_putimage(vars, vars->map->bak->i, i);
			if (vars->collect_turn % 4 == 0)
				ft_putimage(vars, vars->map->coin_f->i, i);
			else if (vars->collect_turn % 2 == 1)
				ft_putimage(vars, vars->map->coin_d->i, i);
			else if (vars->collect_turn % 4 == 2)
				ft_putimage(vars, vars->map->coin_p->i, i);
		}
		i++;
	}
	ft_update_enemies(vars);
}


void	ft_update_enemies(t_vars *vars)
{
	int	i;
	int	testi;

	vars->enemy_turn++;
	i = 0;
	if (SMART == 1)
		printf("%s\n", g_input);
	while (i < (int)ft_strlen(vars->map->c))
	{
		if (vars->enemy_turn % 8 < 4)
			testi = i + 1;
		else
			testi = i - 1;
		if (vars->map->c[i] == 'M' && vars->map->c[testi] == '0')
		{
			vars->map->c[i] = '0';
			vars->map->c[testi] = 'M';
			ft_putimage(vars, vars->map->bak->i, i);
			ft_putimage(vars, vars->map->enemy->i, testi);
			if (vars->enemy_turn % 8 < 4)
				i++;
		}
		i++;
	}

}
