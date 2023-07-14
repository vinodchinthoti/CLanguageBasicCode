//circular buffer…
#include<stdio.h>
#include<stdlib.h>

int SIZE;

struct bufferElement
{
    struct bufferElement * right;
    int data;
    struct bufferElement * left;
};
typedef struct bufferElement node;
node * head = NULL;

node *createNode(int value);
int menu();
void intoBuffer();
void pushHead();
void popTail();
int countNodes();
void displayBuffer();
void FIFO();
void LIFO();
void bufferStatus();

int main ()
{
    int ch;
    printf("\n Welcome.\n This program helps to create and manipuiate circular buffer of fixed size.");
    printf("\n Enter the size of buffer: ");
    scanf("%d",&SIZE);
    do{
        ch = menu();
    }while(ch);
    printf("\n Terminating Buffer");
    return 0;

}

int menu()
{
    int ch;
    printf("\n 1. Write a buffer ");
    printf("\n 2. Display buffer ");
    printf("\n 3. Insert a values");
    printf("\n 4. Delete a values");
    printf("\n 5. Status of buffer");
    printf("\n 6. Exit");
    printf("\n\n Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: intoBuffer();
                 break;
        case 2: displayBuffer();
                 break;
        case 3: pushHead();
                 break;
        case 4: popTail();
                 break;         
        case 5: bufferStatus();
                 break;
        default: return 0;
    }
    return 1;
}

node *createNode(int value)
{
    node * newnode =(node *)malloc(sizeof(node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int countNodes()
{
    node * temp = head ;
    int ctr = 0;
    if( temp==NULL )
    {
     return 0 ;
    }
    /*else if(temp==head->left)
    {
        return 1;
    }*/
    else
    {
        do {
        
            temp=temp->right;
            ctr++;
            
        }while(temp!=head);
       // printf("\r\n node cnt = %d",ctr);
        return ctr;
    }
}

void intoBuffer()
{
    int len;
    //printf("\n\n IntoBuffer:");
    len=countNodes();
   // printf("\n\n len = %d:",len);
    if(SIZE>len)
        pushHead();
    else {
        printf("inside limiter");
        pushHead();
        popTail();
    }
}

void pushHead()
{
    int value;
    node * newnode;
    printf("Enter value");
    scanf("%d",&value );
    newnode=createNode(value);
    if(head==NULL)
    {
        head=newnode;
        newnode->left=head;
        newnode->right=head;
    }
    else{
        newnode->left=head;
        newnode->right=head->right;
        head->right=newnode;
        head->right->left=newnode;
        head=newnode;
    }
}

void popTail()
{
    int len = countNodes();
    node * temp = head;
    
    if(len==1)
    {
     free(temp);
    }
    else{
        printf("Entering pop");
        temp=head->right; 
        head->right=temp->right;

        free(temp);  
       // printf("head->right:%d",(head->right)->data) ;   
    }
}



void displayBuffer()
{
    node* temp = head;
    if(head == NULL)
       printf("\n The buffer is empty");
    else{
        printf("\n Buffer Elements :");
      //  printf("%d",temp->data);
        //temp = temp->left ;
       // while(temp!=head)
         do {
        
            temp=temp->right;
           // printf("\n temp->left:%d",temp->left);
            printf("\t %d",temp->data);
           // printf("\t temp->right:%d",temp->right);
            
        }while(temp!=head);
       // printf("\n\n head->left:%d",head->left);
       // printf("\thead:%d",head->data);
       // printf("head->right:%d",head->right);
    }
}

void bufferStatus()
{
    int len;
    len=countNodes();
    printf("\n Total Nodes: %d",SIZE);
    printf("\n Nodes Used: %d",len);
    printf("\n Empty Nodes: %d",(SIZE-len));
}
