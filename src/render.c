#include "../inc/fractol.h"

void	handle_pixel(int x, int y, t_mlx *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, 2, 0, 799);
	c.y = map(y, 2, -2, 0, 799);
	while ()
	{
		z = sum_complex(square_complex(z), c);
		if ()
		{
			my_pixel_put();
			return ;
		}
	}

}
void	fractal_render(t_mlx *fractal)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (++y < Y_SIZE)
	{
		while (++x < X_SIZE)
		{
			handle_pixel(x, y, fractal);
		}
	}
}