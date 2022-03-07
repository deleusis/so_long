/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:03:35 by deleusis          #+#    #+#             */
/*   Updated: 2022/03/03 18:16:44 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map_name, t_prog *prog)
{
	int		fd;
	int		i;
	char	*str;
	char	*str2;

	str2 = "init";
	i = 0;
	init_map (map_name, prog);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("Error to open\n");
	while (str2)
	{
		str = get_next_line(fd);
		str2 = ft_strtrim(str, "\n");
		prog->map[i] = str2;
		i++;
		free(str);
	}
	close(fd);
}

void	init_map(char *map_name, t_prog *prog)
{
	int		fd;
	int		i;
	char	*str;

	str = "init";
	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("Error to open\n");
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		i++;
	}
	prog->map = malloc(sizeof(char *) * (i + 1));
	if (!prog->map)
		error("Malloc error\n");
	prog->height = i;
	close(fd);
}
