#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    // Define VRef
  


    float VoltagetoResistance ( float V)
{
	// Calculate & return reistance fom voltage (K Ohms)
	float R;
	R = (((10*3.3)/V)-10);
	return (R);
}

int main(void)
{
 // Define Thermistor constants

  float Res;
  float Vref=5.0, ThermV=1.25;


   Res =VoltagetoResistance (ThermV );
  //printf("\n The resistance of thermistor is %f\n",Res);
   
    return 0;
}
