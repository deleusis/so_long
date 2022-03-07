/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:16 by deleusis          #+#    #+#             */
/*   Updated: 2022/02/26 19:30:16 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_image(t_prog *prog)
{
	prog->wall.image = mlx_xpm_file_to_image(prog->mlx_ptr, WALL,
			&prog->wall.width, &prog->wall.height);
	prog->ground.image = mlx_xpm_file_to_image (prog->mlx_ptr, GROUND,
			&prog->ground.width, &prog->ground.height);
	prog->player.image = mlx_xpm_file_to_image (prog->mlx_ptr, PLAYER,
			&prog->player.width, &prog->player.height);
	prog->collectable.image = mlx_xpm_file_to_image (prog->mlx_ptr, COLLECTABLE,
			&prog->collectable.width, &prog->collectable.height);
	prog->exit.image = mlx_xpm_file_to_image (prog->mlx_ptr, EXIT,
			&prog->exit.width, &prog->exit.height);
	prog->enemy.image = mlx_xpm_file_to_image (prog->mlx_ptr, ENEMY,
			&prog->enemy.width, &prog->enemy.height);
	return (0);
}

int	put_image(t_prog *prog)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(prog->mlx_ptr, prog->win_ptr);
	while (prog->map[++y])
	{
		x = -1;
		while (prog->map[y][++x])
			put_image1(prog, x, y);
	}
	return (0);
}

void	put_image1(t_prog *prog, int x, int y)
{
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
		prog->ground.image, x * 64, y * 64);
	if (prog->map[y][x] == '1')
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->wall.image, x * 64, y * 64);
	else if (prog->map[y][x] == '0')
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->ground.image, x * 64, y * 64);
	else if (prog->map[y][x] == 'P')
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->player.image, x * 64, y * 64);
	else if (prog->map[y][x] == 'E')
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->exit.image, x * 64, y * 64);
	else if (prog->map[y][x] == 'C')
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->collectable.image, x * 64, y * 64);
	else if (prog->map[y][x] == 'H')
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->enemy.image, x * 64, y * 64);
}
