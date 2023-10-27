#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int age=1;
while (age!=0) //loop while age is not 0
printf("\n Please enter your age\n");
scanf("%d",&age);
printf("You are %d years old \n",age);
//code now repeats test with value of age
 if ((age==18) || (age==21))
 {
    printf(" Youhave come of age\n");
    break;
 }
}
return 0;

