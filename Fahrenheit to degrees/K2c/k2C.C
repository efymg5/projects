#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    // Define VRef
  //ADC value to voltage
float ADCtoVoltage ( float ADC, float vref)
    {	
	float V;
    V = (ADC*vref)/1024;
	return (V);
	}

 
 // Convert resistance to temp in K

 float ResistancetoTempk ( float T ,float b, float R, float r0)
{
	// Calculate  \& return value in kelvin
	float TempK;
    TempK=1/((1/T)+(1.0/b)*log(R/r0));
	return (TempK);
}

/* Write a function to convert degrees K to degrees C  (Part b, (iv))
 // Convert resistance to temp in K
Call it from the main() function above */
float KelvintoCelcius ( float K)
{
	// Calculate  \& return value in celcius
	float C;
	C = (K-273.15);
	return (C);
}

    float VoltagetoResistance ( float V)
{
	// Calculate & return reistance fom voltage (K Ohms)
	float R;
	R = (((10*3.3)/V)-10);
	return (R);
}

int main()
{
 // Define Thermistor constants

  float ThermTK,ThermTempC;
  float T0=298.15, B=3975, R0=10;

  float A0,ThermV,Res;
  float Vref=5.0;
 printf("Please input value for A0\n");
 scanf("%f", &A0);

    // Calculate thermistor temperature in degrees C ( Part b, i,ii,iii & v)
    ThermV= ADCtoVoltage ( A0, Vref);
 //printf("\n The voltage of thermistor is %f\n",ThermV);
 
 Res =VoltagetoResistance (ThermV );
    //printf ("\nThe resistance is %f  K ohms\n");
   
 
     ThermTK = ResistancetoTempk ( T0 , B, Res, R0);
 
    ThermTempC = KelvintoCelcius ( ThermTK);
   printf ("\n The voltage of thermistor is %f\n The temperature in k is %f  degrees\n",ThermV, ThermTempC);
    return 0;
}