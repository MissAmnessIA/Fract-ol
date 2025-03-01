#include "../inc/fractol.h"


void	fractal_init(t_mlx *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		ft_error("Connection error");
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, X_SIZE, Y_SIZE, fractal->name);
	if (!fractal->win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal);
		ft_error("Error creating window");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr,
											X_SIZE, Y_SIZE);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal);
		ft_error("Error creating image");
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
											&fractal->img.bpp,
											&fractal->img.line_len,
											&fractal->img.endian);
	//events_init(fractal); // TO DO
	//data_init(fractal); //TO DO
}