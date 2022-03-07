/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:29:13 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 18:21:42 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_prog *prog, char *steps, char *path)
{
	prog->enemy.image = mlx_xpm_file_to_image (prog->mlx_ptr, path,
			&prog->enemy.width, &prog->enemy.height);
	put_image(prog);
	mlx_string_put(prog->mlx_ptr, prog->win_ptr, 86, 86, COLOR, "Steps - ");
	mlx_string_put(prog->mlx_ptr, prog->win_ptr, 166, 86, COLOR, steps);
}	

int	counter(t_prog *prog)
{
	static int			g;
	char				*steps;

	steps = ft_itoa(prog->steps);
	g++;
	move_enemy(prog);
	if (g == 1000)
		draw_enemy(prog, steps, ENEMY);
	if (g == 2000)
		draw_enemy(prog, steps, ENEMY2);
	if (g == 3000)
		draw_enemy(prog, steps, ENEMY3);
	if (g == 4000)
		draw_enemy(prog, steps, ENEMY4);
	if (g > 5000)
		g = 0;
	free(steps);
	return (0);
}

void	enemy_pos(t_prog *prog)
{
	int	i;
	int	j;

	i = -1;
	while (prog->map[++i])
	{
		j = -1;
		while (prog->map[i][++j])
		{
			if (prog->map[i][j] == 'H')
			{
				prog->map[i][j] = '0';
				break ;
			}
		}
	}
	prog->map[prog->enemy_y][prog->enemy_x] = 'H';
}

void	set_enemy_pos(t_prog *prog, int x, int y)
{
	if (prog->map[prog->enemy_y][prog->enemy_x + x] == '1')
		return ;
	else if (prog->map[prog->enemy_y][prog->enemy_x + x] == 'C')
		return ;
	else if (prog->map[prog->enemy_y][prog->enemy_x + x] == 'E')
		return ;
	else if (prog->map[prog->enemy_y][prog->enemy_x + x] == 'P')
		exit_game(prog);
	else
	{
		prog->enemy_x = prog->enemy_x + x;
		prog->enemy_y = prog->enemy_y + y;
	}
	enemy_pos(prog);
	put_image(prog);
}

int	move_enemy(t_prog *prog)
{
	static int	g;

	g++;
	if (g == 1000)
		set_enemy_pos(prog, -1, 0);
	if (g == 2000)
		set_enemy_pos(prog, -1, 0);
	if (g == 3000)
		set_enemy_pos(prog, 1, 0);
	if (g == 4000)
		set_enemy_pos(prog, 1, 0);
	if (g > 5000)
		g = 0;
	return (0);
}
