#include <stdio.h>
#include <stdlib.h>
int main(void)
{//declare variables 
unsigned int a=60,b=13;
unsigned int R;
R= a&b;
printf("The result of a bitwise a and b is %x\n",R);
R= a||b;
printf("The result of a bitwise a or b is %x\n",R);
R= a^b;
printf("The result of a bitwise a XOR b is %x\n",R);
R= ~a ;
printf("a's compliment is  %x\n",R);
R= a<<2;
printf("The result of a shifted left 2 places is %x\n",R);
R= a>>2;
printf("The result of a shifted right 2 places is %x\n",R);

return 0; }