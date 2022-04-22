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
    printf("\n2-Insert a node @ beginning");
    printf("\n3-Insert a node @ mid");
    printf("\n4-Insert a node @ end");
    printf("\n------------------------");
    printf("\n5-Delete a node @ beginning");
    printf("\n6-Delete a node @ mid");
    printf("\n7-Delete a node @ end");
    printf("\n------------------------");
    printf("\n8-Traverse the List from L to R");
    printf("\n9-Traverse the List from R to L");
    printf("\n------------------------");
    printf("\n10-Count Nodes");
    printf("\n11-Exit");
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

void rev_traverse(node *start) {
    if(start==NULL) {return;}
    else {
        rev_traverse(start->next);
        printf("%d-->",start->data);
    }
}

void ins_at_beg() {
    node *newnode;
    newnode=getnode();
    if(start==NULL) {start=newnode;}
    else {
        newnode->next=start;
        start=newnode;
    }
}

void ins_at_end() {
    node *newnode,*temp;
    newnode=getnode();
    if(start==NULL) {start=newnode;}
    else {
        temp=start;
        while(temp->next!=NULL) {temp=temp->next;}
        temp->next=newnode;
    }
}

void ins_at_mid() {
    node *newnode, *temp, *prev;
    int pos,nodectr,ctr=1;
    newnode=getnode();
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    nodectr=countnode(start);
    if(pos>1 && pos<nodectr) {
        temp=prev=start;
        while(ctr<pos) {
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
}

void del_at_beg() {
    node *temp;
    if(start==NULL) {
        printf("\nNo nodes exist!!!"); 
        return;
    }else {
        temp=start;
        start=temp->next;
        free(temp);
        printf("\nDeletion @ beginning executed!!!");
    }
}

void del_at_end() {
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
        printf("\nDeletion @ end executed!!!");
    }
}

void del_at_mid() {
    int ctr=1,pos,nodectr;
    node *temp,*prev;
    if(start=NULL) {
        printf("Empty List!!!");
        return;
    }else {
        printf("\nEnter the position of node to delete: ");
        scanf("%d",&pos);
        nodectr=countnode(start);
        if(pos>nodectr) {
            printf("This node doesn't exist!!!");
        }
        if(pos>1 && pos<nodectr) {
            temp=prev=start;
            while(ctr<pos) {
                prev=temp;
                temp=temp->next;
                ctr++;
            }
            prev->next=temp->next;
            free(temp);
            printf("\nNode deleted!!!");
        }else {printf("\nInvalid position!!!");}
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
           case 2: ins_at_beg();
                    break;
           case 3: ins_at_end();
                    break;            
           case 4: ins_at_end();
                    break;
           case 5: del_at_beg();
                    break;
           case 6: del_at_mid();
                    break;
           case 7: del_at_end();
                    break;
           case 8: traverse();
                    break;
           case 9: printf("\nTraversing from R to L: ");
                    rev_traverse(start);
                    break;
           case 10: printf("\nNumber of nodes: %d",countnode(start));
                    break;
           case 11: printf("\nExit!!!");
                    exit(0);
           
       }
   }
   return 0;
}