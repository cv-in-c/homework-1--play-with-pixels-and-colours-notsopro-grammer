#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    if (x < 0) x = 0;
    if (x >= im.w) x = im.w - 1;
    if (y < 0) y = 0;
    if (y >= im.h) y = im.h - 1;
    return im.data[x + im.w * y + im.w * im.h * c)];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    im.data[x + im.w * y + im.w * im.h * c] = v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    if(im.c=0)
        for(int i=0;i<im.w;i++){
            for(int j=0;j<im.h;j++0{
                int pvalue=x + im.w * y + im.w * im.h * c;
            }
        }
    if(im.c=1)
        for(int i=0;i<im.w;i++){
            for(int j=0;j<im.h;j++0{
                int pvalue=x + im.w * y + im.w * im.h * c; 
            }
        }
     if(im.c=2)
        for(int i=0;i<im.w;i++){
            for(int j=0;j<im.h;j++0{
                int pvalue=x + im.w * y + im.w * im.h * c;
            }
        }           
    
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
