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

```c++
      double spriteX = sprite[spriteOrder[i]].x - posX;
      double spriteY = sprite[spriteOrder[i]].y - posY;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

      double transformX = invDet * (dirY * spriteX - dirX * spriteY);
      double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = int((w / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
      int spriteHeight = abs(int(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + h / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2;
      if(drawEndY >= h) drawEndY = h - 1;

      //calculate width of the sprite
      int spriteWidth = abs( int (h / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= w) drawEndX = w - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
        }
      }
```