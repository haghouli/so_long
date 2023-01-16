/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:29:35 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/10 05:48:21 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	key_handler(int key, t_data *data)
{
	int static	counter;
	int static	c;

	counter = count_collectors(data);
	if (key == 53)
		exit(0);
	if (key == 13)
		return (move_vertical_bonus(data, &counter, &c, -1));
	else if (key == 1)
		return (move_vertical_bonus(data, &counter, &c, 1));
	else if (key == 0)
		return (move_horizontal_bonus(data, &counter, &c, -1));
	else if (key == 2)
		return (move_horizontal_bonus(data, &counter, &c, 1));
	return (1);
}

static void	fill_images(t_data *data)
{
	int	i;

	data->imgs->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall1.xpm",
			&i, &i);
	data->imgs->pers = mlx_xpm_file_to_image(data->mlx, "./textures/pers.xpm",
			&i, &i);
	data->imgs->collect = mlx_xpm_file_to_image(data->mlx,
			"./textures/coll.xpm", &i, &i);
	data->imgs->back = mlx_xpm_file_to_image(data->mlx, "./textures/black.xpm",
			&i, &i);
	data->imgs->door = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&i, &i);
	data->imgs->board = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm",
			&i, &i);
	data->imgs->enemy = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemyy-_1_.xpm", &i, &i);
	if (!data->imgs->wall || !data->imgs->pers || !data->imgs->collect
		||!data->imgs->back || !data->imgs->door || !data->imgs->board
		|| !data->imgs->enemy)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

static int	check_errors(t_data *data)
{
	if (data->graph == NULL || is_map_error(data->graph)
		|| !check_elements_count(data->graph)
		|| check_elements_bonus(data->graph)
		|| !check_near_enemy(data))
		return (0);
	if (check_stuck(data->graph, &((t_dim){ft_strlen(data->graph[0]),
				count_col(data->graph)}),
		&((t_dim){data->dim->y, data->dim->x}))
				!= (count_collectors(data) + 1))
		return (ft_printf("there no valid path valid path in the map.\n"), 0);
	return (1);
}

static void	create_win(t_data *data)
{
	int	width;
	int	height;

	width = 60 * ft_strlen(data->graph[0]);
	height = 60 * count_col(data->graph);
	data->mlx = mlx_init();
	fill_images(data);
	data->mlx_win = mlx_new_window(data->mlx, width, height, "so long");
	create_map_bonus(data);
	data->counter = 0;
	mlx_hook(data->mlx_win, 2, 0, key_handler, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop_hook(data->mlx, animation, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char *av[])
{
	int		fd;
	t_data	*data;

	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0 || !check_extention(av[1]))
	{
		ft_printf("Error\n");
		return (0);
	}
	data = malloc(sizeof(t_data));
	data->dim = malloc(sizeof(t_dim));
	data->imgs = malloc(sizeof(t_img));
	data->graph = read_file(fd);
	get_enemies_location(data);
	get_start_dim(data);
	if (!check_errors(data))
		return (0);
	else
		create_win(data);
	return (0);
}
