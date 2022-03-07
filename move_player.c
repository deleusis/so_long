/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:03:20 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 17:46:48 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_steps(t_prog *prog)
{
	char	*steps;

	steps = ft_itoa(prog->steps);
	ft_putnbr_fd(prog->steps, 1);
	write(1, "\n", 1);
	mlx_string_put(prog->mlx_ptr, prog->win_ptr, 86, 86, COLOR, "Steps - ");
	mlx_string_put(prog->mlx_ptr, prog->win_ptr, 166, 86, COLOR,
		steps);
	free(steps);
	prog->steps++;
}

void	player_pos(t_prog *prog)
{
	int	i;
	int	j;

	i = -1;
	while (prog->map[++i])
	{
		j = -1;
		while (prog->map[i][++j])
		{
			if (prog->map[i][j] == 'P')
			{
				prog->map[i][j] = '0';
				break ;
			}
		}
	}
	prog->map[prog->pos_y][prog->pos_x] = 'P';
}

void	move_player(t_prog *prog, int x, int y)
{
	if (prog->map[prog->pos_y + y][prog->pos_x + x] == '1')
		return ;
	else if (prog->map[prog->pos_y + y][prog->pos_x + x] == 'C')
	{
		prog->score++;
		prog->pos_x = prog->pos_x + x;
		prog->pos_y = prog->pos_y + y;
	}
	else if (prog->map[prog->pos_y + y][prog->pos_x + x] == 'E')
	{
		if (prog->collect == prog->score)
			exit_game(prog);
		else
			return ;
	}
	else if (prog->map[prog->pos_y + y][prog->pos_x + x] == 'H')
		exit_game(prog);
	else
	{
		prog->pos_x = prog->pos_x + x;
		prog->pos_y = prog->pos_y + y;
	}
	player_pos(prog);
	put_image(prog);
	count_steps(prog);
}

void	set_values(t_prog *prog)
{
	int	x;
	int	y;

	prog->collect = 0;
	prog->score = 0;
	y = -1;
	while (prog->map[++y])
	{
		x = -1;
		while (prog->map[y][++x])
		{
			if (prog->map[y][x] == 'P')
			{
				prog->pos_y = y;
				prog->pos_x = x;
			}
			if (prog->map[y][x] == 'C')
				prog->collect++;
		}
	}
}
