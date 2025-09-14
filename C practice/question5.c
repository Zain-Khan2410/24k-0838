#include<stdio.h>

int main()
{
  int customerID;
  float units, netamount, cperu, bill, surcharge;
  printf("Enter the customer ID");
  scanf(" %d", &customerID);

  printf("Enter the units consumed:");
  scanf(" %f", &units);
  
  if (units<=199){
      cperu= 16.20 ;
      bill = units * cperu;
  }
  else if (units>= 200 && units<300){
      cperu= 20.10;
      bill = units * cperu;
  }
  else if (units>= 300 && units< 500){
      cperu= 27.10;
      bill = units * cperu;
  }
  else if (units>= 500 ){
      cperu= 35.90;
      bill = units * cperu;
  }

  if (bill > 18000){
    surcharge= bill * 0.15;
  }
  netamount = bill + surcharge;
    

printf("Customer ID= %d \n", customerID);
printf("Units Consumed= %.2f \n", units);
printf("Amount Charges @ Rs. %.2f per unit = %.2f\n", cperu, bill);
printf("Surcharge Amount:= %.2f \n", surcharge);
printf("Net amount paid by the customer:= %.2f \n", netamount);
}