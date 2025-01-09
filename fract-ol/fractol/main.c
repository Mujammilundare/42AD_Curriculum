/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreer <rcreer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:17:42 by rcreer            #+#    #+#             */
/*   Updated: 2024/09/23 15:30:53 by rcreer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_msg(void)
{
	putstr_fd("Please enter: \n\" ./fractol mandelbrot \"\n", 2);
	putstr_fd("or\n\"./fractol julia <num1> <num2> \"\n ", 2);
	putstr_fd("or\n./fractol \"buffalo\" \n", 2);
	exit(EXIT_FAILURE);
}

static int	num_check(char *s)
{
	int	i;
	int	dot_check;
	int	decimal_check;

	i = 0;
	dot_check = 0;
	decimal_check = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '.' && s[i] != '+'
			&& s[i] != '-')
			return (0);
		if (!(s[i + 1] >= '0' && s[i + 1] <= '9') && (s[i] == '.' || s[i] == '+'
				|| s[i] == '-'))
			return (0);
		if (s[i] == '.')
			dot_check += 1;
		if (s[i] == '+' || s[i] == '-')
			decimal_check += 1;
		if (dot_check > 1 && decimal_check > 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 6)) || (ac == 2 && !ft_strncmp(av[1],
				"buffalo", 8)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			if (num_check(av[2]) == 1 && num_check(av[3]) == 1)
			{
				fractal.julia_x = string_to_double(av[2]);
				fractal.julia_y = string_to_double(av[3]);
			}
			else
				error_msg();
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_con);
	}
	else
		error_msg();
}
