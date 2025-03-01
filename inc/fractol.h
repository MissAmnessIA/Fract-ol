#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define X_SIZE 500
# define Y_SIZE 500

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
}				t_mlx;

//fractal init
void	fractal_init(t_mlx *fractal);

//render
void	fractal_render(t_mlx *fractal);
void	handle_pixel(int x, int y, t_mlx *fractal)

//math_utils
double map(double uscaled_n, double n_mn, double n_mx, double o_mn, double o_mx);
//utils
void	ft_error(char *msg);

#endif