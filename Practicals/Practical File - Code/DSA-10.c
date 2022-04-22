#include<stdio.h>
#include<stdlib.h>

struct LL {
  int data;
  struct LL *next;
};

typedef struct LL node;

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
    printf("\n1-Create a List");
    printf("\n------------------------");
    printf("\n2-Reverse a List");
    printf("\n3-Traverse the List from L to R");
    printf("\n------------------------");
    printf("\n4-Exit");
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

void reverse (){
    node *p, *q, *r;
 
    p = q = r = start;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    start = q;
}

void traverse(node *temp) {
    if(start==NULL) {printf("\nList is Empty!!!");}
    else {
        printf("\nContents of the list are(from L to R): ");
        while(temp!=NULL) {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("X");
    }
}

int main(void) {
   int ch,n;
   while(1) {
       ch=menu();
       switch(ch) {
           case 1: if(start==NULL) {
               printf("\nEnter the number of nodes you want: ");
               scanf("%d",&n);
               createLL(n);
               printf("\nList created!!!");
            }else {printf("List already exists!!!");}
                    break;
           case 2: reverse();
                    break;
           case 3: traverse(start);
                    break;
           case 4: printf("\nExit!!!");
                    exit(0);
           
       }
   }
   return 0;
}