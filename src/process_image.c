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
    return im.data[x + im.w * y + im.w * im.h * c];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    im.data[x + im.w * y + im.w * im.h * c] = v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    memcpy(copy.data, im.data, im.w * im.h * im.c * sizeof(float)); 
   return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
       for(int i=0;i<im.h;i++){
        for(int j=0;j<im.w;j++){
            float r=im.data[i*im.w+j];
            float g=im.data[i*im.w+j+im.w*im.h];
            float b=im.data[i*im.w+j+2*im.w*im.h];
            float y=0.299*r+0.587*g+0.114*b;
            gray.data[i*im.w+j]=y;
        }
    } 
    return gray;
}

void shift_image(image im, int c, float v)
{
 for(int i=0;i<im.h;i++){
     for(int j=0;j<im.w;j++){
         im.data[j+im.w*i+im.h*im.w*c]+=v;
     }
   }
}

void clamp_image(image im)
{
  for(int i=0;i<im.c;i++){
   for(int j=0;j<im.h;j++){
     for(int k=0;k<im.w;k++){
       if(im.data[i*im.w*im.h+j*im.w+k]>1)
          im.data[i*im.w*im.h+j*im.w+k]=1;
        else if(im.data[i*im.w*im.h+j*im.w+k]<0)
           im.data[i*im.w*im.h+j*im.w+k]=0;
     }
   }
  }
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
   for(int i=0;<im.h;i++){
       for(int j=0;j<im.w;j++){
           float r=im.data[j+im.w*i];
           float g=im.data[j+im.w*i+im.w*im.h*c];
           float b=im.data[j+im.w*i+2*im.w*im.h*c];
           float V=float three_way_max(r,g,b);
           float m=float three_way_min(r,g,b);
           float C=V-m;
           float S;
            if(V==0)
                S=0;
            else
                S=C/V;
            float H1=0,H;
            if(C==0)
                H1=0;
            else if(V==r)
                H1=(g-b)/C;
            else if(V==g)
                H1=(b-r)/C+2;
            else if(V==b)
                H1=(r-g)/C+4;
            
            if(H1<0)
                H=H1/6+1;
            else
                H=H1/6;
           if(H<0)
                H+=1;
           else if(H>1)
                H-=1;

            im.data[j+i*im.w]=H;
            im.data[j+i*im.w+im.w*im.h]=S;
            im.data[j+i*im.w+2*im.w*im.h]=V;
        }
   }
}

void hsv_to_rgb(image im)
{
   
}
