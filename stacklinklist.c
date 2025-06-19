#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}
struct node *top=NULL;
void push();
void pop();
void peek();
void display();
void main()
{
    int choice;
    do{
    printf("\n1.push operation\n");
    printf("\n2.pop operation\n");
    printf("\n3.peek operation\n");
    printf("\n4.display\n");
    printf("\n5. exit\n");
     printf("\nEnter your choice to make form 1 to 5\n");
    scanf("%d",&choice);
         switch(choice)
        {
        case 1:
          push();
        break;
        case 2:
          pop();
        break;
        case 3:
          peek();
          break;
        case 4:
          display();
        break;
        case 5:
          exit(1);
        break;
        default:
        printf("\nenter valid number \n");    
        }

    }while(choice!=5);
}
void push(){
    int x;
    printf("\n enter the data to enter\n");
    scanf("%d",&x);
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void pop(){
    struct node*temp=top;//temp is used to free the memory
    if(top==0){
        printf("\nunderflow\n");
    }
        else{
            printf("%d",top->data);
            top=top->next;//delete the top element
            free(temp);
        }}

void peek(){//to display the first element
   if(top==0){
    printf("\nunderflow or empty\n");
   }else{
    printf("top element : %d",top->data);
   }
}   
void display(){
    struct node*temp;
    temp=top;
    if(top==0){
        printf("\nunderflow or empty\n");
    }else{
        while(temp!=0)
        {
            printf("\n%d\n",temp->data);
            temp=temp->next;
        }
    }
}     

    