#include "../include/mrt.h"

void	print_coordinate(t_tuple coor)
{
	printf("x = %lf || y = %lf || z = %lf || v = %lf\n", coor.x, coor.y, coor.z, coor.v);
}

void	print_color(t_color color)
{
	printf("r = %d || g = %d || b = %d\n", (int)color.r, (int)color.g, (int)color.b);
}

void	print_a_light(t_ambient_light light)
{
	printf("ratio = %lf\n", light.ratio);
	print_color(light.color);
}

void	print_camera(t_camera camera)
{
	print_coordinate(camera.forward);
	print_coordinate(camera.viewpoint);
	printf("fov = %d\n", (int)camera.fov);
}

void	print_light(t_light light)
{
	print_coordinate(light.point);
	printf("ratio = %lf\n", light.b_ratio);
	print_color(light.color);
}

void	print_sphere(t_sphere sphere)
{
	print_coordinate(sphere.center);
	printf("rad = %lf\n", sphere.rad_square);
	print_color(sphere.color);
}

void	print_plane(t_plane plane)
{
	print_coordinate(plane.point);
	print_coordinate(plane.n_vector);
	print_color(plane.color);
}

void	print_cylinder(t_cylinder cylinder)
{
	print_coordinate(cylinder.center);
	print_coordinate(cylinder.n_vector);
	printf("d = %lf\n", cylinder.diameter);
	printf("h = %lf\n", cylinder.height);
	print_color(cylinder.color);
}

void	print_scene(t_scene scene)
{
	printf("print the ambint light\n");
	print_a_light(scene.ambient_light);
	printf("print the camera\n");
	print_camera(scene.camera);
	printf("print the light\n");
	while (scene.light != NULL)
	{
		print_light(*(scene.light));
		scene.light = (scene.light)->next;
	}
	printf("print the sphere\n");
	while (scene.sphere != NULL)
	{
		print_sphere(*(scene.sphere));
		scene.sphere = (scene.sphere)->next;
	}
	printf("print the plane\n");
	while (scene.plane != NULL)
	{
		print_plane(*(scene.plane));
		scene.plane = (scene.plane)->next;
	}
	printf("print the cylinder\n");
	while (scene.cylinder != NULL)
	{
		print_cylinder(*(scene.cylinder));
		scene.cylinder = (scene.cylinder)->next;
	}
}
