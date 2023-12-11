/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:11:32 by looutbai          #+#    #+#             */
/*   Updated: 2023/12/04 15:54:25 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float get_fov(t_map *map)
{
	if (map->p_angle == 'N')
		return ((3 * M_PI) / 2);
	else if (map->p_angle == 'S')
		return (M_PI / 2);
	else if (map->p_angle == 'E')
		return (0);
	else if (map->p_angle == 'W')
		return (M_PI);		
	else
		return (-1);
}

void right(t_map *map)
{
	double p_x;
	double p_y;
	p_x = cos(map->fov);
	p_y = sin(map->fov);
	if (map->mini_map[(int)(map->y_p )][(int)(map->x_p + p_x)] != '1')
		map->x_p += p_x;
}

void left(t_map *map)
{
	double p_x;
	double p_y;
	p_x = cos(map->fov);
	p_y = sin(map->fov);
	if (map->mini_map[(int)(map->y_p )][(int)(map->x_p - p_x)] != '1')
		map->x_p -= p_x;
}

void up(t_map *map)
{
	map->fov -= 0.5;
}
void down(t_map *map)
{
	map->fov += 0.5;
}

void move_right(t_map *map)
{
	map->fov += 0.5;
	if (map->fov > 2 * M_PI)
		map->fov = 0;
	else if (map->fov < 0)
		map->fov += 2 * M_PI;
}

void move_left(t_map *map)
{
	map->fov -= 0.5;
	if (map->fov > 2 * M_PI)
		map->fov = 0;
	else if (map->fov < 0)
		map->fov += 2 * M_PI;
}
void move_for(t_map *map)
{
	double p_x;
	double p_y;
	p_x = cos(map->fov);
	p_y = sin(map->fov);
	if (map->mini_map[(int)((map->y_p + p_y) )][(int)(map->x_p)] != '1')
		map->y_p += p_y;
}

void move_back(t_map *map)
{
	double p_x;
	double p_y;
	p_x = cos(map->fov);
	p_y = sin(map->fov);
	if (map->mini_map[(int)((map->y_p - p_y)) ][(int)(map->x_p)] != '1')
		map->y_p -= p_y;
}

void movement(t_map *m)
{
	if (m->move[0] == KY_UP || m->move[0] == KY_W)
		move_for(m);
	if (m->move[0] == KY_DOWN || m->move[0] == KY_S)
		move_back(m);

	if (m->move[1] == KY_D)
		right(m);
	if (m->move[1] == KY_A)
		left(m);

	if (m->move[2] == KY_RIGHT)
		move_right(m);
	if (m->move[2] == KY_LEFT)
		move_left(m);
}

int key_press(int keycode, t_map *m)
{
	if (keycode == KY_UP || keycode == KY_W)
		m->move[0] = keycode;
	else if (keycode == KY_DOWN || keycode == KY_S)
		m->move[0] = keycode;

	if (keycode == KY_D)
		m->move[1] = keycode;
	else if (keycode == KY_A)
		m->move[1] = keycode;

	if (keycode == KY_RIGHT)
		m->move[2] = keycode;
	else if (keycode == KY_LEFT)
		m->move[2] = keycode;
	return (0);
}

int key_release(int keycode, t_map *m)
{
	if (keycode == KY_UP || keycode == KY_W)
		m->move[0] = -1;
	else if (keycode == KY_DOWN || keycode == KY_S)
		m->move[0] = -1;

	if (keycode == KY_D)
		m->move[1] = -1;
	else if (keycode == KY_A)
		m->move[1] = -1;

	if (keycode == KY_RIGHT)
		m->move[2] = -1;
	else if (keycode == KY_LEFT)
		m->move[2] = -1;
	return 0;
}