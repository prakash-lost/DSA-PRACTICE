#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *newnode,*temp;
//make the head
node *head = NULL;
void printmenu();
void printmenu()
{
     printf("\n Menu for operation:\n");
     printf("1. Insert at beginning\n");
     printf("2. Insert at end\n");
     printf("3. Insert at position\n");
     printf("4. Delete at beginning\n");
     printf("5. Delete at end\n");
     printf("6. Delete at user given position\n");
     printf("7. count the node\n");
     printf("8. display\n");
     printf("9. Exit\n");
}
//traverse the linked list
void display();
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
void insertAtBeginning(int data);
void insertAtBeginning(int data){
     newnode=(node*)malloc(sizeof(node));
     printf("enter the data to insert");
     scanf("%d",&newnode->data);
     newnode->next=head;
     head=newnode;
     void display();
}
void insertAtEnd(int data);
void insertAtEnd(int data){
     newnode=(node*)malloc(sizeof(node));
     printf("enter the data to insert");
     scanf("%d",&newnode->data);
     newnode->next=NULL;
     temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;
     }
     temp->next=newnode;
     void display();
}

void insertAtPosition(int);
void insertAtPosition(int data){
     int i=1,pos,count=0;
     newnode=(node*)malloc(sizeof(node));
     printf("enter the position");
     scanf("%d",&pos);
     temp=head;
     while (temp!=NULL) {
     temp=temp->next;
     count++;}
     if(pos>count)
     {
        printf("invalid position . cant find node on that position");
     }
     else
     {  temp=head; }
     while (i<pos)
     { temp=temp->next;
     i++; }
     printf("enter the data to enter in that node");
     scanf("%d",&newnode->data);
     newnode->next=temp->next;
     temp->next=newnode;
     void display();
}
void deleteAtBeginning();
void deleteAtBeginning(){
     if(head == NULL) {
        printf("EMPTY LINKED LIST\n");
        return; }
     temp=head;
     head=head->next;
     free(temp);
     void display();
}
void deleteAtEnd();
void deleteAtEnd()
{
     node *prevnode; // to make previous node the last node by using NULL
     if(head == NULL) {
        printf("EMPTY LINKED LIST\n");
        return;
     }
     temp = head;
     //traverse and finding the 2nd last node to break the last node
     while(temp->next!= NULL) {
     prevnode=temp;
        temp = temp->next;
     } if(temp==head)
     {head=NULL;
     } else {
     prevnode->next=NULL;
     }
     free(temp);
     void display();
}
void deleteAtPosition();
void deleteAtPosition()
{
     node *posnode;
     int pos,i=1;
     if(head == NULL){
        printf("EMPTY LINKED LIST\n");
        return;
     }
     temp=head;
     printf("enter the position ");
     scanf("%d",&pos);
     while(i<pos-1)
     {
        temp=temp->next;
        i++;
     }
     posnode=temp->next;
     temp->next=posnode->next;
     free(posnode);
     void display();
}
void count_node();
void count_node()
{
     int count=0;
     temp=head;
     while (temp!=NULL){
     temp=temp->next;
     count++;}
     printf("The total node are= %d",count);
}
int main(void)
{
    int choice,pos,count=0;
    int data;
    do{
        printmenu();
        printf("enter the choice to make\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertAtBeginning(data);
            break;
            case 2:
            insertAtPosition(data);
             break;
            case 3:
            insertAtEnd(data);
            break;
            case 4:
            deleteAtBeginning();
            break;
            case 5:
            deleteAtPosition();
            break;
            case 6:
            deleteAtEnd();
            break;            
            case 7:
            count_node();
            break;            
            case 8:
            display();
            break;    
            case 9:
            exit(1);
            break;    
        default:
            printf("invalid choice \n");
        }
    }while(choice!=9);
    return 0;
}



