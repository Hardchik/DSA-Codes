#include <stdio.h>

int main(void) {
	// your code goes here
	int n,sum=0;
	float mean=0,medn=0;
	scanf("%d",&n);
	int A[n];
	for (int i=0 ; i<n ; i++) {
	    scanf("%d",&A[i]);
	}
	
	for(int k=0 ; k<n ; k++) {
	    for(int j=0 ; j<n-k-1 ; j++) {
	        if(A[j+1]<A[j]) {
	            int temp=A[j];
	            A[j]=A[j+1];
	            A[j+1]=temp;
	        }
	    }
 	}
 	printf("Sorted Array:");
	for (int i=0 ; i<n ; i++) {
	    printf(" %d",A[i]);
	}
	
	for (int j=0 ; j<n ; j++) {
	    sum+=A[j];
	}

	mean=(float)sum/n;
	if(n%2==0) {
	    n/=2;
	    medn=(float)(A[n-1]+A[n])/2;
	}else {
	    n=(n/2);
	    medn=A[n];
	}
	printf("\nMean: %f\nMedian: %f",mean,medn);
	return 0;
}

