/*
* Created: 2020/10/27 17:21:07
*/

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define DISPLAY_X 1920
# define DISPLAY_Y 1080

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define K_ESC 53
# define KEY_ARROW_W 126
# define KEY_ARROW_A 124
# define KEY_ARROW_D 123
# define KEY_ARROW_S 125
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define KEY " RNSWECF1\t\n"
# define KEY_KEY "RNSWECF"
# define MAP_IN "02WNSE"
# define MAP_INI "102WNSE"

typedef struct				s_spr
{
	double					dist;
	double					x;
	double					y;
}							t_spr;

typedef struct				s_picture
{
	int						width;
	int						height;
	int						*data;
	int						bpp;
	int						len_pct;
	int						end_pct;
	void					*img;
}							t_picture;

typedef struct				s_sprite_ray
{
	int						width;
	int						height;
	int						ray_strt_x;
	int						ray_strt_y;
	int						ray_end_x;
	int						ray_end_y;
	int						tex_x;
	int						tex_y;
	int						scrn_x;
	int						scrn_mv;
	double					x;
	double					y;
	double					trans_x;
	double					trans_y;
	double					invers;
}							t_sprite_ray;

typedef struct				s_ray
{
	int						map_x;
	int						map_y;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
	int						line_height;
	int						draw_start;
	int						draw_end;
	int						tex_num;
	int						tex_x;
	int						tex_y;
	double					dir_x;
	double					dir_y;
	double					camera_x;
	double					delta_dist_x;
	double					delta_dist_y;
	double					side_dist_x;
	double					side_dist_y;
	double					pw_dist;
	double					wall_x;
	double					step;
	double					tex_pos;
}							t_ray;

typedef struct				s_player
{
	double					x;
	double					y;
	double					dir_x;
	double					dir_y;
	double					follow_x;
	double					follow_y;
	double					speed_m;
	double					speed_r;
}							t_plr;

typedef struct				s_info
{
	char					*so_tex_inf;
	char					*we_tex_inf;
	char					*no_tex_inf;
	char					*ea_tex_inf;
	char					*spr_tex_inf;
	int						**buf;
	int						fd;
	int						width;
	int						height;
	char					**map;
	int						dir;
	void					*mlx;
	void					*win;
	int						**txtr;
	int						map_w;
	int						map_h;
	int						f_clr;
	int						c_clr;
	int						inf_spr;
	double					*inf_buf;
	t_picture				img;
	t_plr					player;
	t_ray					ray;
	t_sprite_ray			s_ray;
	t_spr					*sprite;
}							t_all_info;

int							ft_bmp(t_all_info *all);
void						ft_wall_txt(t_plr *plr, t_ray *r);
void						ft_wall_clr(t_all_info *all, t_ray *r, int x);
int							ft_exit(int i);
void						ft_free(void *str);
int							ft_finish(t_all_info *all);
int							get_next_line(int fd, char **line);
int							ft_texture(t_all_info *all);
void						ft_up_down(t_all_info *all, t_plr *plr,\
										double speed_m);
void						ft_left_right(t_all_info *all, t_plr *plr,\
											double speed_m);
int							ft_keyboard(int key, t_all_info *all);
void						ft_split_screen(t_all_info *all);
void						ft_raycasting(t_all_info *all);
void						ft_raycasting_spr(t_all_info *all, t_plr *plr);
int							ft_all_ray(t_all_info *all);
int							ft_parse(t_all_info *all, t_list *lst);
int							ft_new_lists(t_all_info *all, char *str);
int							ft_fill(t_all_info *all, t_list *lst);
int							ft_process_fill(t_all_info *all, int n,\
											int *len, char *l);
int							ft_middle(t_all_info *all, int n, int m,\
										int len);
int							ft_valid(t_all_info *all);
int							ft_digit(char *str);
int							ft_atoi_rx(t_all_info *all, const char *str);
int							ft_atoi_ry(t_all_info *all, const char *str);
int							ft_ln_screen(t_all_info *all, char *str);
int							ft_ln_txtr(t_all_info *all, char *str);
int							ft_enter_color(char *range0, char *range1,\
											char *range2);
int							ft_clr(char **range);
int							ft_color_f(t_all_info *all, char *str);
int							ft_sign3(char *str);
int							ft_sign(char *str);
int							ft_color_c(t_all_info *all, char *str);
int							ft_all_parser(t_all_info *all, char *path);
void						ft_first_ray(t_all_info *all, t_plr *plr,\
											t_ray *ray, int x);
void						ft_ray_step_player(t_plr *plr, t_ray *r);
void						ft_view_wall(t_all_info *all, t_ray *r);
void						ft_wall_dis_ht(t_plr *plr, t_ray *r,\
											t_all_info *all);
void						ft_process_sort(t_all_info *all);
int							ft_instal_sprite(t_all_info *all);
void						ft_sort_spr(t_plr *plr, t_all_info *all);
void						ft_transform_spr(t_all_info *all,\
								t_plr *plr, t_sprite_ray *sr, int n);
void						ft_height_width_spr(t_all_info *all,\
												t_sprite_ray *sr);
void						ft_color_spr(t_all_info *all, \
											t_sprite_ray *r, int s);
void						ft_load(t_all_info *all, int *txtr,\
									char *path, t_picture *img);
void						ft_mlx_texture(t_all_info *all);
int							ft_check_map(t_all_info *all);
void						ft_free2(char **str);
int							ft_start(t_all_info *all, char *path);
int							ft_second_part(t_all_info *all, int n);
int							ft_print_err(t_all_info *all, int n);
int							ft_one_arg(const char *s1);
int							ft_two_arg(const char *s1, const char *s2);
int							ft_comparison(const char *s, const char *str);
int							ft_duptxtr(char *s1);
char						*ft_minus_end(char *src);
int							ft_key_str_txtr(char *s1);
int							ft_key_end_txtr(char *s1);
void						ft_w_and_h(t_all_info *all, t_plr *plr, t_ray *r);
void						ft_raycasting_spr(t_all_info *all, t_plr *plr);
void						ft_spr_hw(t_all_info *all, t_sprite_ray *s);
void						ft_srp_change(t_all_info *all, t_plr *plr, \
											t_sprite_ray *s_ray, int i);
void						ft_color_spr(t_all_info *all, t_sprite_ray *s_ray, \
											int line);
void						ft_location_spr(t_all_info *all, t_plr *plr);
void						ft_process_loc(t_all_info *all);
int							ft_in_map(char n);
int							ft(char n);
int							ft_list_chek_map_instal_spr(t_all_info *all, \
															char *line);
int							ft_key_key2(char *str);
int							ft_comma(char *str);

#endif
