#include <stdio.h>
#include <math.h>

// Forward TC function
float NISTdegCtoMilliVoltsKtype(float tempDegC);  // returns EMF in millivolts

// Inverse TC function
float NISTmilliVoltsToDegCKtype(float tcEMFmV);  // returns temp in degC assuming 0 degC cold jcn

int main()
{
        // Define VRef
        
    float Vref=5.0;

        // Define Thermistor constants
    float  T0=298.15, B=3975, R0=10;


    // Thermistor function values
    float ThermTK, A1, ThermTempC,ThermV,Res;
    //Thermocouple function values
    float CoupV, A0, CoupETC, CoupT, CompEMF;


        // User input for pins A0 and A1
  

    printf("Please input value for A0\n");
    scanf("%f", &A0);
    printf("Please input value for A1\n");
    scanf("%f",&A1);
        // Calculate thermistor temperature in degrees C ( Part b, i,ii,iii & v)
        ThermV= ADCtoVoltage ( A0, Vref);

        // Convert voltage to resistance
        Res =VoltagetoResistance (ThermV );
        // Convert resistance to temp in K
    
        ThermTK = ResistancetoTempk ( T0 , B, Res, R0);

    // convert temp in k to c 
    ThermTempC = KelvintoCelcius ( ThermTK);
    //printf ("\n The voltage of thermistor is %f\n The temperature in k is %f  degrees\n",ThermV, ThermTempC);

        // Calculate thermocouple temperature in degrees C ( Part c, i - iv)

        //Calculates thermocouple Voltage from ADC
        CoupV= ADCtoVoltage ( A1, Vref);
        //Calculates Thermocouple voltage from ETC 
        CoupETC= ETCFunc(A1);
        //Compensation EMF calculated from thermistor temp (C)
        CompEMF= NISTdegCtoMilliVoltsKtype(ThermTempC);
        // // Adding ETC and compensation EMF for next function
        // InternalADD=(CoupETC, CompEMF*1000);
        //Calculates Hot junction temperature in Celcius 
        CoupT= NISTmilliVoltsToDegCKtype(CoupETC + CompEMF*1000);


    
        // Output results
        printf("Thermistor temperature (deg C): %f \n", ThermTempC);
        printf("Thermocouple temperature with CJC (deg C): %f \n", CoupT);

        return 0;
}

/* Write a function here to convert ADC value to voltages. (Part a, equation 1)
Call it from the main() function above */
// Function to Calculate & return voltage from adc
    float ADCtoVoltage ( float ADC, float vref)
    {	
	float V;
    V = (ADC*vref)/1024;
	return (V);
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

 // Function to convert temp in k to c 
//Voltage to resistance function
float VoltagetoResistance ( float V)
{
	// Calculate & return reistance fom voltage (K Ohms)
	float R;
	R = ((10*3.3/V)-10);
	return (R);
}

 // Convert resistance to temp in K
 float ResistancetoTempk ( float T ,float b, float R, float r0)
{
	// Calculate  \& return value in kelvin
	float TempK;
    TempK=1/((1/T)+(1.0/b)*log(R/r0));
	return (TempK);
}
float ETCFunc( float VThermocoup)
{
 float ETC;
 ETC=((VThermocoup-0.35)/54.4);
return (ETC);

}

// float  InternalADD( float testETC, float TestEcomp)
// {
// // float combine;
// combine= (testETC+ TestEcomp);
// return (combine);
// }

// /* returns EMF in millivolts */
// float NISTdegCtoMilliVoltsKtype(float tempDegC)
// {
//     int i;
//     float milliVolts = 0;
//     if(tempDegC >= -170 && tempDegC < 0)
//     {
//         const float coeffs[11] =
//         {
//             0.000000000000E+00,
//             0.394501280250E-01,
//             0.236223735980E-04,
//             -0.328589067840E-06,
//             -0.499048287770E-08,
//             -0.675090591730E-10,
//             -0.574103274280E-12,
//             -0.310888728940E-14,
//             -0.104516093650E-16,
//             -0.198892668780E-19,
//             -0.163226974860E-22
//         };
//         for (i=0; i<=10; i++)
//         {
//             milliVolts += coeffs[i] * pow(tempDegC,i);
//         }
//     }
//     else if(tempDegC >= 0 && tempDegC <= 1372)
//     {
//         const float coeffs[10] =
//         {
//             -0.176004136860E-01,
//             0.389212049750E-01,
//             0.185587700320E-04,
//             -0.994575928740E-07,
//             0.318409457190E-09,
//             -0.560728448890E-12,
//             0.560750590590E-15,
//             -0.320207200030E-18,
//             0.971511471520E-22,
//             -0.121047212750E-25
//         };
//         const float a0 =  0.118597600000E+00;
//         const float a1 = -0.118343200000E-03;
//         const float a2 =  0.126968600000E+03;

//         for (i=0; i<=9; i++)
//         {
//             milliVolts += coeffs[i] * pow(tempDegC,i);
//         }

//         milliVolts += a0*exp(a1*(tempDegC - a2)*(tempDegC - a2));
//     }
//     else
//     {
//         milliVolts = 99E99;
//     }
//     return milliVolts;
// }

// // returns temperature in deg C.
// float NISTmilliVoltsToDegCKtype(float tcEMFmV)
// {

//         int i, j;
//         float tempDegC = 0;
//         const float coeffs[11][3] =
//         {
//           {0.0000000E+00,  0.000000E+00, -1.318058E+02},
//          {2.5173462E+01,  2.508355E+01,  4.830222E+01},
//          {-1.1662878E+00,  7.860106E-02, -1.646031E+00},
//          {-1.0833638E+00, -2.503131E-01,  5.464731E-02},
//          {-8.9773540E-01,  8.315270E-02, -9.650715E-04},
//          {-3.7342377E-01, -1.228034E-02,  8.802193E-06},
//          {-8.6632643E-02,  9.804036E-04, -3.110810E-08},
//          {-1.0450598E-02, -4.413030E-05,  0.000000E+00},
//          {-5.1920577E-04,  1.057734E-06,  0.000000E+00},
//          {0.0000000E+00, -1.052755E-08,  0.000000E+00}
//        };
//        if(tcEMFmV >=-5.891 && tcEMFmV <=0 )
//        {
//            j=0;
//        }
//        else if (tcEMFmV > 0 && tcEMFmV <=20.644  )
//        {
//            j=1;
//        }
//        else if (tcEMFmV > 20.644 && tcEMFmV <=54.886  )
//        {
//            j=2;
//        }
//        else
//        {
//            return 99E9;
//        }

//        for (i=0; i<=9; i++)
//         {
//             tempDegC += coeffs[i][j] * pow(tcEMFmV,i);
//         }
//     return tempDegC;
// }