#include <stdio.h>
int main()
{
    int num, balance = 2000, amount;
    printf("Menu:\n1.Check funds.\n2.Deposit Funds.\n3.Withdraw Funds\n4.Exit\nEnter number to continue: \n");
    scanf("%d", &num);
    if (num == 1){
        printf("Your current balance is $%d",balance);
    }else if (num == 2){
        printf("Enter amount to deposit:");
        scanf("%d",&amount);
        balance +=amount;
        printf("Amount deposited succesfully, Your balance is%d",balance);
    }else if (num == 3){
        printf("Enter amount to withdraw:");
        scanf("%d",&amount);
        if(amount>0 && amount<=balance){
        balance -=amount;
        printf("Amount withdrawn succesfully, Your balance is%d",balance);
        }else if(amount<0){
            printf("Invalid amount");
        }else{
            printf("Insufficient funds");
        }
    } else if(num == 4){
        printf("exiting program");
    

    }else{
        printf("invalid number entered");
    }    

}

