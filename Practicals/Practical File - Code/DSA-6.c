#include <stdio.h>

int main(void) {
	// your code goes here
	int m[5][10];
	for (int i=0;i<5;i++) {
	    printf("Enter the marks of ten students for Course %d: ",i+1);
	    for(int j=0;j<10;j++) {
	        scanf("%d",&m[i][j]);
	    }
	    printf("\n");
	}
	
	for (int i=0;i<5;i++) {
	    printf("Marks of ten students for Course %d:",i+1);
	    for(int j=0;j<10;j++) {
	        printf(" %d",m[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}

