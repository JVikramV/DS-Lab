#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = *head;
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = new_node;
}

void printList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* ptr = *head1;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = head2;
    }
}

void sortList(struct Node* head) {
    if (head == NULL) return;

    struct Node* i = head;
    struct Node* j = NULL;
    int temp;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    printf("Enter elements for List 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&list1, data);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n);
    printf("Enter elements for List 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&list2, data);
    }

    printf("\nList 1 before sorting: ");
    printList(list1);

    printf("List 2 before sorting: ");
    printList(list2);

    concatenate(&list1, list2);
    printf("\nList 1 after concatenating with List 2: ");
    printList(list1);

    sortList(list1);
    printf("\nList 1 after sorting: ");
    printList(list1);

    reverseList(&list1);
    printf("\nList 1 after reversing: ");
    printList(list1);

    return 0;
}
