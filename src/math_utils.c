#include "../inc/fractol.h"

double map(double uscaled_n, double n_mn, double n_mx, double o_mn, double o_mx)
{
	return ((n_mx - n_mn) * (uscaled_n - o_mn) / (o_mx - o_mn) + n_mn);
}