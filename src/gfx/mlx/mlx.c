MLX functions that might come in handy

void	*mlx_init(); //must be the first function to be called -> returns NULL if initialization of MLX Library fails

/*
void *mlx_ptr	the mlx instance pointer;
int  size_x		the width of the window;
int  size_y		the height of the window;
char *title		the title of the window;
*/
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title); //creates & returns a pointer to a new window (should be saved for further reference)

/*
void *mlx_ptr	the mlx instance;
void *win_ptr	the window instance;
int  x			the x location of where the image ought to be placed;
int  y			the y location of where the image ought to be placed;
int				has no return value (bc).
*/
// do NOT use mlx_clear_window!!!
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y); // puts image to given location (x,y) (don't forget to clear it afterwards if calling in a loop)

/*
void *mlx_ptr	the mlx instance;
void *win_ptr	the window instance;
int				has no return value (bc).
*/
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr); //destroys the window

/*
void *mlx_ptr	the mlx instance;
int  color		the int color (0xTTRRGGBB);
uint			the converted color.
*/
uint	mlx_get_color_value(void *mlx_ptr, int color); // receives a color value and returns the correspondingly transformed unsigned int

/*
void *mlx_ptr	the mlx instance pointer;
int  width		the width of the image to be created;
int  height		the height of the image to be created;
void*			the image instance reference.
*/
void	*mlx_new_image(void *mlx_ptr,int width,int height); // creates a MLX compatible picture, buffers it before rendering

/*
void *mlx_ptr	the mlx instance;
void *win_ptr	the window instance;
int  x			the x location of where the image ought to be placed;
int  y			the y location of where the image ought to be placed;
int				has no return value (bc).
*/
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y); // puts image at (x,y) recommended for large amounts of graphical data (changing the memory of the locations it will directly change it on the screen)

/*
void *mlx_ptr	the mlx instance;
void *img_ptr	the image instance;
int				has no return value (bc).
*/
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr); // destroys the image

/*
void *win_ptr	the window instance;
int  (*f)()		the handler function, will be called as follows:	(*f)(int key_code, void *param);
void *param		the parameter to give on each event;
int				has no return value (bc).
*/
int		mlx_key_hook(void *win_ptr, int (*f)(), void *param); // every time a key is pressed it will be triggered

/*
void *mlx_ptr	the mlx instance;
int				has no return value (bc).
*/
int		mlx_loop(void *mlx_ptr); // loops over given MLX pointer (will be called by the order of registration)

int		mlx_mouse_hide(); // hides the mouse

/*
void *win_ptr	the window instance;
int  x			the x location to move to;
int  y			the y location to move to;
int				has no return value (bc).
*/
int		mlx_mouse_move(void *win_ptr, int x, int y); // move cursor to given location

/*
void *mlx_ptr	the mlx instance;
int  *sizex		the screen width;
int  *sizey		the screen height
int				has no return value (bc).
*/
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey); // get the current screen size as MacOS is sheit

/*
void *mlx_ptr	the mlx instance;
char *filename	the file to load;
int  *width		a pointer to where the width ought to be written;
int  *height	a pointer to where the height ought to be written;
mem_leak		this function has a memory leak, try using xpm instead;
void*			the image instance.
*/
void	*mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

/*
void *mlx_ptr	the mlx instance;
char *filename	the file to load;
int  *width		a pointer to where the width ought to be written;
int  *height	a pointer to where the height ought to be written;
void*			the image instance, and NULL in case of error.
*/
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);