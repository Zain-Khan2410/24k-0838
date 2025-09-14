#include <stdio.h>
int main()
{
    int i,j,rows,stars,spaces;
    printf("enter no. of rows: ");
    scanf("%d", &rows);
    stars = 1;
    spaces = rows -  1;
    for(i=0;i<=rows*2;i++){
        /* Print spaces */
        for(j=1; j<=spaces; j++){
            printf(" ");
        } 
        
        /* Print stars */
       for(j=1; j<stars*2; j++){
            printf("*");
        }
        /* Move to next line */
        printf("\n");
             if(i<rows)
        {
            spaces--;
            stars++;
        }
        else
        {
            spaces++;
            stars--;
        }
    }
    }
