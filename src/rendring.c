#include "../libft/libft.h"
#include "../include/parse.h"
#include "../include/minirt.h"


void render(t_scene *scene)
{
    int x;
    int y;
    int color;
    t_ray *ray;

    scene->mlx = mlx_init();
    if (!scene->mlx)
    {
        printf("Error: Failed to initialize MLX\n");
        return;
    }
    scene->mlx_win = mlx_new_window(scene->mlx , 800, 600, "Mini RT");
    if (!scene->mlx_win)
    {
        printf("Error: Failed to create MLX window\n");
        return;
    }
    if (!scene->img)
    {
        printf("Error: scene->img is NULL\n");
        return;
    }
    scene->img->img = mlx_new_image(scene->mlx, 800, 600);
    if (!scene->img->img)
    {
        printf("Error: Failed to create MLX image\n");
        return;
    }
    y = 0;
    while (y < 600)
    {
        x = 0;
        while (x < 800)
        {
            ray = create_ray(&scene->camera, x, y, scene);
            if (ray)
            {
                color = colors_and_hits(scene, ray);
                mlx_pixel_put(scene->mlx, scene->mlx_win, x, y, color);
                free_ray(ray);
            }
            x++;
        }
        y++;
    }
    mlx_loop(scene->mlx);
}
