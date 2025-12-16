#ifndef MINI_RT_H
#define MINI_RT_H

# include "../minilibx-linux/mlx.h"
# include "parse.h"

#include <math.h>

typedef struct s_hit
{
    double t;
    int   hit;
    double distance;
    t_coordinates   point;
    t_color   color;
    t_coordinates   normal;
} t_hit;

t_hit   hit_objcts(t_scene *scene, t_ray *ray);
t_hit   intersaction_sphere(t_ray *ray, t_sphere *sphere);
// void sphere(t_scene *t_scene);

#endif