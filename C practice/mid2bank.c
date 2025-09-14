#include <stdio.h>
int main()
{
    int pin = 3142, inputpin,num1, accnum;
    float balance = 21900, amount, cbalance;
    printf("Enter Security PIN number: ");
    scanf("%d",&inputpin);
    if(pin == inputpin){
        printf("1.Check Balance.\n2.Transfer to another Bank.\n3.Change PIN.\n");
        printf("Enter number 1,2,3 to access the above options:");
        scanf("%d",&num1);
        if(num1 == 1){
            printf("your current balance is:$%.2f",balance);
        }else if(num1 == 2){
               while (1) {
                printf("Enter amount to be transferred: ");
                scanf("%f", &amount);
                
                if (amount > balance) {
                    printf("Amount exceeds the current balance.\n");
                    printf("Re-enter Security PIN number: ");
                    scanf("%d", &inputpin);
                    
                    if (inputpin != pin) {
                        printf("Incorrect PIN. Transfer failed.\n");
                        break;
                    } else {
                        printf("PIN verified. Please enter a valid transfer amount.\n");
                    }
                } else {
                    
                    balance -= amount;
                    printf("Amount transferred successfully.\n");
                    printf("Your current balance is: $%.2f\n", balance);
                    break;  
                }
            }

            
        }else if(num1 == 3){
            int oldpin, newpin;
            printf("Enter old Security number: ");
            scanf("%d", &oldpin);
            if(pin == oldpin){
                printf("Enter new security PIN:");
                scanf("%d",&newpin);
                pin = newpin;
                printf("PIN Change Successfully");
            }else{
                printf("Invalid Security PIN");
            }

        }else{
            printf("Invalid Option");
        }
    

    }
       
    else{
        printf("Invalid Pin\n.");

}
}