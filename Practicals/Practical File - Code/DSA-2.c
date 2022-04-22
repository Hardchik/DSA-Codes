#include <stdio.h>

void insert_elem(int A[],int n) {
    int ins_ind;
    scanf("%d",&ins_ind);
    for(int i=n-1;i>=ins_ind;i--) {
        A[i+1]=A[i];
    }
    scanf("%d",&A[ins_ind]);
    n++;
    printf("New Array:");
    for(int i=0;i<n;i++) {
        printf(" %d",A[i]);
    }
}

void delete_elem(int A[],int n) {
    int del;
    scanf("%d",&del);
    for(int i=del;i<n;i++) {
        A[i]=A[i+1];
    }
    n--;
    printf("New Array:");
    for(int i=0;i<n;i++) {
        printf(" %d",A[i]);
    }
}

int main(void) {
	// your code goes here
	int m,choice;
	scanf("%d",&m);
	int A[10];
	for(int i=0;i<10;i++) {
	    if(i<m) {scanf("%d",&A[i]);}
	    else if(i>=m) {A[i]=0;}
	}
	
//	for(int i=0;i<m;i++) {printf("%d",A[i]);}

    label:
	    printf("Choices:\n1 - Insertion\n2 - Deletion\n");
    	scanf("%d",&choice);
    	if(choice==1) {
    	    insert_elem(A,m);
    	}else if(choice==2) {
    	    delete_elem(A,m);
    	}else {
    	    printf("Enter a suitable choice");
    	    goto label;
    	}
	
	return 0;
}