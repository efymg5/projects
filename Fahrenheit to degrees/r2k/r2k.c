#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    // Define VRef
  


 
 // Convert resistance to temp in K
 float ResistancetoTempk ( float T ,float b, float R, float r0)
{
	// Calculate  \& return value in kelvin
	float TempK;
    TempK=1/((1/T)+(1.0/b)*log(R/r0));
	return (TempK);
}

int main(void)
{
 // Define Thermistor constants

  float ThermTK;
  float T0=298.15, B=3975, R0=10, Res=16.4;


 
     ThermTK = ResistancetoTempk (  T0 , B, Res, R0);
    printf ("\nThe temperature in k is %f  degrees\n", ThermTK);
   
    return 0;
}