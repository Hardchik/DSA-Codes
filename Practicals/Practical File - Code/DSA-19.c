#include <stdio.h>
#include <stdlib.h>

struct dlinklist {
    struct dlinklist *left;
    int data;
    struct dlinklist *right;
};

typedef struct dlinklist node;
node *start = NULL;

node* getnode() {
    node * newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode -> data);
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

int countnode(node *start) {
    if(start == NULL) {return 0;}
    else {return (1 + countnode(start -> right));}
}

int menu() {
    int ch;
    printf("\n 1.Create");
    printf("\n------------------------------");
    printf("\n 2.Insertion");
    printf("\n------------------------------");
    printf("\n 3.Deletion");
    printf("\n------------------------------");
    printf("\n 4.Traverse the list from Left to Right");
    printf("\n------------------------------");
    printf("\n 5.Count the Number of nodes in the list");
    printf("\n------------------------------");
    printf("\n 6.Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void createlist(int n) {
    int i;
    node *newnode;
    node *temp;
    for(i = 0; i < n; i++) {
        newnode = getnode();
        if(start == NULL){
            start = newnode;
        }else {
            temp = start;
            while(temp -> right)
                {temp = temp -> right;}
            temp -> right = newnode;
            newnode -> left = temp;
        }
    }
}

void ins(int item) {  
    node *ptr = (node *) malloc(sizeof(node));  
    node *temp;  
    if(ptr == NULL) {  
       printf("\nOVERFLOW");  
    }else {  
       
        ptr->data=item;  
        if(start == NULL) {  
           ptr->right = NULL;  
           ptr->left = NULL;  
           start = ptr;  
        }else {  
          temp = start;  
          while(temp->right!=NULL) {  
              temp = temp->right;  
          }  
          temp->right = ptr;  
          ptr ->left=temp;  
          ptr->right = NULL;  
        }  
    printf("\nNode Inserted!!!");  
    } 
}    

void del() {  
    node *ptr;  
    if(start == NULL) {  
        printf("\n UNDERFLOW\n");  
    }else if(start->right == NULL) {  
        start = NULL;   
        free(start);  
        printf("\nNode Deleted\n");  
    }else {  
        ptr = start;  
        start = start -> right;  
        start -> left = NULL;  
        free(ptr);  
        printf("\nNode Deleted\n");  
    }  
}  

void traverse() {
    node *temp;
    temp = start;
    printf("\n The contents of List: ");
    if(start == NULL )
        {printf("\n Empty List");}
    else {
        while(temp != NULL) {
        printf("%d <--> ", temp -> data);
        temp = temp -> right;
        }
        printf("X");
    }
}

int main(void) {
    int ch, n,prod;
    while(1) {
        ch = menu();
        switch(ch) {
            case 1: printf("\n Enter Number of nodes to create: ");
                    scanf("%d", &n);
                    createlist(n);
                    printf("\n List created..");
                    break;
            case 2: scanf("%d",&prod);
                    ins(prod);
                    break;
            case 3: del();
                    break;        
            case 4: traverse();
                    break;
            case 5: printf("\n Number of nodes: %d", countnode(start));
                    break;
            case 6: printf("\n Exit!!!");
                    exit(0);
        }
    }
    return 0;
}