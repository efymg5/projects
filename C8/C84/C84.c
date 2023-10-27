 #include <stdio.h>
 #include <stdlib.h>
 int main(void)
 {

    int a;
    printf("Please enter an age\n");
    scanf("%d",&a);
    if (a<=5)
   {
    printf("Still a baby");
   } 
    else if ((a<5) || (a<=12))
    {
        printf("Junior years");
    }
        else if ((a<12) || (a<20))
    {
        printf("Teenage years");
    }
            else if (a>=20)
    {
        printf("Yay adulthood");
    }
    return 0;
 }