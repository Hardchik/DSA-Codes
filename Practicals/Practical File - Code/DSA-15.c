#include<stdio.h>
#define n 10
int main(void) {
    int queue[n],ch=1,front=0,rear=0,i,j=1,x=n;
    printf("MENU");
    printf("\n1-Insertion");
    printf("\n2-Deletion");
    printf("\n3-Display");
    printf("\n4-Exit");
    while(1) {
        printf("\nEnter the Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            if(rear==x) {
                printf("\nQueue is Full");
            }else {
                printf("\nEnter data: ");
                scanf("%d",&queue[rear++]);
            }
            break;
        case 2:
            if(front==rear) {
                printf("\nQueue is empty");
            }else {
                printf("\nDeletion executed!!!");
                front++;
                x++;
            }
            break;
        case 3:
            printf("\nQueue Elements are: ");
            if(front==rear) {
                printf("\nQueue is Empty");
            }else {
                for(i=front; i<rear; i++) {
                    printf(" %d ->",queue[i]);
                }
                printf(" X");
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Choice!!!");
            }
        }
    }
    return 0;
}