/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:37:33 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:53:19 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define BUFFER_SIZE 32
# define MVAL 10
# define MAPVAL "12NSEW"
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_cfg
{
	int				screen_w;
	int				screen_h;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	int				floor;
	int				sky;
	int				err;
	char			**map;
	t_list			*map_lst;
	int				map_emptystr;
	int				map_width;
	int				map_height;
	int				save;
}					t_cfg;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line;
	int				endian;
}					t_img;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
	double			sprite_x;
	double			sprite_y;
	double			tr_x;
	double			tr_y;
	int				scr_x;
	int				width;
	int				height;
	int				start_x;
	int				end_x;
	int				start_y;
	int				end_y;
	struct s_sprite	*next;
}					t_spr;

typedef struct		s_tex
{
	void			*img;
	int				*addr;
	char			*path;
	int				w;
	int				h;
	int				bpp;
	int				line;
	int				endian;
	int				height;
	double			step;
}					t_tex;

typedef struct		s_cub
{
	void			*mlx;
	void			*win;

	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			ray_x;
	double			ray_y;
	int				map_x;
	int				map_y;
	double			side_x;
	double			side_y;
	int				sprite_cnt;
	double			d_x;
	double			d_y;
	double			dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			speed;
	double			rotate;
	double			dist_arr[MAX_WIDTH];

	t_img			*img;
	t_tex			*tex[5];
	t_spr			*sprite;
	t_cfg			cfg;
}					t_cub;

char				**ft_split(char const *s, char c);
char				**str_split(char const *s, char c);
void				plus_args(size_t *i, size_t *len);
char				**free_res(char **res);
int					count_elem(char const *s, char c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);

int					get_next_line(int fd, char **line);
int					check_n(char *tail);
int					normal_call(char **line, char **tail);
int					last_call(char **line, char **tail);
int					gnl_len(const char *s);
char				*gnl_substr(const char *s, int start, int len);
char				*gnl_strjoin(char *tail, char *buf);
char				*make_line(char *tail);
char				*cut_tail(char *tail);

void				parse_cfg(t_cfg *cfg, int ac, char **av);
int					read_conf(t_cfg *cfg, char *av);
int					copy_map(t_cfg *cfg);
int					fill_spaces(t_cfg *cfg, int i, int j);
void				clear_map_list(t_list **begin_list);
void				init_conf(t_cfg *cfg);
void				add_param(t_cfg *cfg, char *line);
int					get_sprite_path(t_cfg *cfg, char *line);
int					get_tex_path(t_cfg *cfg, char *line, int start);
int					check_color_string(char ch);
int					cnt_char(char const *s, char c);
int					get_color(t_cfg *cfg, char *line, int i);
int					check_one_color(char *str);
int					get_one_color(t_cfg *cfg, char *str);
int					check_premap(t_cfg *cfg);
int					is_map_string(char *line);
int					check_map_string(char *line);
void				add_map_str(t_cfg *cfg, char *line);
void				map_to_arr(t_cfg *cfg);
int					check_string(t_cfg *cfg, int i, int j);
int					check_string_back(t_cfg *cfg);
int					check_column(t_cfg *cfg, int str, int col);
int					check_column_back(t_cfg *cfg);
int					check_map(t_cfg *cfg);
int					check_double_player(t_cfg *cfg, int i, int j);
int					check_space_around(t_cfg *cfg, int i, int j);
char				*make_spaces(int amount, t_cfg *cfg);
void				get_map_size(t_cfg *cfg);
int					check_path(t_cfg *cfg);
void				check_screen(t_cfg *cfg);
int					get_screen_size(t_cfg *cfg, char *line);
int					cnt_elem(char const *s, char c);
void				free_params(char **tmp);
int					ret_err(t_cfg *cfg);
int					ret_err_free(t_cfg *cfg, char **tmp);

void				draw_screen(t_cub *cub, int x);
void				get_wall_height(t_cub *cub, int x);
void				get_wall_dist(t_cub *cub);
void				get_dda_step(t_cub *cub);
t_img				*init_img(t_cub *cub);
t_tex				*init_tex(t_cub *cub, char *path);
void				initlist(t_cub *cub, t_cfg *cfg);
void				spr_add_back(t_cub *cub, t_spr *new);
t_spr				*new_spr(t_cub *cub, double coord_x, double coord_y);
void				read_map_obj(t_cub *cub, int i, int j);
void				get_sprite_distance(t_cub *cub);
void				swap_sprites(t_spr *a, t_spr *b);
void				sort_sprites(t_cub *cub);
void				read_textures(t_cub *cub);
void				load_texture(t_cub *cub, t_cfg *cfg);
void				my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void				init_player_ns(t_cub *cub, char ch, int x, int y);
void				init_player_we(t_cub *cub, char ch, int x, int y);
int					seek_end(char *str, char *tail);
int					seekchar(char *str, char c);
int					mouse_handler(t_cub *cub);
int					key_handler(int key, t_cub *cub);
void				move_forward(t_cub *cub);
void				move_backward(t_cub *cub);
void				move_left(t_cub *cub);
void				move_right(t_cub *cub);
void				rotate_ccw(t_cub *cub);
void				rotate_cw(t_cub *cub);
int					get_tex_x(t_cub *cub, int side);
double				get_texture_position(t_cub *cub, int side, int start);
void				texcast(t_cub *cub, int x, int start, int end);
int					get_tex_index(t_cub *cub);
void				get_sprite_params(t_cub *cub, t_spr *tmp);
int					is_column_visible(t_cub *cub, t_spr *tmp, int col);
void				draw_sprite_column(t_cub *cub, t_spr *tmp, int col);
void				draw_sprite(t_cub *cub);
void				write_bmp_image(t_cub *cub, int fd);
void				write_bmp_info(t_cub *cub, int fd);
void				write_bmp(t_cub *cub);
void				clean_cfg(t_cfg *cfg);
int					cfg_exit(t_cfg *cfg, int code);
int					proc_exit(t_cub *cub, int code);
void				get_error_code(int code);

#endif
