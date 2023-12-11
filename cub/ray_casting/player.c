/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:41:28 by looutbai          #+#    #+#             */
/*   Updated: 2023/12/10 15:58:51 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	find_player_location(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mini_map[i])
	{
		j = 0;
		while (map->mini_map[i][j])
		{
			if (map->mini_map[i][j] == 'W' || map->mini_map[i][j] == 'N' || map->mini_map[i][j] == 'E' || map->mini_map[i][j] == 'S')
			{
				map->x_p = j+0.5; //speed
				map->y_p = i+0.5;
                map->p_angle = map->mini_map[i][j];
                map->mini_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void draw_player(t_map *map)
{
    int centerX = (SCALE * map->x_p);
    int centerY = (SCALE * map->y_p);

    for (int l = centerY - 4 ; l < centerY + 5; l++) 
    {
        for (int k = centerX - 4; k < centerX + 5; k++) 
        {
                my_mlx_pixel_put(&map->img, k, l, 0x00FF0000);
        }
    }

}


void draw_line(t_map *map)
{
    double i = 0;
    double x = (SCALE * map->x_p);
    double y = (SCALE * map->y_p);
    double start_x = x;
    double start_y = y;
    double step_size = 1.0;
    while (i < 700)
    {
        if (map->mini_map[(int)(y / SCALE)][(int)(x / SCALE)] != '0')
        {
            map->distance = distance(start_x,start_y,x,y);
            break;
        }
        my_mlx_pixel_put(&map->img, x, y, 0x00FFFFFF);
        x += step_size * cos(map->fov) ;
        y += step_size * sin(map->fov) ;
        if (x < 0 || x >= WMAP|| y < 0 || y >= HMAP)
            break;
        i++;
    }
}

