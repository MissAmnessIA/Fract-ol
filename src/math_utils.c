#include "../inc/fractol.h"

double map(double unscaled_n, double n_mn, double n_mx, double o_mn, double o_mx)
{
	return ((n_mx - n_mn) * (unscaled_n - o_mn) / (o_mx - o_mn) + n_mn);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x + z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}