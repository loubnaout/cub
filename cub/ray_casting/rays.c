/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:28:19 by looutbai          #+#    #+#             */
/*   Updated: 2023/12/10 16:32:48 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	check_wall(double y_player, double x_player, double py, double px, t_map *map)
{
	double ppy = ((py / SCALE) + 1) ;
	double ppx = ((px / SCALE)) ;
	double ppyy = ((py / SCALE) - 1) ;
	double ppxx = ((px / SCALE)) ;

	if (y_player > py && x_player > px)
	{
		if ((int)(py + 1) % SCALE == 0 && map->mini_map[(int)((py / SCALE) + 1)] && map->mini_map[(int)(ppy)][(int)(ppx)] == '0')
			return ('N');
		else
			return ('W');
	}
	else if (y_player > py && x_player < px)
	{
		if ((int)(py + 1) % SCALE == 0 && map->mini_map[(int)((py / SCALE) + 1)] && map->mini_map[(int)(ppy)][(int)(ppx)] == '0')
			return ('N');
		else
			return ('E');
	}
	else if (y_player <= py && x_player <= px)
	{
		if ((int)(py) % SCALE == 0 && map->mini_map[(int)((py / SCALE) - 1)] && map->mini_map[(int)(ppyy)][(int)(ppxx)] == '0')
			return ('S');
		else
			return ('E');
	}
	else if (y_player <= py && x_player >= px)
	{
		if ((int)(py) % SCALE == 0 && map->mini_map[(int)((py / SCALE) - 1)] && map->mini_map[(int)(ppyy)][(int)(ppxx)] == '0')
			return ('S');
		else
			return ('W');
	}
	return (0);
}

void rays(t_map *map)
{
    double posx = map->x_p ;
    double posy = map->y_p ;
    char view = '\0';
    while(true)
    {
        if(map->mini_map[(int)((posy /SCALE))][(int)((posx /SCALE))] != '0')
        {
            view = check_wall(map->y_p,map->x_p,posy,posx,map);
            break;
        }
        posx += cos((map->fov)/ 180);
        posy += sin((map->fov)/ 180);
	}
	draw_line(map);
}

void projection(t_map *map)
{
    double i;
    double nb_rays;
    double fov = map->fov;

	map->fov -= 30 * 3.14 / 180;
    nb_rays = WMAP;
    while(i < nb_rays)
    {
        rays(map);
        i++;
		map->fov += ((60 * 3.14) / 180) / nb_rays;
    }
	map->fov = fov;
}