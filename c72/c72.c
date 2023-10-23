
 #include <stdio.h>
 #include <stdlib.h>
 

 int main(void)
 { 
    char Myname[50];
    printf("Please enter your name\n");
    fgets(Myname, 50, stdin);
 printf("\n Hello %s",Myname);
    return 0; // Exit from main
 }