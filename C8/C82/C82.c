 #include <stdio.h>
 #include <stdlib.h>
 int main(void)
 {

    int a;
    printf("Please enter a number between 1 and 10\n");
    scanf("%d",&a);
    if ((a>=1) && (a<=10))
   {
    printf("The number is in range");
   } 
    else if ((a<1) || (a>10))
    {
        printf("The number is not in range");
    }
    return 0;
 }