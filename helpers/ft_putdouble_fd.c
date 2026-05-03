#include "../push_swap.h"
#include "../libft.h"

void ft_putdouble_fd(double d, int fd, int decimalplaces)
{
	int	   base;
	double remainder;
	int	   digit;

	base = (int)d;
	ft_putnbr_fd(base, fd);
	if (decimalplaces > 0)
	{
		ft_putchar_fd('.', fd);
		remainder = d - (double)base;
		if (remainder < 0)
			remainder = -remainder;
		while (decimalplaces > 0)
		{
			remainder *= 10;
			digit = (int)remainder;
			ft_putnbr_fd(digit, fd);
			remainder -= digit;
			decimalplaces--;
		}
	}
}