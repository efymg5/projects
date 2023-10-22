#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int r=2; 
int Vol= (4*M_PI*r*r*r)/3;
int Area=4*M_PI*r*r;
printf("The volume of the sphere is %d\n and the surface area is%d",Vol,Area);
}