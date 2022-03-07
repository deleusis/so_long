/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:39:40 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 18:18:55 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	exit_game(t_prog *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->height)
	{
		free(prog->map[i]);
		i++;
	}
	free(prog->map);
	exit(0);
}

int	key_press(int keycode, t_prog *prog)
{
	if (keycode == ESC)
		exit_game(prog);
	if (keycode == A)
		move_player(prog, -1, 0);
	if (keycode == S)
		move_player(prog, 0, 1);
	if (keycode == D)
		move_player(prog, 1, 0);
	if (keycode == W)
		move_player(prog, 0, -1);
	return (0);
}

void	check_map_name(char *map_name)
{
	size_t	size;

	size = ft_strlen(map_name);
	if (ft_strncmp(&map_name[size - 4], ".ber\0", 5))
		error("Incorrect map_name\n");
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	prog.steps = 1;
	prog.flag_enemy = 0;
	if (argc == 2)
	{
		check_map_name(argv[1]);
		prog.map = &argv[1];
		read_map(argv[1], &prog);
		check_all_map(&prog);
		prog.width = ft_strlen(prog.map[0]);
		prog.mlx_ptr = mlx_init();
		prog.win_ptr = mlx_new_window (prog.mlx_ptr, prog.width * 64,
				prog.height * 64, "Mushroom");
		init_image (&prog);
		put_image(&prog);
		mlx_hook(prog.win_ptr, 17, 1L << 0, exit_game, &prog);
		mlx_hook(prog.win_ptr, 02, 1L << 0, key_press, &prog);
		if (prog.flag_enemy)
			mlx_loop_hook(prog.mlx_ptr, counter, &prog);
		mlx_loop(prog.mlx_ptr);
		return (0);
	}
	write(1, "Invalid Arguments\n", 18);
	return (0);
}
