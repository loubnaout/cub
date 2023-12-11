/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:18 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/27 14:24:16 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	f_color_check(t_map *map)
{
	char	*f_color;
	int		i;

	f_color = NULL;
	f_color = ft_strjoin(f_color, map->colors[1]);
	map->f_color = ft_split(f_color, ',');
	free(f_color);
	i = 0;
	while (map->f_color[i])
	{
		if (ft_atoi(map->f_color[i]) > 255)
		{
			printf("f_color error !\n");
		}
		i++;
	}
}

void	error_colors(t_map *map)
{
	int		i;
	char	*c_color;

	i = 0;
	c_color = NULL;
	c_color = ft_strjoin(c_color, map->colors[3]);
	map->c_color = ft_split(c_color, ',');
	free(c_color);
	while (map->c_color[i])
	{
		if (ft_atoi(map->c_color[i]) > 255)
		{
			printf("c_color error !\n");
		}
		i++;
	}
	f_color_check(map);
}

int	len_max(t_map *map)
{
	int	i;
	int	len_max;
	int	c_len;

	i = 0;
	len_max = 0;
	c_len = 0;
	while (map->mini_map[i])
	{
		c_len = ft_strlen(map->mini_map[i]);
		if (c_len > len_max)
		{
			len_max = c_len;
		}
		i++;
	}
	return (len_max);
}

int count_lines(char **map)
{
    int lines = 0;
    while (*map != NULL)
    {
        lines++;
        map++;
    }
    return lines;
}
void	check_map_length(t_map *map)
{
	map->k_nor = 0;
	map->len_nor = len_max(map);
	while (map->mini_map[map->k_nor])
	{
		map->c_len_nor = ft_strlen(map->mini_map[map->k_nor]);
		if (map->c_len_nor < map->len_nor)
		{
			map->new_line = (char *)malloc(map->len_nor + 1);
			if (map->new_line)
			{
				ft_strttcpy(map->new_line, map->mini_map[map->k_nor]);
				map->j_nor = map->c_len_nor;
				while (map->j_nor < map->len_nor)
				{
					map->new_line[map->j_nor] = ' ';
					map->j_nor++;
				}
				map->new_line[map->len_nor] = '\0';
				free(map->mini_map[map->k_nor]);
				map->mini_map[map->k_nor] = map->new_line;
			}
		}
		map->k_nor++;
	}
}
