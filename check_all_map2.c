/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:12:42 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 18:16:10 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_symbols_enemy(t_prog *prog)
{
	int	i;
	int	j;

	i = -1;
	while (prog->map[++i])
	{
		j = -1;
		while (prog->map[i][++j] != '\0')
		{
			if (prog->map[i][j] == 'H')
			{
				prog->flag_enemy = 1;
				prog->enemy_y = i;
				prog->enemy_x = j;
			}
		}
	}
}

static void	count_symbols(t_prog *prog, int *players, int *colls, int *exits)
{
	int	i;
	int	j;

	i = -1;
	*players = 0;
	*colls = 0;
	*exits = 0;
	while (prog->map[++i])
	{
		j = -1;
		while (prog->map[i][++j] != '\0')
		{
			if (prog->map[i][j] == 'P')
				(*players)++;
			if (prog->map[i][j] == 'C')
				(*colls)++;
			if (prog->map[i][j] == 'E')
				(*exits)++;
			count_symbols_enemy(prog);
		}
	}
}

void	check_symbols(t_prog *prog)
{
	int	i;
	int	j;
	int	players;
	int	colls;
	int	exits;

	j = 0;
	count_symbols(prog, &players, &colls, &exits);
	while (prog->map[j])
	{
		i = 0;
		while (prog->map[j][i] != '\0')
		{
			if (prog->map[j][i] == 'P' || prog->map[j][i] == 'E'
					|| prog->map[j][i] == '1' || prog->map[j][i] == 'C'
					|| prog->map[j][i] == '0' || prog->map[j][i] == 'H')
				i++;
			else
				error("Error\nInvalid symbol\n");
		}
		j++;
	}
	if (players != 1 || colls < 1 || exits != 1)
		error("Error\nInvalid number of spec symbols\n");
}
