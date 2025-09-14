#include<stdio.h>

int main()
{
  int age , nt;
  char seattype;
  float tc,tp;
  
  printf("enter the age: ");
  scanf("%d", &age);
  
  if (age < 16) {
  printf("invalid age");
  }
 
  printf("Enter Seat type (R for Regular, V for VIP, P for Premium): ");
  scanf(" %c", &seattype); 
    
    
  printf("Enter the number of tickets: ");
  scanf("%d", &nt);
  
  if (age < 16) {
  printf("invalid age");
  }
  
  if (seattype = 'R') {
     if (age >= 16 && age <= 64) {
       tp = 800;
     }else { 
       tp = 700;
     }
  }else if (seattype = 'V') {
       if (age >= 16 && age <= 64) {
          tp = 1000;
       }else {
          tp= 1500;
       }
  }else if (seattype = 'P') {
      if (age >= 16 && age <=64) {
         tp = 1500;
      }else { 
         tp = 1300;
      }
  }else {
     printf("Invalid Seat type");
  }
 
 tc = tp * nt;
  
  if (tc > 3500) {
     tc = tc * 0.9;
  }
  printf(" The total cost of tickets is: %.2f\n", tc);
}