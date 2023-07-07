# 42project_cub3d
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.


```c

void    ft_render_projection(t_data *data)
{
    double dirX = -1;
    double dirY = 0;
    double planeX = 0;
    double planeY = 0.66; //the 2d raycaster version of camera plane

    // double time = 0; //time of current frame
    // double oldTime = 0;
    int stepX;
    int stepY;
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double sideDistX;
    double sideDistY;

        //length of ray from one x or y-side to next x or y-side
    double deltaDistx;
    double deltaDistY;
    double perpWallDist;
    int side; //was a NS or a EW wall hit?

    int x;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
      //calculate ray position and direction
        cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
      
        rayDirX = dirX + planeX * cameraX;
        rayDirY = dirY + planeY * cameraX;


        //which box of the map we're in
        mapX = (int)data->player.x;
        mapY = (int)data->player.y;

        //length of ray from current position to next x or y-side


        /*  identify the deltas */
        /*  identify which cell to move */
        if (rayDirX == 0)
            deltaDistx = 1e30;
        else
            deltaDistx = fabs(1 / rayDirX);
        if (rayDirY == 0)
            deltaDistY = 1e30;
        else
            deltaDistY = fabs(1 / rayDirY);
        /*  -------------------------------  */
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->player.x - mapX) * deltaDistx;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->player.x) * deltaDistx;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->player.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->player.y) * deltaDistY;
        }




        /*  Find where the wall was hitten  */
        while (data->map[mapY][mapX] == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistx;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
        }

        if(side == 0) 
            perpWallDist = (sideDistX - deltaDistx);
        else
            perpWallDist = (sideDistY - deltaDistY);

        printf("%lf\n", perpWallDist);
        x++;
    }
}

```