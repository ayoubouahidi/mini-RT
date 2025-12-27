#include "../include/parse.h"
#include "../include/minirt.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



// --- The Camera Ray Function ---
t_ray	*create_ray(t_camera *camera, int x, int y, t_scene *scene)
{
	t_ray	*ray;
	t_coordinates	pixel_pos;
	float	aspect_ratio;
	float	fov_scale;
	float	ndc_x;
	float	ndc_y;

	(void)scene;
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	
	// Viewport size
	double width = 800.0;
	double height = 600.0;
	// Calculate aspect ratio and FOV scale
	aspect_ratio = (float)(width / height);
	fov_scale = (float)tan((camera->fov * M_PI / 180.0) / 2.0);

	// Convert pixel coordinates to normalized device coordinates (NDC)
	// Range: [-1, 1] with center at (0, 0)
	ndc_x = (float)((2.0 * ((x + 0.5) / width) - 1.0) * aspect_ratio * fov_scale);
	ndc_y = (float)((1.0 - 2.0 * ((y + 0.5) / height)) * fov_scale);
	
	// Set ray origin at camera position
	ray->origin = camera->pos;
	
	// Calculate ray direction using camera's coordinate system
	// direction = right * ndc_x + up * ndc_y + forward
	pixel_pos = vec3_add(
		vec3_add(
			vec3_mult(camera->right, ndc_x),
			vec3_mult(camera->up, ndc_y)
		),
		camera->direction);
	ray->direction = vec3_normalize(pixel_pos);
	
	return (ray);
}

void	free_ray(t_ray *ray)
{
	if (ray)
		free(ray);
}

/* Initialize camera basis vectors from orientation */
void	init_camera(t_camera *camera)
{
	t_coordinates	world_up;
	t_coordinates	right;
	t_coordinates	up;

	/* Set camera position and forward direction */
	camera->pos = camera->viewpoint;
	camera->direction = vec_normalize(camera->orientation);

	/* Define world up vector */
	world_up = (t_coordinates){0, 1, 0};

	/* Calculate right vector = cross(forward, world_up) */
	right = produit_vectorial(camera->direction, world_up);
	if (produit_scalaire(right, right) < 0.0001)
	{
		/* If forward is parallel to world_up, use different world_up */
		world_up = (t_coordinates){1, 0, 0};
		right = produit_vectorial(camera->direction, world_up);
	}
	camera->right = vec_normalize(right);

	/* Calculate up vector = cross(right, forward) */
	up = produit_vectorial(camera->right, camera->direction);
	camera->up = vec_normalize(up);
}