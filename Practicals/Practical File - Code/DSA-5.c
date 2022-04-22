#include<stdio.h>  
void mergeSort(int[],int,int);  
void merge(int[],int,int,int);  
void main ()  
{  
    int a[5],b[5],c[10];//= {10, 9, 7, 101, 23, 44, 12, 78, 34, 23};  
    int i;  
    printf("Enter an Array 1: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d",&a[i]);
    }
    printf("\nEnter an Array 2: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d",&b[i]);
    }
    //Merging
    for (int i = 0; i < 10; i++) {
        if(i<=4) {c[i]=a[i];}
        else {
            int j=i-5;
            c[i]=b[j];
        }
    }
    
    printf("\nUnsorted Array:");
    for (int i = 0; i < 10; i++) {
        printf(" %d",c[i]);
    }
    
    mergeSort(c,0,9);  
    printf("\nSorted Array:");  
    for(i=0;i<10;i++)  
    {  
        printf(" %d",c[i]);  
    }  
      
}  
void mergeSort(int a[], int beg, int end)  
{  
    int mid;  
    if(beg<end)  
    {  
        mid = (beg+end)/2;  
        mergeSort(a,beg,mid);  
        mergeSort(a,mid+1,end);  
        merge(a,beg,mid,end);  
    }  
}  
void merge(int a[], int beg, int mid, int end)  
{  
    int i=beg,j=mid+1,k,index = beg;  
    int temp[10];  
    while(i<=mid && j<=end)  
    {  
        if(a[i]<a[j])  
        {  
            temp[index] = a[i];  
            i = i+1;  
        }  
        else   
        {  
            temp[index] = a[j];  
            j = j+1;   
        }  
        index++;  
    }  
    if(i>mid)  
    {  
        while(j<=end)  
        {  
            temp[index] = a[j];  
            index++;  
            j++;  
        }  
    }  
    else   
    {  
        while(i<=mid)  
        {  
            temp[index] = a[i];  
            index++;  
            i++;  
        }  
    }  
    k = beg;  
    while(k<index)  
    {  
        a[k]=temp[k];  
        k++;  
    }  
}  