#include <stdio.h>
#include <string.h>
int main()
{
   char array[5][100] = {"Have", "you", "done", "your", "work"};
   char word[100];
   printf("Enter a word: ");
   scanf("%s",&word);
   int flag = 0;
   for(int i= 0; i<5;i++){
    if(strcmp(array[i],word) == 0){
        flag = 1;
        break;
    } 
   }
   if(flag == 1){
    printf("Found");
    }else{
    printf("Not found");
   }
}