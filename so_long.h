#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# include "minilibx/mlx.h"
# include "get_next_line.h"

# define K_ESCAPE 53
# define K_LEFT 0
# define K_RIGHT 2
# define K_UP 13
# define K_DOWN 1

# define SMART 0

# define M_GREEN 0, 0, 255, 0

extern char *g_input;

typedef struct s_sizes {
	int	w;
	int	h;
}	t_sizes;

typedef struct s_img {
	void	*i;
	t_sizes	*s;
}	t_img;

typedef struct s_map {
	t_sizes	*s;
	char	*c;

	t_img	*perso_l;
	t_img	*perso_r;
	t_img	*perso_u;
	t_img	*perso_d;

	t_img	*coin_f;
	t_img	*coin_d;
	t_img	*coin_p;

	t_img	*enemy;
	t_img	*bak;
	t_img	*wall;
	t_img	*exit;

	int		player;
	int		chunk;
	int		nb_collect;
	int		nb_exit;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_sizes	*s;

	t_map	*map;
	int	steps;
	int	collect_turn;
	int	enemy_turn;
}	t_vars;


//control.c
t_sizes	*ft_init_size(void);
t_sizes	*ft_new_size(int width, int height);
size_t	ft_strchr_bool(const char *str, int c);

//images.c
t_img	*ft_new_img(char *filename, t_vars *vars);
void	ft_map_imgs(t_map *map, t_vars *vars);
void	ft_map_imgs_larges(t_map *map, t_vars *vars);
void	ft_putimage(t_vars *vars, void *img, int i);


//management.c
int	ft_pow(int base, int pow);
int	ft_trgb(int t, int r, int g, int b);
int	ft_mlx_close(t_vars *vars);
void	ft_free_image(t_img *img);
void	ft_clean_exit(t_vars *vars);

//animation.c
void	ft_update(t_vars *vars);
void	ft_update_enemies(t_vars *vars);

//map.c
t_map	*ft_create_map(char *filename, t_vars *vars);
t_map	*ft_init_map(void);
void	ft_readmap(char *filename, t_map *map);
int		ft_check_map(t_map *map);
//static int	ft_is_border(int i, int width, int height)

//movements.c
int	ft_mlx_key_hook(int keycode, t_vars *vars);
int	ft_move(t_vars *vars, char d);
void	ft_putperso(t_vars *vars, char d, int i);
//static int	ft_itoa_nb_length(int n, int sign);
void	ft_graphic_itoa(int n, t_vars *vars, int x);

#endif
