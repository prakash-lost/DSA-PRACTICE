#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
node *newnode,*temp;
//make the head
node *head = NULL;
void insertATbeg(int);
void insertATposition(int,int);
void insertATend(int);
void deleteATbeg();
void deleteATposition();
void deleteATend();
void display();
void printmenu();

int main(void)
{
    int choice;
    int value;
    int position;
    do{
        printmenu();
        printf("enter the choice to make\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
         printf("enter the data to insert \n");
         scanf("%d",&value);
            insertATbeg(value);
            break;
            case 2:
         printf("enter the data to insert \n");
         scanf("%d",&value);
         printf("enter the position ");
         scanf("%d",&position);
            insertATposition(value,position);
             break;
            case 3:
         printf("enter the data to insert \n");
         scanf("%d",&value);
            insertATend(value);
            break;
            case 4:
            deleteATbeg();
            break;
            case 5:
            printf("enter the position\n");
            scanf("%d",&position);
            deleteATposition();
            break;
            case 6:
            deleteATend();
            break;            
            case 7:
            display();
            break;    
            case 8:
            exit(1);
            break;    
        default:
            printf("invalid choice \n");
        }
    }while(choice!=8);
    return 0;
}
void printmenu()
{
     printf("\n Menu for operation:\n");
     printf("1. Insert at beginning\n");
     printf("2. Insert at end\n");
     printf("3. Insert at position\n");
     printf("4. Delete at beginning\n");
     printf("5. Delete at end\n");
     printf("6. Delete at user given position\n");
     printf("7. display\n");
     printf("8. Exit\n");
}
void insertATbeg(int val)
{
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=newnode->prev=NULL;
    if(head=NULL)
    {
        head=newnode;
    } else {
    newnode->next=head;
    head->prev=newnode;
    head=newnode;    
    }
    void display();
}
void insertATend(int val)
{
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=newnode->prev=NULL;
    if(head=NULL)
    {
        head=newnode;
    }
    head=temp;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    void display();
}
void insertATposition(int position,int  val)
{
    int i=1;
    if(position>1){
        printf("invalid position");
    }
    else if (position==1){
        insertATbeg(val);
    }
    else{
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=val;
     newnode->next=newnode->prev=NULL;
       head=temp;
       while(i<position-1){
        temp=temp->next;
        i++;}
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
       }
       void display();
    }
void deleteATbeg()
{
    temp=head;
    if(head=NULL)
    {
        printf("This is empty linklist\n");
    }else {
        head->next=head;
        free(temp);
    }
    void display();
}
void deleteATend()
{ if(head == NULL){
        printf("EMPTY LIST\n");
        return;
    }
    //iterate to second last
    node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    //temp is the second last node
    node *last = temp->next;
    temp->next = NULL;
    free(last);
    void display();
}
void deleteATposition(int position){
    int i=1;
    head-temp;
    while(i<position){
        temp=temp->next;
        i++;
     }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    void display();
}
void display(){
     temp=head;
     if(head==NULL)
     {
        printf("empty linked list");
        exit(1);
     }
     else {
        while(temp!=NULL)
        printf("\t%d\t",temp->data);
        temp=temp->next;
     }
}