#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int count[100] = {0}; 
    for (int i = 0; i < n; i++) {
        printf("Element %d= ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 0; i < 100; i++) {
        if (count[i] > 1)
            printf("Number %d occurs more than once.\n", i);
    }
}
