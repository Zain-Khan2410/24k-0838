#include <stdio.h>
int main()
{
    int num,steps=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    if (num>0){
        while(num!=1){
        
        if(num%2==0){
        num=num/2;

    }else{
        num=(num*3)+1;
    }
    steps++;
    }
    printf("steps to reach 1:%d",steps);
    
}else{
    printf("Invalid number");
}
}