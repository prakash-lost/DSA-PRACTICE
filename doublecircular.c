#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev; 
};

struct Node *head = NULL;
struct Node *temp;

void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition(int position);
void display();
void printMenu();

int main() {
    int choice, data, position;
     do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}

void printMenu() {
    printf("\n********** MENU **********\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at given position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from given position\n");
    printf("7. Display\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}
void insertAtBeginning(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
newNode->prev=NULL;
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    display();
}

void insertAtEnd(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
newNode->prev=NULL;
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    display();
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
    }
    display();
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
    }
    display();
}
void insertAtPosition(int data,int position){
if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
newNode->prev=NULL;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    if (position == 1) {
       insertAtBeginning();
    }

     temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count == position - 1) {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        
    }

    printf("Position out of range\n");
    free(newNode);
    display();
}
void deleteFromPosition(int data,int position){
 if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    struct Node* toDelete = NULL;

    if (position == 1) {
        toDelete = head;
        if (head->next == head) {
            head = NULL;
        } else {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        free(toDelete);
        return;
    }

     temp = head;
    int count = 1;

    while (count < position && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count == position) {
        toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next->prev = temp;
        free(toDelete);
        return;
    }

    printf("Position out of range\n");
    display();
}
