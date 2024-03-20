# Cub3D - A Ray-Casting Project
### <ins>My First RayCaster with miniLibX</ins>

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

---

### <ins>Table of Contents</ins>

1. [Introduction](#introduction)
2. [Technologies Used](#technologies-used)
3. [Ray-Casting vs Ray-Tracing](#ray-casting-vs-ray-tracing)
4. [Limitations of Ray-Casting](#limitations-of-ray-casting)
5. [Digital Differential Analyzer (DDA) Algorithm](#digital-differential-analyzer)
6. [Implementation Details](#implementation-details)
    - [main()](#main)
    - [_render_next_frame()](#_render_next_frame)
    - [_paint()](#_paint)
    - [_ray_casting()](#_ray_casting)
    - [_cast_ray()](#_cast_ray)
    - [_draw_line()](#_draw_line)
    - [_render_the_world()](#_render_the_world)
7. [Usage](#usage)
8. [Screenshots](#screenshots)
9. [Contributing](#contributing)
10. [License](#license)
11. [Contact Information](#contact-information)

---

### <ins>Technologies Used</ins>

This project was implemented using C programming language and the miniLibX library.

---

### <ins>Ray-Casting vs Ray-Tracing</ins>

Ray-casting and ray-tracing are both techniques used in computer graphics to render 3D scenes. The main difference between them is that ray-casting is a rendering technique for generating views of a 3D scene on a 2D display, while ray-tracing is a technique for generating an image by tracing the path of light through pixels in an image plane.

---

### <ins>Limitations of Ray-Casting</ins>

Ray-casting, while efficient and effective for certain applications, does have its limitations:

1. **Lack of Verticality**: Ray-casting typically operates in two dimensions, which means it doesn't handle verticality well. This makes it less suitable for games or simulations that require a full 3D environment.
2. **Over-simplification of Shapes**: Ray-casting simplifies the world into a grid of squares, which can lead to a lack of detail and realism in the rendered environment.
3. **No Shadows or Reflections**: Traditional ray-casting does not support advanced lighting effects like shadows or reflections. These effects require more advanced techniques like ray-tracing.
4. **Limited Field of View**: The field of view in a ray-casting engine is typically limited to a certain angle (often 60 degrees). This can make the rendered environment feel less immersive compared to a full 3D engine.

---

### <ins>Digital Differential Analyzer (DDA) Algorithm</ins>

The Digital Differential Analyzer (DDA) algorithm is a simple yet efficient algorithm used for linear interpolation of variables over an interval between start and end points. In the context of ray casting in a grid (like in a 2D map), it's used to find the cells of the grid that a ray intersects.

Here's a step-by-step breakdown of how the DDA algorithm works in this context:

1. **Initialization**: The algorithm starts at the ray's origin and calculates the direction of the ray in terms of the grid. This is done by dividing the difference in the x and y coordinates of the ray's direction by the length of the ray's direction. This gives the change in x and y for each step along the ray.

2. **Stepping**: The algorithm then enters a loop where it steps along the ray. In each step, it increments the x and y coordinates of the current position by the change in x and y calculated in the initialization step.

3. **Cell Checking**: After each step, the algorithm checks the cell of the grid that the current position is in. If the cell is a wall (or any other cell that the ray can't pass through), the algorithm stops and returns the current position. This is the intersection of the ray with a wall.

4. **Continuation**: If the cell is not a wall, the algorithm continues to the next step along the ray.

The DDA algorithm is efficient because it only needs to check the cells that the ray passes through, and it only needs to check each cell once. This makes it much faster than other methods that check every cell in the grid or that check each cell multiple times.

In the context of the provided code, the DDA algorithm is implemented in the `_horizontal_dda` and `_vertical_dda` functions. These functions step along the ray in the horizontal and vertical directions, respectively, until they find a wall. The `_horizontal_intersect` and `_vertical_intersect` functions are used to calculate the initial intersection points and step sizes for the DDA algorithm.

```C
void	_horizontal_intersect(t_intersection *inter, t_data *data,
		float ray_angle, t_direction dir)
{
	inter->yintercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (dir.down)
		inter->yintercept += TILE_SIZE;
	inter->xintercept = data->player.x + (inter->yintercept - data->player.y)
		/ tan(ray_angle);
	inter->ystep = TILE_SIZE;
	if (dir.up)
		inter->ystep *= -1;
	inter->xstep = inter->ystep / tan(ray_angle);
	if (dir.right && inter->xstep < 0)
		inter->xstep *= -1;
	if (dir.left && inter->xstep > 0)
		inter->xstep *= -1;
	inter->next_x = inter->xintercept;
	inter->next_y = inter->yintercept;
}

void	_horizontal_dda(t_data *data, t_horz *horz, t_intersection *inter,
		int up)
{
	float	y_check;

	while (1)
	{
		y_check = inter->next_y;
		if (up)
			y_check -= 1;
		if (_has_wall_at(inter->next_x, y_check, data))
		{
			horz->wall = 1;
			horz->wall_hit_x = inter->next_x;
			horz->wall_hit_y = inter->next_y;
			break ;
		}
		else
		{
			inter->next_x += inter->xstep;
			inter->next_y += inter->ystep;
		}
	}
}

void	_vertical_intersect(t_intersection *inter, t_data *data,
		float ray_angle, t_direction dir)
{
	inter->xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (dir.right)
		inter->xintercept += TILE_SIZE;
	inter->yintercept = data->player.y + tan(ray_angle) * (inter->xintercept
			- data->player.x);
	inter->xstep = TILE_SIZE;
	if (dir.left)
		inter->xstep *= -1;
	inter->ystep = tan(ray_angle) * inter->xstep;
	if (dir.up && inter->ystep > 0)
		inter->ystep *= -1;
	if (dir.down && inter->ystep < 0)
		inter->ystep *= -1;
	inter->next_x = inter->xintercept;
	inter->next_y = inter->yintercept;
}

void	_vertical_dda(t_data *data, t_vert *vert, t_intersection *inter,
		int left)
{
	float	x_check;

	while (1)
	{
		x_check = inter->next_x;
		if (left)
			x_check -= 1;
		if (_has_wall_at(x_check, inter->next_y, data))
		{
			vert->wall = 1;
			vert->wall_hit_x = inter->next_x;
			vert->wall_hit_y = inter->next_y;
			break ;
		}
		else
		{
			inter->next_x += inter->xstep;
			inter->next_y += inter->ystep;
		}
	}
}
```

### <ins>Implementation Details</ins>
In this section, I'll walk you through the main components of the ray-casting engine implemented in this project.
#### <ins>main()</ins>
The entry point of the project is the `main` function. Here's a step-by-step breakdown of what it does:

```C
int	main(int argc, char **argv)
{
	t_data	data;


	if (ft_parse_args(argc, argv, &data.info, &data.file))
		return (ft_free_info(&data.info), ft_free_file(&data.file));
	if (_initialize(&data, data.info, data.info->map))
		return (1);
	if (ft_open_images(&data.info, &data))
		return(ft_free_info(&data.info), ft_free_file(&data.file));

	_paint(&data);
	mlx_hook(data.win, 2, 1L << 0, _key_press_listener, &data);
	mlx_hook(data.win, 3, 1L << 1, _key_release_listener, &data);
	mlx_loop_hook(data.mlx, _render_next_frame, &data);
	mlx_loop(data.mlx);

	ft_free_info(&data.info);
	ft_free_file(&data.file);
	return (0);
}
```

1. **Parsing Arguments**: The function `ft_parse_args` is called with the command-line arguments. This function is responsible for parsing the arguments and initializing the `data.info` and `data.file` structures. If the arguments are invalid, the function returns an error and the program exits.

2. **Initialization**: The `_initialize` function is called with the `data` structure, `data.info`, and `data.info->map`. This function is responsible for initializing the game state based on the parsed arguments.

3. **Opening Images**: The `ft_open_images` function is called with `data.info` and `data`. This function is responsible for loading the images that will be used in the game. If the images can't be loaded, the function returns an error and the program exits.

4. **Painting the Initial State**: The `_paint` function is called with the `data` structure. This function is responsible for rendering the initial state of the game.

5. **Setting Up Event Listeners**: The `mlx_hook` functions are called to set up event listeners for key press and key release events. The `_key_press_listener` and `_key_release_listener` functions will be called when a key is pressed or released, respectively.

6. **Setting Up the Game Loop**: The `mlx_loop_hook` function is called with the `_render_next_frame` function. This function will be called for each frame of the game, allowing the game state to be updated and the frame to be rendered.

7. **Starting the Game Loop**: The `mlx_loop` function is called to start the game loop. This function will not return until the game is exited.

8. **Cleaning Up**: After the game loop has exited, the `ft_free_info` and `ft_free_file` functions are called to clean up any resources that were allocated during the game.

This main function provides a high-level overview of how the game works. The actual game logic is implemented in the functions that are called from `main`.

#### <ins>_render_next_frame()</ins>

```C
int	_render_next_frame(t_data *data)
{
	if (data->player.walk_direction || data->player.side_direction || data->player.turn_direction)
	{
		if (data->player.walk_direction)
			_move_vertical(data);
		if (data->player.side_direction)
			_move_horizontal(data);
		if (data->player.turn_direction)
			_rotate(data);
		_paint(data);
	}
	return (0);
}
```

The `_render_next_frame` function is a part of the game loop in my ray-casting engine. It's responsible for updating the game state and rendering the next frame. This function is called for each frame of the game, which typically happens many times per second.

Here's a breakdown of what happens in this function:

1. **Checking Player Input**: 

```C
if (data->player.walk_direction || data->player.side_direction || data->player.turn_direction)
```
The function first checks if the player is trying to move or turn. This is done by checking the `walk_direction`, `side_direction`, and `turn_direction` fields of the `player` structure. If any of these fields are non-zero, it means the player is trying to move or turn.

2. **Updating Player Position**: 

The player's position is updated based on the input from the user. This is done in the `_move_vertical`, `_move_horizontal`, and `_rotate` functions.
```C
void	_move_vertical(t_data *data)
{
	float	move_step;
	float	new_x;
	float	new_y;

	move_step = data->player.walk_direction * data->player.move_speed;
	new_x = data->player.x + cos(data->player.rotation_angle) * move_step;
	new_y = data->player.y + sin(data->player.rotation_angle) * move_step;
	if (!_has_wall_at(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	_move_horizontal(t_data *data)
{
	float	move_step;
	float	new_x;
	float	new_y;

	move_step = data->player.side_direction * data->player.move_speed;
	new_x = data->player.x + cos(data->player.rotation_angle + M_PI_2)
		* move_step;
	new_y = data->player.y + sin(data->player.rotation_angle + M_PI_2)
		* move_step;
	if (!_has_wall_at(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	_rotate(t_data *data)
{
	data->player.rotation_angle = data->player.rotation_angle
		+ data->player.turn_direction * data->player.rotation_speed;
}
```


- **_move_vertical**: This function is responsible for moving the player forward or backward. It first calculates the step size for the movement based on the player's walk direction and move speed. It then calculates the new position of the player by adding the step size to the current position. The new position is calculated separately for the x and y coordinates, using the cosine and sine of the player's rotation angle, respectively. This ensures that the player moves in the direction they are facing. If the new position does not have a wall, the player's position is updated.

- **_move_horizontal**: This function is similar to `_move_vertical`, but it's responsible for moving the player left or right. It calculates the step size based on the player's side direction and move speed. The new position is calculated in the same way as in `_move_vertical`, but the rotation angle is adjusted by 90 degrees (or `M_PI_2` radians). This ensures that the player moves perpendicular to the direction they are facing. If the new position does not have a wall, the player's position is updated.

- **_rotate**: This function is responsible for rotating the player. It updates the player's rotation angle based on the player's turn direction and rotation speed. This allows the player to turn left or right.

4. **Rendering the Frame**: After the player's position and direction have been updated, the `_paint` function is called to render the frame. This function uses the current game state to draw a 3D view of the game world.

The function then returns 0, which is typically used to indicate that the function has completed successfully.


#### <ins>_paint()</ins>

The `_paint` function is responsible for rendering a frame of the game. Here's a step-by-step breakdown of what it does:

```C
void	_paint(t_data *data)
{
	char	*img;

	img = mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = img;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	_ray_casting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
```

1. **Creating a New Image**: The function starts by creating a new image using the `mlx_new_image` function. The size of the image is the same as the screen size.

2. **Destroying the Old Image**: If there was a previous image (`data->img.img` is not NULL), it is destroyed using the `mlx_destroy_image` function. This is done to free up the memory used by the old image.

3. **Storing the New Image**: The new image is then stored in `data->img.img`, and its data address is stored in `data->img.addr`. The data address is obtained using the `mlx_get_data_addr` function, which also fills in the bits per pixel, size line, and endian of the image.

4. **Drawing the Map**: The `_draw_map` function is called to draw the map on the new image. This function uses the current game state to determine where the walls and spaces are.

5. **Ray Casting**: The `_ray_casting` function is called to perform ray casting. This function uses the player's position and direction to determine where the rays hit the walls, and it draws the walls on the new image.

6. **Displaying the Image**: Finally, the new image is displayed on the window using the `mlx_put_image_to_window` function. This updates the screen with the new frame.

This function is called for each frame of the game, which typically happens many times per second.

#### <ins>_ray_casting()</ins>

The `_ray_casting` function is responsible for casting rays from the player's position and drawing the walls that the rays hit. Here's a step-by-step breakdown of what it does:

```C
void	_ray_casting(t_data *data)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = _normalize(data->player.rotation_angle - data->half_of_fov);
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->screen_width);
	while (i < data->screen_width)
	{
		_cast_ray(data, ray_angle, i);
		_draw_line(data, ray_angle, i, 0.0);
		ray_angle = _normalize(ray_angle + data->increment_angle);
		i++;
	}
	free(data->rays);
}
```

1. **Initializing Ray Angle**: The function starts by calculating the initial ray angle. This is done by subtracting half of the field of view from the player's rotation angle. The `_normalize` function is used to ensure that the angle is between 0 and 2π.

2. **Allocating Rays Array**: The function then allocates an array of `t_ray` structures. The size of the array is equal to the screen width, which means there will be one ray for each column of the screen.

3. **Casting Rays and Drawing Walls**: The function then enters a loop that runs once for each column of the screen. In each iteration of the loop, it does the following:
   - Calls the `_cast_ray` function to cast a ray from the player's position at the current ray angle. The results of the ray casting are stored in the `data->rays[i]` structure.
   - Calls the `_draw_line` function to draw a vertical line on the screen at the current column. The height and color of the line are determined by the results of the ray casting.
   - Increments the ray angle by `data->increment_angle`, which is the angle between each ray. The `_normalize` function is used to ensure that the angle is between 0 and 2π.

4. **Freeing Rays Array**: After all rays have been cast and all walls have been drawn, the function frees the rays array.

#### <ins>_cast_ray()</ins>

The `_cast_ray` function is responsible for casting a single ray from the player's position and determining where it hits a wall. Here's a step-by-step breakdown of what it does:

```C
void	_cast_ray(t_data *data, float ray_angle, int i)
{
    t_horz			horz;
    t_vert			vert;
    t_intersection	inter;
    t_direction		dir;

    horz = (t_horz){0};
    vert = (t_vert){0};
    ray_angle = _normalize(ray_angle);
    dir = _set_direction(ray_angle);
    _horizontal_intersect(&inter, data, ray_angle, dir);
    _horizontal_dda(data, &horz, &inter, dir.up);
    _vertical_intersect(&inter, data, ray_angle, dir);
    _vertical_dda(data, &vert, &inter, dir.left);
    horz.distance = INT_MAX;
    vert.distance = INT_MAX;
    if (horz.wall)
        horz.distance = _distance_between_points(data->player.x, data->player.y,
                horz.wall_hit_x, horz.wall_hit_y);
    if (vert.wall)
        vert.distance = _distance_between_points(data->player.x, data->player.y,
                vert.wall_hit_x, vert.wall_hit_y);
    _horz_vert_choice(data, &horz, &vert, i);
}
```

1. **Initializing Variables**: The function starts by initializing several variables. `horz` and `vert` are structures that will hold information about the horizontal and vertical intersections of the ray with the walls. `inter` is a structure that will hold information about the intersection of the ray with a wall. `dir` is a structure that will hold the direction of the ray.

2. **Normalizing Ray Angle**: The ray angle is normalized using the `_normalize` function to ensure it is between 0 and 2π.

3. **Setting Ray Direction**: The direction of the ray is set using the `_set_direction` function. This function determines whether the ray is facing up or down and left or right based on the ray angle.

4. **Finding Horizontal Intersections**: The `_horizontal_intersect` function is called to find the first horizontal intersection of the ray with a wall. The `_horizontal_dda` function is then called to step along the grid of squares in the map until it finds a wall. This is done using the Digital Differential Analyzer (DDA) algorithm, which is an efficient way to interpolate values in a grid.

5. **Finding Vertical Intersections**: The `_vertical_intersect` function is called to find the first vertical intersection of the ray with a wall. The `_vertical_dda` function is then called to step along the grid of squares in the map until it finds a wall. This is also done using the DDA algorithm.

6. **Calculating Distances**: The distances from the player to the horizontal and vertical intersections are calculated using the `_distance_between_points` function. If there was no intersection, the distance is set to `INT_MAX`.

7. **Choosing the Closest Intersection**: The `_horz_vert_choice` function is called to choose the closest intersection (either horizontal or vertical). This is the intersection that the ray actually hits.

This function is called once for each ray that is cast, which is once for each column of the screen.

#### <ins>_draw_line()</ins>

The `_draw_line` function is responsible for drawing a vertical line for each ray that is cast. This line represents a slice of the wall that the ray hits. Here's a step-by-step breakdown of what it does:

```C
void	_draw_line(t_data *data, float ray_angle, int i, float dist_to_proj)
{
    float	correct_distance;
    float	wall_height;
    float	wall_top;
    float	wall_bottom;
    int		texture_offset_x;

    correct_distance = data->rays[i].distance * cos(ray_angle
            - data->player.rotation_angle);
    dist_to_proj = (data->screen_width / 2) / tan(data->half_of_fov);
    wall_height = (TILE_SIZE / correct_distance) * dist_to_proj;
    wall_top = (data->screen_height / 2) - (wall_height / 2);
    if (wall_top < 0)
        wall_top = 0;
    wall_bottom = (data->screen_height / 2) + (wall_height / 2);
    if (wall_bottom > data->screen_height)
        wall_bottom = data->screen_height;
    texture_offset_x = _set_texture(data, ray_angle, i);
    _render_the_world(data, &(t_pack){wall_top, wall_bottom, wall_height, i},
        texture_offset_x);
}
```

1. **Correcting the Distance**: The function starts by correcting the distance from the player to the wall that the ray hit. This is done by multiplying the distance by the cosine of the difference between the ray angle and the player's rotation angle. This corrects for the "fishbowl effect" where walls appear to curve around the player.

2. **Calculating Wall Height**: The function then calculates the height of the wall on the screen. This is done by dividing the size of a tile by the corrected distance and then multiplying by the distance to the projection plane. The distance to the projection plane is calculated based on the screen width and the field of view.

3. **Calculating Wall Top and Bottom**: The function then calculates the y-coordinates of the top and bottom of the wall on the screen. The top is calculated by subtracting half of the wall height from half of the screen height. If this is less than 0, it's set to 0. The bottom is calculated by adding half of the wall height to half of the screen height. If this is greater than the screen height, it's set to the screen height.

4. **Setting Texture**: The function then determines the x-coordinate of the texture that should be used for the wall. This is done by calling the `_set_texture` function.

5. **Rendering the Wall**: Finally, the function calls the `_render_the_world` function to draw the wall on the screen. This function draws a vertical line from the top to the bottom of the wall, using the texture determined in the previous step.

#### <ins>_render_the_world()</ins>

The `_render_the_world` function is responsible for drawing a vertical line on the screen that represents a slice of the wall that a ray hit. Here's a step-by-step breakdown of what it does:

```C
void	_render_the_world(t_data *data, t_pack *pack, int texture_offset_x)
{
	int		i;
	int		wall_y;
	int		texture_y;
	char	*dst;

	i = 0;
	while (i < pack->wall_top)
	{
		my_mlx_pixel_put(data->img, pack->i, i++, rgb_to_hex(data->info->c.r,
				data->info->c.g, data->info->c.b));
	}
	while (i < pack->wall_bottom)
	{
		wall_y = i + (pack->wall_height / 2) - (data->screen_height / 2);
		texture_y = (int)(wall_y * (float)data->texture->height
				/ pack->wall_height) % data->texture->height;
		dst = data->texture->addr + texture_y * data->texture->size_line
			+ texture_offset_x * (data->texture->bits_per_pixel / 8);
		my_mlx_pixel_put(data->img, pack->i, i, *(unsigned int *)dst);
		i++;
	}
	while (i < data->screen_height)
		my_mlx_pixel_put(data->img, pack->i, i++, rgb_to_hex(data->info->f.r,
				data->info->f.g, data->info->f.b));
}
```

1. **Drawing the Ceiling**: The function starts by drawing the ceiling above the wall. This is done by calling the `my_mlx_pixel_put` function in a loop from the top of the screen to the top of the wall. The color of the ceiling is determined by the `data->info->c` color.

2. **Drawing the Wall**: The function then draws the wall. This is done by calling the `my_mlx_pixel_put` function in a loop from the top to the bottom of the wall. The color of each pixel of the wall is determined by the texture of the wall. The y-coordinate of the texture is calculated based on the y-coordinate of the wall and the height of the wall and the texture. The x-coordinate of the texture is passed to the function as `texture_offset_x`.

3. **Drawing the Floor**: Finally, the function draws the floor below the wall. This is done by calling the `my_mlx_pixel_put` function in a loop from the bottom of the wall to the bottom of the screen. The color of the floor is determined by the `data->info->f` color.


---

### <ins>Usage</ins>

*To be filled in with specific instructions on how to run your project.*

---

### <ins>Screenshots</ins>

*To be filled in with screenshots of your project.*

---

### <ins>Contributing</ins>

*To be filled in with instructions on how others can contribute to your project, if applicable.*

---

### <ins>License</ins>

*To be filled in with information about the license your project is under, if applicable.*

---

### <ins>Contact Information</ins>

*To be filled in with your contact information or a way for readers to reach you if they have questions or comments.*
