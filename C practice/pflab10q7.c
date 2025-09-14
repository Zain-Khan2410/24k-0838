#include<stdio.h>
#define conversion 0.001
int fcalled=0;

void tokilometer(float meters[],int i){
	float kilometer=meters[i]*conversion;
	fcalled+=1;
	printf("kilometer: %f\n",kilometer);
	
}
int main(){
	int j;
	printf("Enter how many numbers you want to convert: ");
	scanf("%d",&j);
	float meters[j];
	for(int i=0;i<j;i++){
	
	printf("Enter meters: ");
	scanf("%f", &meters[i]);
	tokilometer(meters,i);}
	printf("The function is called %d times",fcalled);
}
