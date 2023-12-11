/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: looutbai <looutbai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:01:32 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/11 09:49:34 by looutbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>
#include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# define S 7
# define PD 1.57079632679
# define PI 3.14159265359
# define ANGLE 0.2
# endif
# define WMAP 1920
# define HMAP 1080
# define SCALE 50
# ifdef __APPLE__
#  define KY_LEFT 123
#  define KY_RIGHT 124
#  define KY_DOWN 125
#  define KY_UP 126
#  define KY_A 0
#  define KY_D 2
#  define KY_S 1
#  define KY_W 13
# endif
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// new
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	// int		width;
	// int		height;
}			t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// ***************

typedef struct s_map
{
	char	**fmap;
	char	*line;
	char	*ptr;
	char	**texture;
	char	**colors;
	char	**mini_map;
	char	**f_color;
	char	**c_color;
	size_t	len_nor;
	size_t	c_len_nor;
	size_t	j_nor;
	int		k_nor;
	int 	posx;
	int		posy;
	double i;
	char	*new_line;
	void	*init;
	void 	*win;
	void 	*image_map;
	double		x_p;
	double		y_p;
	int x_l;
	int y_l;
	int t_x;
	int t_y;
	float fov ;
	double		field_of_view;
	int move[3];
	char p_angle;
	double distance;
	char view;
	double height;
	double width;
	double x_s;
	double y_s;
	double w;
	 double distance_pro;
	 double wall_height_pro;
	 double flo;
	 double co_dis ;
	 double floor_x;
	 double floor_y;
	 double distance_floor;
	 double proj_flo_x;
	 double proj_flo_y;
	double ceil_x;
    double ceil_y;
	double distance_ceil;
	double proj_ceil_x;
	double proj_ceil_y;
	t_img img;
}			t_map;

void		exit_fail(void);
void		get_map(t_map *map, char **av);
char		*get_next_line(int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t l);
void		check_map(t_map *map);
void		check_texture(t_map *map);
void floor_casting(t_map *map);
void		map_pointer(t_map *map);
float		get_fov(t_map *map);
char		*ft_joinstr(char const *s1, char const *s2);
char		*ft_join(char const *s1, char const *s2);
void		ft_free(char **str);
void		check_map_length(t_map *map);
int			len_max(t_map *map);
void		check_i(t_map *map);
void		check_walls(t_map *map);
void		check_len_i(t_map *map);
void		check_len_j(t_map *map);
void		check_space_errors(t_map *map);
void		check_player(t_map *map);
size_t		ft_strlenn(char **ptr);
size_t		ft_strleen(char **ptr);
void		valid_texture(t_map *map);
void		error_print(char *str);
char		*ft_strttcpy(char *dest, char *src);
void		check_colors(t_map *map);
void		check_walls(t_map *map);
void		error_colors(t_map *map);
void		window(t_map *map);
int	count_lines(char **map);
char **drawing_map(t_map *map);
void cast_ray(double fov,t_map *map,int *x,int *y);
void	find_player_location(t_map *map);
void player_view(int *x,int *y,t_map *map);
int	key_press(int keycode, t_map *m);
void draw_player(t_map *map);
void right(t_map *map);
void left(t_map *map);
void move_for(t_map *map);
void move_back(t_map *map);
void move_right(t_map *map);
void move_left(t_map *map);
void draw_line(t_map *map);
void draw_player(t_map *map);
void rays(t_map *map);
void projection(t_map *map);
int draw(t_map *map);
int	key_press(int keycode, t_map *m);
void movement(t_map *m);
int key_release(int keycode, t_map *m);
void render_projected3d_wall(double distance,t_map *map,int height,char view);
char check_wall(double y_player, double x_player, double py, double px, t_map *map);
void cast_rays_3d(t_map *map,double angle , int x);
double distance(double start_x,double start_y,double x,double y);
void projection_3D(t_map *map);
void ceiling_casting(t_map *map);
void    project_ceil(t_map *map, double i, double top);

#endif 