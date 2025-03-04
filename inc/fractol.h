#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define X_SIZE 500
# define Y_SIZE 500

# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

# define MAGENTA_BURST	0xFF00FF
# define LIME_SHOCK		0xCCFF00
# define NEON_ORANGE	0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM		0x33CCCC
# define HOT_PINK		0xFF66B2
# define ELECTRIC_BLUE	0x0066FF
# define LAVA_RED		0xFF3300

typedef	struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_mlx
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	escape_value;
	int		iteration_definition;
}				t_mlx;

//fractal init
void		data_init(t_mlx *fractal);
void		fractal_init(t_mlx *fractal);

//render
void		my_pixel_put(int x, int y, t_img *img, int color);
void		fractal_render(t_mlx *fractal);
void		handle_pixel(int x, int y, t_mlx *fractal);

//math_utils
double		map(double unscaled_n, double n_mn, double n_mx, double o_mn, double o_mx);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//utils
void		ft_error(char *msg);

#endif