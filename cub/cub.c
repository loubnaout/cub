/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:01:14 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/10 16:50:48 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int destr(int keycode, t_map *m)
{
	if (keycode == 53)
	{
		mlx_destroy_window(m->init, m->win);
		exit(0);
	}
	return 0;
}

void exit_fail(void)
{
	printf("error\n");
	exit(1);
}

void get_map(t_map *map, char **av)
{
	int fd;
	char *tmp;

	fd = open(av[1], O_RDWR);
	if (ft_strncmp(av[1], ".cub", ft_strlen(av[1] - 4)) == 1 || fd < 0)
		exit_fail();
	map->line = get_next_line(fd);
	map->ptr = NULL;
	while (map->line != NULL)
	{
		tmp = ft_strjoin(map->ptr, map->line);
		if (map->ptr != NULL)
			free(map->ptr);
		map->ptr = tmp;
		free(map->line);
		map->line = get_next_line(fd);
	}
	check_map(map);
}

void mlx_clear_image(t_map *map)
{
	for (size_t i = 0; i < WMAP; i++)
	{
		for (size_t j = 0; j < HMAP; j++)
		{
			my_mlx_pixel_put(&map->img, i, j, 0x00000000);
		}
	}
}

int draw(t_map *map)
{
	// mlx_clear_image(map);
	// drawing_map(map);
	// draw_player(map);
	// draw_line(map);
	// movement(map);
	// projection(map);
	projection_3D(map);
	
	mlx_put_image_to_window(map->init, map->win, map->img.img, 0, 0);
	return 0;
}

void action(t_map *map)
{
	mlx_hook(map->win, ON_KEYDOWN, 0, key_press, map);
	mlx_hook(map->win, ON_KEYUP, 0, key_release, map);

	mlx_hook(map->win, 57, 0, destr, map);
	mlx_hook(map->win, ON_DESTROY, 0, destr, map);
	mlx_loop_hook(map->init, draw, map);
	mlx_loop(map->init);
}

void window(t_map *map)
{

	map->init = mlx_init();
	map->win = mlx_new_window(map->init, WMAP, HMAP, "cub3D");

	map->img.img = mlx_new_image(map->init, WMAP, HMAP);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.size_line, &map->img.endian);
	mlx_put_image_to_window(map->init, map->win, map->img.img, 0, 0);
}

void init_all_var(t_map *map)
{
	map->fov = get_fov(map);
	for (size_t i = 0; i < 3; i++)
		map->move[i] = -1;
}

int main(int ac, char **av)
{
	t_map map;
	
	if (ac == 2)
		get_map(&map, av);

	else
		printf("error args \n");
	find_player_location(&map);
	window(&map);
	init_all_var(&map);
	action(&map);
}

void ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
