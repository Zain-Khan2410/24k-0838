#include <stdio.h>

int main() {
    int num, temp, i, d1, d2, d3;
printf("Enter a three digit integer number: ");
scanf("%d", &num);
temp=num;
for( i=0 ; temp>0 ; i++ )
    { temp=temp/10  ; }
if ( i== 3)
   {printf("Valid number\n");
     d1=num%10;
     d2=(num/10) % 10;
     d3=num/100;
     if( d1+d3 == d2)
        {printf("True");}
        else 
        {printf("False");} }
else
   {printf("invalid");}
 }