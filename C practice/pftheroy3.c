#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *temp;
    int n;
    printf("Enter the number of strings you want to sort: ");
    scanf("%d",&n);
    char **str = (char **)malloc(n * sizeof(char *));
    if(str ==NULL){
        printf("Memory allocation Failed");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        str[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter the string: ");
        scanf("%s",str[i]);
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(strcmp(str[j], str[j+1]) > 0){
               temp = str[j];
               str[j] = str[j+1];
               str[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",str[i]); 
    }
    for(int i = 0;i<n;i++){
        free(str[i]);
    }
    free(str);
}