#include<stdio.h>

int main()
{
    int A[10],item;
    for(int i=0;i<10;i++) {
        scanf("%d", &A[i]);
    }
    printf("Enter the value to be searched: ");
    scanf("%d",&item);
    for(int j=0;j<10;j++) {
        if(item == A[j]) {
            printf("The item is %d and the index is %d.",A[j],j);
            return 0;
        }
    }
    printf("The item is not found!!!");
    return 0;
}