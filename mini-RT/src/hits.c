#include "../libft/libft.h"
#include "../include/parse.h"
#include "../include/minirt.h"


t_coordinates ray_at(t_ray *ray, double t)
{
    t_coordinates result;
    
    result.x = ray->origin.x + t * ray->direction.x;
    result.y = ray->origin.y + t * ray->direction.y;
    result.z = ray->origin.z + t * ray->direction.z;
    return result;
}

t_hit   intersection_cylinder(t_ray *ray, t_cylinder *cylinder)
{
    t_hit			hit;
    t_coordinates	oc;
    double			a, b, c, discriminant;
    double			t1, t2, t;
    double			y;
    double			radius;
    
    ft_bzero(&hit, sizeof(hit));
    
    radius = cylinder->diameter / 2.0;
    oc = vec_substraction(ray->origin, cylinder->center_cylinder);
    
    a = ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z;
    b = 2.0 * (ray->direction.x * oc.x + ray->direction.z * oc.z);
    c = oc.x * oc.x + oc.z * oc.z - (radius * radius);
    
    discriminant = b * b - 4.0 * a * c;
    
    if (discriminant < 0.0 || fabs(a) < 0.0001)
        return (hit);
    
    t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    t = (t1 > 0.001) ? t1 : t2;
    
    if (t > 0.001)
    {
        y = ray->origin.y + t * ray->direction.y;
        
        if (y >= cylinder->center_cylinder.y && y <= cylinder->center_cylinder.y + cylinder->height)
        {
            hit.hit = 1;
            hit.distance = t;
            hit.point = ray_at(ray, t);
            hit.normal = vec_substraction(hit.point, cylinder->center_cylinder);
            hit.normal.y = 0;
            hit.normal = vec_normalize(hit.normal);
            hit.color = cylinder->color;
            return (hit);
        }
    }
    
    return (hit);
}

t_hit   intersection_plane(t_ray *ray, t_plane *plane)
{
    t_hit hit;
    ft_bzero(&hit, sizeof(hit));
    double denom, t;
    t_coordinates oc;

    denom = produit_scalaire(ray->direction, plane->normalized_vector);
    if (fabs(denom) < 0.0001)
        return hit; 
    oc = vec_substraction(plane->point_center, ray->origin);
    t = produit_scalaire(oc, plane->normalized_vector) / denom;
    if (t < 0.001)
        return hit;
    hit.hit = 1;
    hit.distance = t;
    hit.point = ray_at(ray, t);
    hit.normal = plane->normalized_vector;
    if (produit_scalaire(ray->direction, hit.normal) > 0)
    {
        hit.normal.x = -hit.normal.x;
        hit.normal.y = -hit.normal.y;
        hit.normal.z = -hit.normal.z;
    }
    hit.color = plane->color;
    return hit;
}

t_hit   intersection_sphere(t_ray *ray, t_sphere *sphere)
{
	t_hit hit;
	ft_bzero(&hit, sizeof(hit));
	t_coordinates o_c;
	double t1;
	double t2;
	double t;
	double a;
	double b;
	double c;
	double delta;

	o_c = vec_substraction(ray->origin, sphere->sphere_center);
	a = produit_scalaire(ray->direction, ray->direction);
    b = 2.0 * produit_scalaire(o_c, ray->direction);
    c = produit_scalaire(o_c, o_c) - (sphere->radius * sphere->radius);
	delta = b * b - 4 * a * c;
	if (delta < 0)
        return hit;
	t1 = (-b - sqrt(delta)) / (2.0 * a);
    t2 = (-b + sqrt(delta)) / (2.0 * a);
	t = t1;
	if (t1 < 0.001)
		t = t2;
	if (t < 0.001)
		return hit;
	hit.hit = 1;
	hit.distance = t;
	hit.point = ray_at(ray, t);
	hit.normal = vec_substraction(hit.point, sphere->sphere_center);
    hit.normal = vec_normalize(hit.normal);
	hit.color = sphere->color;
	return hit;
}



t_hit   hit_objcts(t_scene *scene, t_ray *ray)
{
	t_hit	closest;
	t_hit	current;
	int i;

	i = 0;
    ft_bzero(&closest, sizeof(closest));
    closest.distance = 1e30;

	while (i < scene->num_sphere && scene->spheres)
	{
		current = intersection_sphere(ray, &scene->spheres[i]);	
        if (current.hit && (!closest.hit || current.distance < closest.distance))
            closest = current;
		i++;
	}

    i = 0;
    while (i < scene->num_planes && scene->planes)
    {
        current = intersection_plane(ray, &scene->planes[i]);
        if (current.hit && (!closest.hit || current.distance < closest.distance))
            closest = current;
		i++; 
    }
   
    i = 0;
    while (i < scene->num_cylinder && scene->cylinders)
    {
        current = intersection_cylinder(ray, &scene->cylinders[i]);
        if (current.hit && (!closest.hit || current.distance < closest.distance))
            closest = current;
		i++; 
    }
	return closest;	

}

int colors_and_hits(t_scene *scene, t_ray *ray)
{
    t_hit hit;

    hit = hit_objcts(scene, ray);

    if (!hit.hit)
        return (144 << 16) | (238 << 8) | 144;

    int r = (int)hit.color.red;
    int g = (int)hit.color.green;
    int b = (int)hit.color.blue;
    
    return (r << 16) | (g << 8) | b;
}