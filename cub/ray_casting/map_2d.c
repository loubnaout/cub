/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:43 by looutbai          #+#    #+#             */
/*   Updated: 2023/12/10 11:38:24 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

    if (x < 0 || x >= WMAP || y < 0 || y >= HMAP)
        return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void cell(t_map *map, int x, int y)
{
    for (int l = SCALE * y; l < SCALE * (y + 1); l++)
    {
        for (int k = SCALE * x; k < SCALE * (x + 1); k++)
        {
            if (map->mini_map[y][x] == '1')
                my_mlx_pixel_put(&map->img, k, l, 0x00006633);
            else if (map->mini_map[y][x] == '0')
                my_mlx_pixel_put(&map->img, k, l, 0x00CCCC99);
            else if (map->mini_map[y][x] == ' ')
                my_mlx_pixel_put(&map->img, k, l, 0x00000000);
        }
    }
}

char **drawing_map(t_map *map)
{
    for (int y = 0; y < count_lines(map->mini_map); y++)
    {
        for (size_t x = 0; x < map->len_nor; x++)
        {
            cell(map, x, y);
        }
    }
    return map->mini_map;
}
