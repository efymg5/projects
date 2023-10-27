#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    // Define VRef
  
float ADCtoVoltage ( float ADC, float vref)
    {	
	float V;
    V = (ADC*vref)/1024;
	return (V);
	}



int main(void)
{
 // Define Thermistor constants

  float A0,ThermV;
  float Vref=5.0;

    // User input for pins A0 

 printf("Please input value for A0\n");
 scanf("%f", &A0);

    // Calculate thermistor temperature in degrees C ( Part b, i,ii,iii & v)
    ThermV= ADCtoVoltage ( A0, Vref);

 
  printf("\n The voltage of thermistor is %f\n",ThermV);
    //printf ("\nThe resistance is %f  K ohms\n");
    return 0;
}
