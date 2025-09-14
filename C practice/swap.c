#include <stdio.h>
#define city 4
#define days 7
void Hottestday(int temp[city][days]);
void Averagetemperature(int temp[city][days]);

int main()
{
    int temp[city][days];
    for(int i=0;i<city;i++){
        printf("Enter temperature for cities %d(0 for karachi, 1 for lahore, 2 for peshawar, 3 for islamabad):\n",i);
        for (int j=0;j<days;j++){
            printf("day %d: \n",j);
            scanf("%d",&temp[i][j]);
        }
    }
    Hottestday(temp);
    Averagetemperature(temp);
}    
    
void Hottestday(int temp[city][days]){
    char cities[city][15]={"karachi","lahore","peshawar","islamabad"};
    for(int i=0;i<city;i++){
        int maxtemp=temp[i][0];
        int hottestday = 0;
        for(int j=0;j<days;j++){
            if(temp[i][j]>maxtemp){
                maxtemp=temp[i][j];
                hottestday=j;
                }
        }
        printf("\nhottest day for %s is %d with a temperature of %d\n",cities[i],hottestday,maxtemp );
    }
}
void Averagetemperature(int temp[city][days]){
    int sum=0;
    for(int j=0;j<days;j++){
        sum+=temp[3][j];
    }
    float avg=sum/(float)days;
    printf("the average temperature in islamabad is %.2f",avg);

}



    
