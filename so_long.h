/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:01:08 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 18:12:28 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# define PLAYER "./assets/player.xpm"
# define COLLECTABLE "./assets/collectable.xpm"
# define WALL "./assets/wall.xpm"
# define GROUND "./assets/ground.xpm"
# define EXIT "./assets/exit.xpm"
# define ENEMY "./assets/hedgehog1.xpm"
# define ENEMY2 "./assets/hedgehog2.xpm"
# define ENEMY3 "./assets/hedgehog3.xpm"
# define ENEMY4 "./assets/hedgehog4.xpm"

# define COLOR 0x0000FF

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_img{
	void	*image;
	int		width;
	int		height;
}		t_img;

typedef struct s_prog{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		enemy_x;
	int		enemy_y;
	int		score;
	int		collect;
	int		steps;
	int		flag_enemy;
	t_img	ground;
	t_img	wall;
	t_img	player;
	t_img	collectable;
	t_img	exit;
	t_img	enemy;
}		t_prog;
int		exit_game(t_prog *prog);
void	check_map_name(char *map_name);
void	check_all_map(t_prog *prog);
void	check_symbols(t_prog *prog);
int		key_press(int keycode, t_prog *prog);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	read_map(char *map_name, t_prog *prog);
void	set_values(t_prog *prog);
void	init_map(char *map_name, t_prog *prog);
char	*get_next_line(int fd);
int		init_image(t_prog *prog);
int		put_image(t_prog *prog);
void	put_image1(t_prog *prog, int x, int y);
void	move_player(t_prog *prog, int x, int y);
void	player_pos(t_prog *prog);
void	count_steps(t_prog *prog);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char *s1, char *set);
void	error(char *str);
int		counter(t_prog *prog);
int		move_enemy(t_prog *prog);
void	set_enemy_pos(t_prog *prog, int x, int y);
void	draw_enemy(t_prog *prog, char *steps, char *path);
void	enemy_pos(t_prog *prog);

#endif