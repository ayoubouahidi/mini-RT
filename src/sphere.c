#include "../libft/libft.h"
#include "../include/parse.h"
#include "../include/minirt.h"
/* mlx.h is included in ../include/minirt.h, avoid duplicate include to fix editor includePath warnings */

void sphere(t_scene *scene)
{
    int x;
    int y;

    scene->mlx = mlx_init();
    scene->mlx_win = mlx_new_window(scene->mlx , 800, 600, "My Window");
    mlx_loop(scene->mlx);
    scene->img->img = mlx_new_image(scene->mlx, 800, 600);
    y = 0;
    while (y < 800)
    {
        x = 0;
        while (x < 600)
        {
            // ray generation 
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(scene->mlx, scene->mlx_win, scene->img->img, 0, 0);
    mlx_loop(scene->mlx);
    
}