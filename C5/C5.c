#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int r=2; 
float Vol= (4*M_PI*r*r*r)/3;
float Area=4*M_PI*r*r;
printf("The volume of the sphere is %-3f\n and the surface area is%3f",Vol,Area);
}