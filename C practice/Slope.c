#include <stdio.h>

int main()
{
   
    float x1 , y1;
    float x2 , y2;
    float slope;
    
    printf("Enter X-coordinate and y-coordinate of 1st point");
    scanf("%f %f" ,&x1,&y1);
    printf("Enter X-coordinate and y-coordinate of 2nd point");
    scanf("%f %f" ,&x2,&y2);
    slope = (y2 - y1) / (x2 - x1);

    printf("The slope of the line is %.3f\n",slope);

}
