#include "../inc/fractol.h"
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x *(img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}


void	handle_pixel(int x, int y, t_mlx *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;

	z.x = map(x, -2, 2, 0, 499);
	z.y = map(y, 2, -2, 0, 499);
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);

}
void	fractal_render(t_mlx *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < Y_SIZE)
	{
		x = -1;
		while (++x < X_SIZE)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
							fractal->win_ptr,
							fractal->img.img_ptr,
							0, 0);
}