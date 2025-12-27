#include "../include/parse.h"
#include "../include/minirt.h"
#include <math.h>


t_coordinates   vec_addition(t_coordinates a, t_coordinates b)
{
    return ((t_coordinates){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_coordinates   vec_substraction(t_coordinates a, t_coordinates b)
{
    return ((t_coordinates){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_coordinates   echelle_vecteur(t_coordinates v, double s)
{
    return ((t_coordinates){v.x * s, v.y * s, v.z * s});
}

double  produit_scalaire(t_coordinates a, t_coordinates b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_coordinates   produit_vectorial(t_coordinates a, t_coordinates b)
{
    return ((t_coordinates){ 
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    });
}

t_coordinates   vec_normalize(t_coordinates v)
{
    double  len;

    len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len == 0)
        return ((t_coordinates){0, 0, 0});
    return ((t_coordinates){v.x / len, v.y / len, v.z / len});
}

// Aliases for compatibility with ray.c 
t_coordinates   vec3_add(t_coordinates a, t_coordinates b)
{
    return (vec_addition(a, b));
}

t_coordinates   vec3_mult(t_coordinates v, double s)
{
    return (echelle_vecteur(v, s));
}

t_coordinates   vec3_normalize(t_coordinates v)
{
    return (vec_normalize(v));
}

