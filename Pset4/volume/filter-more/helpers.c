#include "helpers.h"
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {   //if(width % 2 == 0 ||(width % 2 != 0 && j != (width-1)/2))
            temp_image = *(&image[i][j]);
            *(&image[i][j]) = *(&image[i][width-j-1]);
            *(&image[i][width-j-1]) = temp_image;
        }
    }
    return;
}

//Check the validity of adjacent pixels
bool valid(int k, int l, int height, int width)
{
    if(k >= 0 && l >= 0 && k < height && l < width)
    {
        return true;
    }
    return false;
}

//Calculate the average color values of the pixel and its neighboring pixels and update the color value of pixel
void calc_avg(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int total_red, total_blue, total_green, grid_count; total_red = total_blue = total_green = grid_count = 0;
    for(int k = i-1; k <= i+1; k++)
    {
        for(int l = j-1; l <= j+1; l++)
        {
            if(valid(k, l, height, width))
            {
                grid_count++;
                total_red += image[k][l].rgbtRed;
                total_blue += image[k][l].rgbtBlue;
                total_green += image[k][l].rgbtGreen;
            }
        }
    }
    image[i][j].rgbtRed = round(total_red / grid_count);
    image[i][j].rgbtBlue = round(total_blue / grid_count);
    image[i][j].rgbtGreen = round(total_green / grid_count);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            calc_avg(i, j, height, width, image);
        }
    }
    return;
}

//Check for any pixels past the border
bool valid_border(int i, int j, int k, int l, int height, int width)
{
    if(i+k >=0 && i+k < height && j+l >= 0 && j+l < width)
    {
        return true;
    }
    return false;
}

int cap(int value)
{
    if(value < 255)
    {
        return value;
    }
    else
    {
        return 255;
    }
}

void calc_sobel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] ={{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] ={{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int new_redx, new_bluex, new_greenx, new_redy, new_bluey, new_greeny;
    new_redx = new_bluex = new_greenx = new_redy = new_bluey = new_greeny = 0;

    for(int k = -1; k <= 1; k++)
    {
        for(int l = -1; l <= 1; l++)
        {
            if(valid_border(i, j, k, l, height, width))
            {
                new_redx += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                new_bluex += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                new_greenx += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];

                new_redy += image[i + k][j + l].rgbtRed * Gy[k+1][l+1];
                new_bluey += image[i + k][j + l].rgbtBlue * Gy[k+1][l+1];
                new_greeny += image[i + k][j + l].rgbtGreen * Gy[k+1][l+1];
            }
        }
    }
    image[i][j].rgbtRed = cap(round(sqrt(new_redx * new_redx + new_redy * new_redy)));
    image[i][j].rgbtBlue = cap(round(sqrt(new_bluex* new_bluex + new_bluey * new_bluey)));
    image[i][j].rgbtGreen = cap(round(sqrt(new_greenx * new_greenx + new_greeny * new_greeny)));
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j =0; j < width; j++)
        {
            calc_sobel(i , j, height, width, image);
        }
    }
    return;
}
