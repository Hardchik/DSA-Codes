# include<stdio.h>  
# include<malloc.h>  
  
typedef struct node {  
    int priority;  
    int info;  
    struct node *link;  
}NODE;  
NODE *front = NULL;  
 
void insert(int data,int priority) {  
    NODE *temp,*q;  
    temp = (NODE *)malloc(sizeof(NODE));  
    temp->info = data;  
    temp->priority = priority;  
    if( front == NULL || priority < front->priority ) {  
        temp->link = front;  
        front = temp;  
    }else {  
        q = front;  
        while( q->link != NULL && q->link->priority <= priority)  
            q=q->link;  
        temp->link = q->link;  
        q->link = temp;  
    }  
}  

void del() {  
    NODE *temp;  
    if(front == NULL)  
        printf("UNDERFLOW!!!\n");  
    else {  
        temp = front;  
        printf("Deleted item is %d\n", temp->info);  
        front = front->link;  
        free(temp);  
    }  
}  

void display() {  
    NODE *ptr;  
    ptr = front;  
    if(front == NULL)  
        printf("Queue is empty!!!\n");  
    else {     
        printf("\nQueue is:");  
        //printf("Priority       Item\n");  
        while(ptr != NULL) {  
            //printf("%5d        %5d\n",ptr->priority,ptr->info);  
            printf(" %d ->",ptr->info);
            ptr = ptr->link;  
        }  
        printf(" X");
    }  
}  
 
int main(void) {  
    int choice, data, priority;  
    do {  
        printf("\n1.Insert");  
        printf("\n2.Delete");  
        printf("\n3.Display");  
        printf("\n4.Quit");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch(choice) {  
            case 1: printf("\nEnter the data which is to be added in the queue: ");  
                    scanf("%d",&data);  
                    printf("\nEnter its priority: ");  
                    scanf("%d",&priority);  
                    insert(data,priority);  
                    break;  
            case 2: del();  
                    break;  
            case 3: display();  
                    break;  
            case 4: break;  
            default :  printf("\nWrong choice!!!");  
        }  
    }while(choice!=4);  
    return 0;  
}  