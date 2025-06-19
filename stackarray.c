/*complete menu driven program in c to array inmplementation of stack*/
#include<stdio.h>
#include<stdlib.h>

int stack[100],N;
int top = -1;
void push();
void pop();
void peek();//to see which element is in top or first in stack 
void display();
void main()
{
    int choice,N;
    printf("\n enter the number of elements in the stack \n");
    scanf("%d",&N);
    do{
    printf("\nfollowing are the operation that can be done\n");
    printf("\n1.push operation \n");
    printf("\n2.pop operstion\n");
    printf("\n3.peek operation\n");
    printf("\n4.display operation \n");
    printf("\n 5.exit \n");
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
    int x ;
    printf("enter the data ti enter in the stack ");
    scanf("%d",&x);
    if  ( top==N-1 ){
        printf("overflow in the stack\n");
    }
    else{
        top++;
        stack[top]=x;
    }}
void pop(){
    int detvalue;
    if(top==-1){
        printf("under flow in the stack \n");
        }else{
            detvalue=stack[top];
            top--;
            printf("deleted value is %d",detvalue);
        }}    
void peek(){
    if (top==-1){
        printf("under flow\n");
    }else{
        printf("first element is %d",stack[top]);
    }
}
void display(){
    int i ;
    if(top==-1){
        printf("empty stack\n");
     }else{
        for(i=top;i>0;i--);
        {
            printf("%d",stack[i]);
        }
     }
}