#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char name[10];
	int duration;
	float cost;
	int seats;
}packages;
packages package[3];
void displaypackage(){
	for(int i=0;i<3;i++){
		printf("%d package: \n",i);
		printf("Name:%s\n",package[i].name);
		printf("Duration:%d\n",package[i].duration);
		printf("Cost:%.2f\n",package[i].cost);
		printf("Seats available:%d\n",package[i].seats);
	}}
void packagebook(){
	int num;
	printf("Choose package number from 0-2: ");
	scanf("%d",&num);
	if(package[num].seats!=0){
	package[num].seats-=1;
		 printf("Your seat has been booked successfully");}
	else{ 
	printf("Seats are not available");
	}}
int main(){
	for(int i=0;i<3;i++){
        printf("Enter package name: ");
		scanf("%s", package[i].name);
		printf("Enter duration: ");
		scanf("%d", &package[i].duration);
		printf("Enter cost: ");
		scanf("%f", &package[i].cost);
		printf("Enter seats available: ");
		scanf("%d", &package[i].seats);		
	}
	displaypackage();
	packagebook();
}