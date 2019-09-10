#include "../incl/fdf.h"


void reload(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	put_grid(fdf);
}

int give_up(void)
{
    exit(1);
	return (0);
}

int key_hooks(int Key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (Key == 53)
		give_up();
	else if (Key == UP_ARROW)
		fdf->y_offset -= 10;
	else if (Key == DOWN_ARROW)
		fdf->y_offset += 10;
	else if (Key == LEFT_ARROW)
		fdf->x_offset -= 10;
	else if (Key == RIGHT_ARROW)
		fdf->x_offset += 10;
	reload(fdf);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf *fdf;

    if (argc != 2)
    {
        ft_putendl("USAGE : ./fdf [fdf file]");
        return (0);
    }
	fdf = init_fdf(argv[1]);
	printf("PRINT FDF : win_height : %d\n", fdf->win_height);
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 6345184, "TEST");
	//mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	//draw_line(fdf, test1, test2);``
	printf("Rendering fdf\n");
	put_grid(fdf);
	mlx_hook(fdf->win, 17, 0, give_up, 0);
    mlx_key_hook(fdf->win, key_hooks, fdf);
    mlx_loop(fdf->mlx);
    return (0);
}
