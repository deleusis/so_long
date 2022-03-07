/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:03:05 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 18:05:36 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_rectangular(t_prog *prog)
{
	int		i;

	i = 1;
	prog->width = ft_strlen(prog->map[0]);
	while (prog->map[i])
	{
		if (ft_strlen(prog->map[i]) != prog->width)
			error("Error\nMap is not rectangular\n");
		i++;
	}
}

void	check_walls(t_prog *prog)
{
	int	i;
	int	x;
	int	y;

	prog->height = i;
	x = 0;
	while (x < prog->width)
	{
		if (prog->map[0][x] != '1' || prog->map[prog->height - 1][x] != '1')
			error("Error\nWalls error\n");
		x++;
	}	
	y = 0;
	while (y < prog->height)
	{
		if (prog->map[y][0] != '1' || prog->map[y][prog->width - 1] != '1')
			error("Error\nWalls error\n");
		y++;
	}
}

void	check_all_map(t_prog *prog)
{
	check_map_rectangular(prog);
	check_walls(prog);
	check_symbols(prog);
	set_values(prog);
}
