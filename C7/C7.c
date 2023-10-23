#include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

 int main(void)
 {
 int h; // Declare some variables
 float r;
 float M_PI=3.142; 

 // Use printf to prompt the use to enter an integer
 printf("please enter the value for height\n");

 // use scanf with %d to read into ’a’
 scanf("%d",&h); // note the important &

 // And display on the screen
 printf("The value you entered for h is %d\n", h);

 // Use printf to prompt the use to enter an float
 printf("Please enter the value for radius\n");

 // use scanf with %f to read into ’f’
 scanf("%f",&r); // note the important &

 // And display on the screen
 printf ("The value you entered for radius is %f\n", r);
 int SurfA= (2*M_PI*r*r)+(2*M_PI*r*h);
 printf ("The surface area of the sphere is %f\n", SurfA);
 return 0; // Exit from main
 }
