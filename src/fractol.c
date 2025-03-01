#include "../inc/fractol.h"

int main (int argc, char **argv)
{
	t_mlx	fractal;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
		ft_error("Wrong arguments");
	mlx_destroy_image(fractal.mlx_ptr, fractal.img.img_ptr);
	mlx_destroy_window(fractal.mlx_ptr, fractal.win_ptr);
	mlx_destroy_display(fractal.mlx_ptr);
	return(0);
}