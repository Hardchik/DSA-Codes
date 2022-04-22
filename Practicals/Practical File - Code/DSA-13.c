#include <stdio.h>

int A[10],top=-1,n;

void push() {
    if(top==9) {
        printf("\nOVERFLOW!!!");
    }else {
        top++;
        printf("\nEnter the item to be pushed: ");
        scanf("%d",&A[top]);
    }
}	
    
void pop() {
    if(top==-1) {
        printf("\nUNDERFLOW!!!");
    }else {
        printf("\nPop successfull!!!");
        top--;
    }
}    

void display() {
    if(top==-1) {
        printf("\nUNDERFLOW!!!");
    }else {
        printf("\nStack:");
        for (int i = 0; i <= top; i++) {
            printf(" %d",A[i]);
        }
    }
}

int main(void) {
	// your code goes here
	int x=1,choice;
	printf("MENU\n1 - Push\n2 - Pop\n3 - Display\n4 - Exit");
	while(x) {
	    printf("\nEnter your choice: ");
	    scanf("%d",&choice);
	    if(choice==1) {push();}
	    else if(choice==2) {pop();}
	    else if(choice==3) {display();}
	    else if(choice==4) {x=0; printf("\nExiting...");}
	    else {printf("Enter a valid choice!!!");}
	}
	return 0;
}

