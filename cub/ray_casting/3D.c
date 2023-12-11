/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:56:07 by looutbai          #+#    #+#             */
/*   Updated: 2023/12/11 10:06:57 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// void projection(t_map *map)
// {
//     double i;
//     double nb_rays;
//     double fov = map->fov;

// 	map->fov -= 30 * 3.14 / 180;
//     nb_rays = WMAP;
//     while(i < nb_rays)
//     {
//         rays(map);
//         i++;
// 		map->fov += ((60 * 3.14) / 180) / nb_rays;
//     }
// 	map->fov = fov;
// }
// void rays(t_map *map)
// {
//     double posx = map->x_p ;
//     double posy = map->y_p ;

//     char view = '\0';
//     while(true)
//     {
//         if(map->mini_map[(int)((posy /SCALE))][(int)((posx /SCALE))] != '0')
//         {
//             view = check_wall(map->y_p,map->x_p,posy,posx,map);
//             break;
//         }
//         posx += cos((map->fov)/ 180);
//         posy += sin((map->fov)/ 180);
// 	}
// 	draw_line(map);
// }
void projection_3D(t_map *map)
{
    double i = 0;
    double nb_rays;
    double fov = map->fov;

	map->fov -= 30 * (M_PI / 180);
    nb_rays = WMAP;
    while(i < nb_rays)
    {
        cast_rays_3d(map,map->fov,map->height); 
        i++;
		map->fov += ((60 * 3.14) / 180) / nb_rays;
    }
	map->fov = fov;
}

void draw_3D(t_map *map,int i,char view)
{
    if(map->p_angle == 'N') 
        my_mlx_pixel_put(&map->img,map->height,map->width,0x00CC99CC);  
    else if(map->p_angle == 'S')
        my_mlx_pixel_put(&map->img,map->height,map->width,0x00FF6666); 
    else if(map->p_angle == 'W')
        my_mlx_pixel_put(&map->img,map->height,map->width,0x00FF0099);   
    else if(map->p_angle == 'E')
        my_mlx_pixel_put(&map->img,map->height,map->width,0x00663366);
}

double distance(double start_x,double start_y,double x,double y)
{
    return(sqrt((x - start_x) * (x - start_x) + (y - start_y) * (y - start_y)));
}

void cast_rays_3d(t_map *map,double angle , int x)
{
    double px;
    double py;
    px = map->x_p;
    py = map->y_p;
    while(true)
    {
        map->x_s = (int)(px/SCALE);
        map->y_s = (int)(py/SCALE);
        if (map->mini_map[(int)map->y_s][(int)map->x_s] == '1' || map->mini_map[(int)(((py - (int)map->y_s) / SCALE))][(int)map->x_s] == '1' || map->mini_map[(int)map->y_s][(int)(((px - (int)map->x_s) / SCALE))] == '1')
		{
            map->distance = distance(map->x_p,map->y_p,px,py);
            map->view = check_wall(map->y_p,map->x_p,py,px,map);
            break;
        }
        px += cos((map->fov)/ 180);
        py += sin((map->fov)/ 180);

    }

    render_projected3d_wall(map->distance,map,map->height,map->fov);
}


void render_projected3d_wall(double distance,t_map *map,int height,char view)
{
    int i = 0;
    map->width = 0.0;
    map->distance_pro = (WMAP / 2.0) / tan((map->fov / 2.0)) ;
    printf("distance  = %f fov = %f\n",map->distance_pro, map->fov);
    printf(" = %d\n", WMAP);
   
    map->wall_height_pro = (SCALE / map->distance) * map->distance_pro;
    while(map->width < HMAP / 2 - map->wall_height_pro / 2 && map->width < HMAP)
    { 
        my_mlx_pixel_put(&map->img,height,map->width++,0x0099FFFF);
    }
    while(map->width < HMAP / 2 + map->wall_height_pro / 2 && map->width < HMAP)
    {
        my_mlx_pixel_put(&map->img,height,map->width++,0x00996600);
    }
    while(map->width < HMAP)
    { 
        my_mlx_pixel_put(&map->img,height,map->width++,0x00990066);
    }
}