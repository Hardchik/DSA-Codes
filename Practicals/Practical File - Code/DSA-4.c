#include <stdio.h>

int main(void) {
	// your code goes here
	int A[10];
	printf("Enter the Array: ");
	for (int i = 0; i < 10; i++) {
	    scanf("%d",&A[i]);
	}
	for (int i = 0; i < 10; i++) {
	    for (int j = 0; j < 9-i; j++) {
	        if(A[j]>A[j+1]) {
	            int temp=A[j];
	            A[j]=A[j+1];
	            A[j+1]=temp;
	        }
	    }
	}
	printf("\nSorted Array:");
	for (int i = 0; i < 10; i++) {
	    printf(" %d",A[i]);
	}
	return 0;
}

