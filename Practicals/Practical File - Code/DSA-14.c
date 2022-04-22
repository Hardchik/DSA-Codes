#include<stdio.h>
#include<stdlib.h>

struct stack {
  int data;
  struct stack *next;
};

typedef struct stack node;

node *start=NULL;
node* getnode() {
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

int menu() {
    int ch;
    printf("\n1-Insertion (Push)");
    printf("\n------------------------");
    printf("\n2-Deletion (Pop)");
    printf("\n------------------------");
    printf("\n3-Traverse the List from L to R");
    printf("\n------------------------");
    printf("\n4-Count Nodes");
    printf("\n------------------------");
    printf("\n5-Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}

void createLL(int n) {
    node *temp, *newnode;
    for (int i = 0; i < n; i++) {
        newnode=getnode();
        if(start==NULL) {start=newnode;}
        else {
            temp=start;
            while(temp->next!=NULL) {temp=temp->next;}
            temp->next=newnode;
        }
    }
}

int countnode(node *ptr) {
    int ctr=0;
    while(ptr!=NULL) {
        ctr++;
        ptr=ptr->next;
    }
    return ctr;
}

void traverse() {
    node *temp;
    temp=start;
    if(start==NULL) {printf("\nList is Empty!!!");}
    else {
        printf("\nContents of the list are(from L to R): ");
        while(temp!=NULL) {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
    printf("X");
}

void push() {
    node *newnode,*temp;
    newnode=getnode();
    if(start==NULL) {start=newnode;}
    else {
        temp=start;
        while(temp->next!=NULL) {temp=temp->next;}
        temp->next=newnode;
    }
}

void pop() {
    node *temp, *prev;
    if(start==NULL) {
        printf("\nNo nodes exist!!!"); 
        return;
    }else {
        temp=start;
        prev=start;
        while(temp->next!=NULL) {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        printf("\nDeletion executed!!!");
    }
}

int main(void) {
   int ch,n;
   while(1) {
       ch=menu();
       switch(ch) {
           case 1: push();
                    break;
           case 2: pop();
                    break;
           case 3: traverse();
                    break;
           case 4: printf("\nNumber of nodes: %d",countnode(start));
                    break;
           case 5: printf("\nExit!!!");
                    exit(0);
           
       }
   }
   return 0;
}