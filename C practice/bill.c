#include<stdio.h>

int main()
{
  int price;
  float discount, afterdiscountprice;
  printf("Enter the price");
  scanf(" %d", &price);
  
  if (price<500){
  discount= 0 * price;
  afterdiscountprice = price - discount;
  }
  else if (price>= 500 && price>2000){
  discount= 0.05 * price;
  afterdiscountprice = price - discount;
  }
  else if (price>= 2000 && price< 4000){
  discount= 0.10 * price;
  afterdiscountprice = price - discount;
  }
  else if (price>= 4000 && price<= 6000){
  discount= 0.20 * price;
  afterdiscountprice = price - discount;
  }
  else if (price> 6000){
  discount= 0.35 * price;
  afterdiscountprice = price - discount;
  } 
 
    

printf("Price= %d \n", price);
printf("Discount= %.2f \n", discount);
printf("Amount after discount= %.2f \n", afterdiscountprice);
}