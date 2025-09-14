#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    // int n;
   // printf("enter number of elements: ");
    //scanf("%d", &n);
    ///int *arr = (int *) malloc(1 *sizeof(int));
    //if (arr==NULL){
      //  printf("Memory Allocation Failed");
        //return 1;
    //}
    //printf("Enter %d elements: ",n);
    //for(int i=0; i<n;i++){
     //   arr[i]= i + 1;
   // scanf("%d",&arr[i] );
//}
//printf("Elements entered: \n");/
//for (int i = 0; i < n; i++)
//
//{
  //  printf("%d\n", arr[i]);
//}

//free(arr);
char *string1 = (char *) malloc(5*sizeof(char));
char *string2 = (char *) malloc(5*sizeof(char));
if(string1== NULL){
    printf("Memory Allocation Failed");
    return 1;
}
if(string2 == NULL){
    printf("Memory Allocation Failed");
    return 1;
}
printf("Enter string 1: \n");
scanf("%s", string1);
if(strcmp(string1, "q")== 0){
    free(string1);
    free(string2);
}
printf("Enter string 2: \n");
scanf("%s", string2);
if(strcmp(string1, "q")== 0){
    free(string1);
    free(string2);
}
int length1 = strlen(string1);
int length2 = strlen(string2);
char *concat = (char *)malloc((length1 + length2 + 1)* sizeof(char));
if (concat== NULL){
    printf("Memory Aloocation failed");
    free(string1);
    free(string2);
    return 0;
}
strcpy(concat, string1);
strcat(concat, string2);
printf("Concatenated String: %s", concat);
free(string1);
free(string2);
free(concat);


return 0;
}

