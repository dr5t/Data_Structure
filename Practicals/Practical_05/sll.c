#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char usn[20], name[30], branch[10];
    int sem;
    long phno;
    struct Node *next;
};

struct Node *head = NULL;

// Create Node
struct Node* createNode() {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter USN, Name, Branch, Sem, Phone:\n");
    scanf("%s %s %s %d %ld", newnode->usn, newnode->name, newnode->branch, &newnode->sem, &newnode->phno);
    newnode->next = NULL;
    return newnode;
}

// Front Insertion
void insertFront() {
    struct Node *newnode = createNode();
    newnode->next = head;
    head = newnode;
}

// Display
void display() {
    struct Node *temp = head;
    int count = 0;
    if (temp == NULL) {
        printf("List Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%s %s %s %d %ld\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total Nodes = %d\n", count);
}

// Insert End
void insertEnd() {
    struct Node *newnode = createNode(), *temp = head;
    if (head == NULL) {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

// Delete Front
void deleteFront() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete End
void deleteEnd() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = head, *prev;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Insert at Position
void insertPos(int pos) {
    struct Node *newnode = createNode(), *temp = head;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete at Position
void deletePos(int pos) {
    struct Node *temp = head, *prev;
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Reverse List
void reverse() {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Main
int main() {
    int choice, pos;
    while (1) {
        printf("\n1.Insert Front\n2.Display\n3.Insert End\n4.Delete Front\n5.Delete End\n6.Insert Pos\n7.Delete Pos\n8.Reverse\n9.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFront(); break;
            case 2: display(); break;
            case 3: insertEnd(); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Enter position: "); scanf("%d", &pos); insertPos(pos); break;
            case 7: printf("Enter position: "); scanf("%d", &pos); deletePos(pos); break;
            case 8: reverse(); break;
            case 9: exit(0);
        }
    }
}