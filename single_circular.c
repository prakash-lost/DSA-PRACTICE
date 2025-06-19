#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

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

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    newNode->next = head;

    if (head == NULL) {
        newNode->next = newNode;
    } else {
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
    }
    newNode->next=head;
    head = newNode;
    void display();
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;
    newNode->next = head;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
    }
    void display();
}

void insertAtPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
     newNode->next = temp->next;
    temp->next = newNode;
    void display();
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == head) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
    }
    void display();
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if (temp->next == head) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    void display();
}

void deleteFromPosition(int position) {
    if (head == NULL || position <= 0) {
        printf("List is empty or invalid position\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    int count = 1;

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    while (count < position && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < position) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    void display();
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}
