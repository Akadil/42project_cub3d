// void    ft_draw_column(t_data *data, t_ray *ray, int x)
// {
//     int lineHeight;
//     int draw_start;
//     int draw_end;

//     float   ratio_x;
//     float   ratio_y;
//     int     pos_x;
//     int     pos_y;
//     int     pos_color;

//     lineHeight = (int)(WINDOW_HEIGHT / ray->distance_perp);
//     draw_start = -lineHeight / 2 + WINDOW_HEIGHT / 2;
//     if (draw_start < 0)
//         draw_start = 0;
//     draw_end = lineHeight / 2 + WINDOW_HEIGHT / 2;
//     if (draw_end >= WINDOW_HEIGHT)
//         draw_end = WINDOW_HEIGHT - 1;
//     if (ray->side == 1)                      // upper or lower 
//     {
//         ratio_x = data->player.x + ray->distance_perp * ray->dir.x;
//         ratio_x -= (int)ratio_x;
//         if (ray->dir.y > 0)
//             pos_x = (int)((double)data->wall.south.width * ratio_x);
//         else
//             pos_x = (int)((double)data->wall.north.width * ratio_x);
//     }
//     if (ray->side == 0)                      // right or left
//     {
//         ratio_x = data->player.y + ray->distance_perp * ray->dir.y;
//         ratio_x -= (int)ratio_x;
//         if (ray->dir.x > 0)
//             pos_x = (int)((double)data->wall.west.width * ratio_x);
//         else
//             pos_x = (int)((double)data->wall.east.width * ratio_x);
//     }
//     while (draw_start < draw_end)
//     {
//         if (ray->side == 1 && ray->dir.y > 0)
//         {
//             ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
//             pos_y = (int)(data->wall.south.height * ratio_y);
//             pos_color = (float)(pos_y * data->wall.south.line_len) + (pos_x * ((float)data->wall.south.bpp / 8));
//             printf("%d, %d, %d\n", (int)data->wall.south.addr[pos_color], (int)data->wall.south.addr[pos_color + 1], (int)data->wall.south.addr[pos_color + 2]);
//             my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.south.addr[pos_color], (int)data->wall.south.addr[pos_color + 1], (int)data->wall.south.addr[pos_color + 2])); 
//         }
//         else if (ray->side == 1 && ray->dir.y <= 0)
//         {
//             ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
//             pos_y = (int)(data->wall.north.height * ratio_y);
//             pos_color = (float)(pos_y * data->wall.north.line_len) + (pos_x * ((float)data->wall.north.bpp / 8));
//             my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.north.addr[pos_color], (int)data->wall.north.addr[pos_color + 1], (int)data->wall.north.addr[pos_color + 2])); 
//         }
//         else if (ray->side == 0 && ray->dir.x > 0)
//         {
//             ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
//             pos_y = (int)(data->wall.west.height * ratio_y);
//             pos_color = (float)(pos_y * data->wall.west.line_len) + (pos_x * ((float)data->wall.west.bpp / 8));
//             my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.west.addr[pos_color], (int)data->wall.west.addr[pos_color + 1], (int)data->wall.west.addr[pos_color + 2]));
//         }
//         else
//         {
//             ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
//             pos_y = (int)(data->wall.east.height * ratio_y);
//             pos_color = (float)(pos_y * data->wall.east.line_len) + (pos_x * ((float)data->wall.east.bpp / 8));
//             my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.east.addr[pos_color], (int)data->wall.east.addr[pos_color + 1], (int)data->wall.east.addr[pos_color + 2]));
//         }
//         draw_start++;
//     }
// }
